// Copyright Anton Vasserman, All Rights Reserved.

#include "MRPlayerController.h"

#include "CobraCodeMashRunner/Characters/MRRunnerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AMRPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AMRPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PossessedCharacter = Cast<AMRRunnerCharacter>(InPawn);
}

void AMRPlayerController::RequestInputActionPowerLeft()
{
	if (PossessedCharacter->CanRun() && LastInput != EInput::Left)
	{
		PossessedCharacter->PowerLeft();
		LastInput = EInput::Left;
	}
}

void AMRPlayerController::RequestInputActionPowerRight()
{
	if (PossessedCharacter->CanRun() && LastInput != EInput::Right)
	{
		PossessedCharacter->PowerRight();
		LastInput = EInput::Right;
	}
}

void AMRPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(InputComponent);
		IsValid(EnhancedInputComp))
	{
		EnhancedInputComp->BindAction(InputActionPowerLeft, ETriggerEvent::Started, this, &AMRPlayerController::RequestInputActionPowerLeft);
		EnhancedInputComp->BindAction(InputActionPowerRight, ETriggerEvent::Started, this, &AMRPlayerController::RequestInputActionPowerRight);
	}
}
