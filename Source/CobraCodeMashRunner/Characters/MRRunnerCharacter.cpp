// Copyright Anton Vasserman, All Rights Reserved.

#include "MRRunnerCharacter.h"

#include "CobraCodeMashRunner/Core/Utility/MashRunnerStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"

AMRRunnerCharacter::AMRRunnerCharacter()
{
}

void AMRRunnerCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Setup PaperFlipbookComponent
	GetSprite()->SetFlipbook(UMashRunnerStatics::GetRunnerIdlePaperFlipbook());
	GetSprite()->SetRelativeLocation(FVector(0.f, 0.f, 30.f));

	// Setup Character Movement Component
	GetCharacterMovement()->MaxWalkSpeed = 0.f;
}

void AMRRunnerCharacter::PowerLeft()
{
	// TODO (Refactor): Move this to the PlayerController
	if (LastInput != EInput::Left)
	{
		IncreaseSpeed();
		LastInput = EInput::Left;
	}
}

void AMRRunnerCharacter::PowerRight()
{
	// TODO (Refactor): Move this to the PlayerController
	if (LastInput != EInput::Right)
	{
		IncreaseSpeed();
		LastInput = EInput::Right;
	}
}

void AMRRunnerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddMovementInput(FVector(1.f, 0.f, 0.f), 1.f);

	const float CurrentMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	const float NewMaxWalkSpeed = CurrentMaxWalkSpeed - SpeedDecreaseMultiplier * DeltaSeconds * SpeedDecreaseCurve->GetFloatValue(CurrentMaxWalkSpeed);
	GetCharacterMovement()->MaxWalkSpeed = FMath::Max(NewMaxWalkSpeed, 0.f);
	// TODO (Refactor): Change this to not run on every tick but only when speed actually changes
	GetSprite()->SetFlipbook(
		GetCharacterMovement()->Velocity.Length() > 0.f ?
			UMashRunnerStatics::GetRunnerRunPaperFlipbook() :
			UMashRunnerStatics::GetRunnerIdlePaperFlipbook());
	// TODO (Refactor): Change this to a bool for simpler checking
	if (GetSprite()->GetFlipbook() == UMashRunnerStatics::GetRunnerRunPaperFlipbook())
	{
		GetSprite()->SetPlayRate(GetCharacterMovement()->MaxWalkSpeed / MaxSpeed);
	}
	else
	{
		GetSprite()->SetPlayRate(1.f);
	}
}

void AMRRunnerCharacter::IncreaseSpeed()
{
	const float CurrentMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	const float NewMaxWalkSpeed = CurrentMaxWalkSpeed + SpeedIncreaseCurve->GetFloatValue(CurrentMaxWalkSpeed) * SpeedIncreasePerTab;
	GetCharacterMovement()->MaxWalkSpeed = FMath::Min(NewMaxWalkSpeed, MaxSpeed);
}
