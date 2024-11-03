// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MRGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRaceStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWinnerAnnounced);

UCLASS()
class COBRACODEMASHRUNNER_API AMRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	FOnRaceStarted OnRaceStarted;
	FOnWinnerAnnounced OnWinnerAnnounced;
	
	void AnnounceWinner(int WinnerIndex);
	void RestartCurrentLevel();
	void StartRace();

protected:
	virtual void BeginPlay() override;

private:
	bool bRaceOver = false;
};
