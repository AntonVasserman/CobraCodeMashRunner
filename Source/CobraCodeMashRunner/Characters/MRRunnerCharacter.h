// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"

#include "MRRunnerCharacter.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRRunnerCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMRRunnerCharacter();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	void PowerLeft();
	void PowerRight();
	virtual void Tick(float DeltaSeconds) override;

private:
	float MaxSpeed = 1500.f;
	float SpeedIncreasePerTab = 50.f;
	float SpeedDecreaseMultiplier = 250.f;

	void IncreaseSpeed();
};
