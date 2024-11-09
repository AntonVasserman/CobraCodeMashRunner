// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CobraCodeMashRunner/Core/GameModes/MRPhase.h"
#include "CobraCodeMashRunner/Core/Utility/MRStatics.h"
#include "MRRunnerCharacter.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRRunnerCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMRRunnerCharacter();

	
	virtual void BeginPlay() override;
	FORCEINLINE bool CanRun() const { return bCanRun; }
	void PowerLeft();
	void PowerRight();
	virtual void Tick(float DeltaSeconds) override;

private:
	bool bPlayFootstepSound = true;
	bool bCanRun = false;
	float MaxSpeed = 1500.f;
	float SpeedIncreasePerTab = 50.f;
	float SpeedDecreaseMultiplier = 250.f;
	UPROPERTY()
	class AMRGameStateBase* GameStateRef = nullptr;
	UPROPERTY()
	UCurveFloat* SpeedIncreaseCurve = UMRStatics::GetSpeedIncreaseCurveFloat();
	UPROPERTY()
	UCurveFloat* SpeedDecreaseCurve = UMRStatics::GetSpeedDecreaseCurveFloat();
	UPROPERTY()
	USoundCue* FootstepsSoundCue = UMRStatics::GetFootstepsSoundCue();

	void DecreaseSpeed(float SpeedMultiplier);
	void IncreaseSpeed(float SpeedMultiplier);
	void UpdateFlipbook();
	UFUNCTION()
	void OnPhaseChanged(EMRPhase NewPhase);
};
