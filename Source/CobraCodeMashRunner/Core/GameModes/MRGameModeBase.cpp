// Copyright Anton Vasserman, All Rights Reserved.

#include "MRGameModeBase.h"

#include "CobraCodeMashRunner/Core/Controllers/MRPlayerController.h"
#include "CobraCodeMashRunner/Goal/MRGoal.h"
#include "GameStates/MRGameStateBase.h"
#include "Kismet/GameplayStatics.h"

AMRGameModeBase::AMRGameModeBase()
{
	// Setting up everything but BPs
	GameStateClass = AMRGameStateBase::StaticClass();
	PlayerControllerClass = AMRPlayerController::StaticClass();
}

void AMRGameModeBase::OnRipped(int WinnerIndex)
{
	if (bRaceOver)
	{
		return;
	}

	bRaceOver = true;
	Cast<AMRGameStateBase>(GameState)->SetPhase(EMRPhase::Finished);
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMRGameModeBase::RestartCurrentLevel, 4.f);
}

void AMRGameModeBase::RestartCurrentLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UGameplayStatics::OpenLevel(GetWorld(), FName(CurrentLevelName));
}

void AMRGameModeBase::StartRace()
{
	Cast<AMRGameStateBase>(GameState)->SetPhase(EMRPhase::InProgress);
}

void AMRGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> GoalActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMRGoal::StaticClass(), GoalActors);

	for (AActor* GoalActor : GoalActors)
	{
		AMRGoal* Goal = Cast<AMRGoal>(GoalActor);
		Goal->OnRipped.AddDynamic(this, &AMRGameModeBase::OnRipped);
	}
	
	Cast<AMRGameStateBase>(GameState)->SetPhase(EMRPhase::Wait);
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMRGameModeBase::StartRace, 3.f);
}
