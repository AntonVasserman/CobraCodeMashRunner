// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "CobraCodeMashRunner/Core/Utility/MRInputStatics.h"
#include "GameFramework/PlayerController.h"
#include "MRPlayerController.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	enum class EInput
	{
		None	UMETA(DisplayName = "None"),
		Left	UMETA(DisplayName = "Left"),
		Right	UMETA(DisplayName = "Right"),
	};

	UPROPERTY()
	UInputMappingContext* DefaultMappingContext = UMRInputStatics::GetDefaultMappingContext();

	UPROPERTY()
	UInputAction* InputActionPowerLeft = UMRInputStatics::GetPowerLeftInputAction();

	UPROPERTY()
	UInputAction* InputActionPowerRight = UMRInputStatics::GetPowerRightInputAction();
	
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	void RequestInputActionPowerLeft();
	void RequestInputActionPowerRight();
	virtual void SetupInputComponent() override;

private:
	EInput LastInput = EInput::None;
	UPROPERTY()
	class AMRRunnerCharacter* PossessedCharacter = nullptr;
};
