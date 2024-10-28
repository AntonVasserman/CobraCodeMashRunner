// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "CobraCodeMashRunner/Core/Utility/MashRunnerStatics.h"
#include "MRPlayerController.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UInputMappingContext* DefaultMappingContext = UMashRunnerStatics::GetDefaultMappingContext();

	UPROPERTY()
	UInputAction* InputActionPowerLeft = UMashRunnerStatics::GetPowerLeftInputAction();

	UPROPERTY()
	UInputAction* InputActionPowerRight = UMashRunnerStatics::GetPowerRightInputAction();
	
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	void RequestInputActionPowerLeft();
	void RequestInputActionPowerRight();
	virtual void SetupInputComponent() override;

private:
	UPROPERTY()
	class AMRRunnerCharacter* PossessedCharacter = nullptr;
};
