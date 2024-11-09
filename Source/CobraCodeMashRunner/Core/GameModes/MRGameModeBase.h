// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MRGameModeBase.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMRGameModeBase();

protected:
	virtual void BeginPlay() override;

private:
	bool bRaceOver = false;

	UFUNCTION()
	void OnRipped(int WinnerIndex);
	void RestartCurrentLevel();
	void StartRace();
};
