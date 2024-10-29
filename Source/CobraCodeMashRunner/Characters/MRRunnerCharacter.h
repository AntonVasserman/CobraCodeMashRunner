// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CobraCodeMashRunner/Core/Utility/MashRunnerStatics.h"

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

protected:
	enum class EInput
	{
		None	UMETA(DisplayName = "None"),
		Left	UMETA(DisplayName = "Left"),
		Right	UMETA(DisplayName = "Right"),
	};
	
private:
	float MaxSpeed = 1500.f;
	float SpeedIncreasePerTab = 50.f;
	float SpeedDecreaseMultiplier = 250.f;
	UPROPERTY()
	UCurveFloat* SpeedIncreaseCurve = UMashRunnerStatics::GetSpeedIncreaseCurveFloat();
	UPROPERTY()
	UCurveFloat* SpeedDecreaseCurve = UMashRunnerStatics::GetSpeedDecreaseCurveFloat();
	// TODO (Refactor): Move this to the PlayerController
	EInput LastInput = EInput::None;

	void IncreaseSpeed();
};
