// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "MRInputStatics.generated.h"

UCLASS(MinimalAPI)
class UMRInputStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	FORCEINLINE static UInputMappingContext* GetDefaultMappingContext()
	{
		return LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/MashRunner/Core/Inputs/IMC_DefaultMappingContext.IMC_DefaultMappingContext"));
	}
	
	FORCEINLINE static UInputAction* GetPowerLeftInputAction()
	{
		return LoadObject<UInputAction>(nullptr, TEXT("/Game/MashRunner/Core/Inputs/Actions/IA_PowerLeft.IA_PowerLeft"));
	}

	FORCEINLINE static UInputAction* GetPowerRightInputAction()
	{
		return LoadObject<UInputAction>(nullptr, TEXT("/Game/MashRunner/Core/Inputs/Actions/IA_PowerRight.IA_PowerRight"));
	}
};
