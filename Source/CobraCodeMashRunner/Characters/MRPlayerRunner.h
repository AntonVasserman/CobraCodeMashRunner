// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MRRunnerCharacter.h"
#include "MRPlayerRunner.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRPlayerRunner : public AMRRunnerCharacter
{
	GENERATED_BODY()

public:
	AMRPlayerRunner();

protected:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmComp = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComp = nullptr;
};
