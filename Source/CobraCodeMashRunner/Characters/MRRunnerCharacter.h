// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "CobraCodeMashRunner/Core/GameModes/MRPhase.h"
#include "CobraCodeMashRunner/Core/Utility/MRStatics.h"
#include "MRRunnerCharacter.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRRunnerCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	AMRRunnerCharacter();
	
	virtual void BeginPlay() override;
	FORCEINLINE bool CanRun() const { return bCanRun; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsRunning() const { return GetVelocity().Length() > 0.0f; }
	void PowerLeft();
	void PowerRight();
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	float MaxSpeed = 1500.f;
	
private:
	bool bCanRun = false;
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
	UFUNCTION()
	void OnPhaseChanged(EMRPhase NewPhase);
};
