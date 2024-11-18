// Copyright Anton Vasserman, All Rights Reserved.

#include "MRAIController.h"
#include "CobraCodeMashRunner/Characters/MRRunnerCharacter.h"

AMRAIController::AMRAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMRAIController::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMRAIController::SimulateInput, FMath::RandRange(MinInputDelay, MaxInputDelay));
}

void AMRAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PossessedCharacter = Cast<AMRRunnerCharacter>(InPawn);
}

void AMRAIController::SimulateInput()
{
	if (PossessedCharacter->CanRun())
	{
		bInputFlipFlop ? PossessedCharacter->PowerLeft() : PossessedCharacter->PowerRight();
		bInputFlipFlop = !bInputFlipFlop;
	}

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMRAIController::SimulateInput, FMath::RandRange(MinInputDelay, MaxInputDelay));
}
