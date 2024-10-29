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

	if (GetCharacterMovement()->MaxWalkSpeed > 0.f)
	{
		GetCharacterMovement()->MaxWalkSpeed -= SpeedDecreaseMultiplier * DeltaSeconds;
	}
}

void AMRRunnerCharacter::IncreaseSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed += SpeedIncreasePerTab;
}
