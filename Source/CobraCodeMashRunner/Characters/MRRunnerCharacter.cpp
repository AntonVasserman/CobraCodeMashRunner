// Copyright Anton Vasserman, All Rights Reserved.

#include "MRRunnerCharacter.h"

#include "CobraCodeMashRunner/Core/Utility/MRStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "CobraCodeMashRunner/Core/Controllers/MRAIController.h"
#include "CobraCodeMashRunner/Core/GameModes/GameStates/MRGameStateBase.h"
#include "Kismet/GameplayStatics.h"

AMRRunnerCharacter::AMRRunnerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Setup PaperFlipbookComponent
	GetSprite()->SetFlipbook(UMRStatics::GetRunnerIdlePaperFlipbook());
	GetSprite()->SetRelativeLocation(FVector(0.f, 0.f, 30.f));
	
	// Setup Character Movement Component
	GetCharacterMovement()->MaxWalkSpeed = 0.f;

	AIControllerClass = AMRAIController::StaticClass();
}

void AMRRunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GameStateRef = GetWorld()->GetGameState<AMRGameStateBase>();
	GameStateRef->OnPhaseChanged.AddDynamic(this, &AMRRunnerCharacter::OnPhaseChanged);
}

void AMRRunnerCharacter::PowerLeft()
{
	IncreaseSpeed(SpeedIncreasePerTab);
}

void AMRRunnerCharacter::PowerRight()
{
	IncreaseSpeed(SpeedIncreasePerTab);
}

void AMRRunnerCharacter::UpdateFlipbook()
{
	// TODO (Refactor): Change this to not run on every tick but only when speed actually changes
	GetSprite()->SetFlipbook(
		GetCharacterMovement()->Velocity.Length() > 0.f ?
			UMRStatics::GetRunnerRunPaperFlipbook() :
			UMRStatics::GetRunnerIdlePaperFlipbook());
	// TODO (Refactor): Change this to a bool for simpler checking
	if (GetSprite()->GetFlipbook() == UMRStatics::GetRunnerRunPaperFlipbook())
	{
		GetSprite()->SetPlayRate(GetCharacterMovement()->MaxWalkSpeed / MaxSpeed);
	}
	else
	{
		GetSprite()->SetPlayRate(1.f);
	}
}

void AMRRunnerCharacter::OnPhaseChanged(EMRPhase NewPhase)
{
	switch (NewPhase)
	{
	case EMRPhase::InProgress:
		bCanRun = true;
		break;
	case EMRPhase::Finished:
		bCanRun = false;
		break;
	default:
		break;
	}
}

void AMRRunnerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddMovementInput(FVector(1.f, 0.f, 0.f), 1.f);
	DecreaseSpeed(SpeedDecreaseMultiplier * DeltaSeconds);
	UpdateFlipbook();
	
	// TODO (Refactor): Change this to a bool for simpler checking
	if (GetSprite()->GetFlipbook() == UMRStatics::GetRunnerRunPaperFlipbook() &&
		(GetSprite()->GetPlaybackPositionInFrames() == 1 || GetSprite()->GetPlaybackPositionInFrames() == 5))
	{
		if (bPlayFootstepSound)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), FootstepsSoundCue);
			bPlayFootstepSound = false;
		}
	}
	else
	{
		bPlayFootstepSound = true;
	}
}

void AMRRunnerCharacter::DecreaseSpeed(float SpeedMultiplier)
{
	const float CurrentMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

	if (!CanRun())
	{
		SpeedMultiplier *= 10.f;
	}
	
	const float NewMaxWalkSpeed = CurrentMaxWalkSpeed - SpeedMultiplier * SpeedDecreaseCurve->GetFloatValue(CurrentMaxWalkSpeed);
	GetCharacterMovement()->MaxWalkSpeed = FMath::Max(NewMaxWalkSpeed, 0.f);
}

void AMRRunnerCharacter::IncreaseSpeed(float SpeedMultiplier)
{
	const float CurrentMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	const float NewMaxWalkSpeed = CurrentMaxWalkSpeed + SpeedMultiplier * SpeedIncreaseCurve->GetFloatValue(CurrentMaxWalkSpeed);
	GetCharacterMovement()->MaxWalkSpeed = FMath::Min(NewMaxWalkSpeed, MaxSpeed);
}
