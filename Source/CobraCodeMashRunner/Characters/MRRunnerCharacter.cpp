// Copyright Anton Vasserman, All Rights Reserved.

#include "MRRunnerCharacter.h"

#include "PaperFlipbookComponent.h"
#include "CobraCodeMashRunner/Core/Utility/MashRunnerStatics.h"

AMRRunnerCharacter::AMRRunnerCharacter()
{
	// Setup PaperFlipbookComponent
	GetSprite()->SetFlipbook(UMashRunnerStatics::GetRunnerIdlePaperFlipbook());
	GetSprite()->SetRelativeLocation(FVector(0.f, 0.f, 30.f));
}

void AMRRunnerCharacter::PowerLeft()
{
	UE_LOG(LogTemp, Display, TEXT("AMRRunnerCharacter::PowerLeft()"));
}

void AMRRunnerCharacter::PowerRight()
{
	UE_LOG(LogTemp, Display, TEXT("AMRRunnerCharacter::PowerRight"));
}
