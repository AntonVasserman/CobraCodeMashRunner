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
	IncreaseSpeed();
}

void AMRRunnerCharacter::PowerRight()
{
	IncreaseSpeed();
}

void AMRRunnerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddMovementInput(FVector(1.f, 0.f, 0.f), 1.f);

	GetCharacterMovement()->MaxWalkSpeed = FMath::Max(GetCharacterMovement()->MaxWalkSpeed - SpeedDecreaseMultiplier * DeltaSeconds, 0.f);
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
	GetCharacterMovement()->MaxWalkSpeed = FMath::Min(GetCharacterMovement()->MaxWalkSpeed + SpeedIncreasePerTab, MaxSpeed);
}
