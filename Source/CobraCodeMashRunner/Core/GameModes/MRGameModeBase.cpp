// Copyright Anton Vasserman, All Rights Reserved.

#include "MRGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void AMRGameModeBase::AnnounceWinner(int WinnerIndex)
{
	if (bRaceOver)
	{
		return;
	}

	bRaceOver = true;
	OnWinnerAnnounced.Broadcast();
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
	OnRaceStarted.Broadcast();
}

void AMRGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMRGameModeBase::StartRace, 3.f);
}
