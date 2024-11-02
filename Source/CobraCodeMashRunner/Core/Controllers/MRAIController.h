// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MRAIController.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMRAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	// Used to simulate the flip-flop logic of alternating between left and right input
	bool bInputFlipFlop = false;
	float MinInputDelay = 0.08f;
	float MaxInputDelay = 0.2f;

	UPROPERTY()
	class AMRRunnerCharacter* PossessedCharacter;

	// UFUNCTION()
	void SimulateInput();
};
