// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "PaperFlipbook.h"

#include "MashRunnerStatics.generated.h"

UCLASS(MinimalAPI)
class UMashRunnerStatics : public UBlueprintFunctionLibrary
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
	
	FORCEINLINE static UPaperFlipbook* GetRunnerIdlePaperFlipbook()
	{
		return LoadObject<UPaperFlipbook>(nullptr, TEXT("/Game/MashRunner/Art/Characters/PFB_Runner_Idle.PFB_Runner_Idle"));
	}
};
