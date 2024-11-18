// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "PaperZDAnimInstance.h"
#include "Sound/SoundCue.h"
#include "MRStatics.generated.h"

UCLASS(MinimalAPI)
class UMRStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	FORCEINLINE static FName GetCollisionProfileNameBlockAll() { return FName("BlockAll"); }

	FORCEINLINE static UPaperSprite* GetFieldStageSprite()
	{
		return LoadObject<UPaperSprite>(nullptr, TEXT("/Game/MashRunner/Art/Background/SPR_Field.SPR_Field"));
	}

	FORCEINLINE static UPaperSprite* GetGoalConnectedSprite()
	{
		return LoadObject<UPaperSprite>(nullptr, TEXT("/Game/MashRunner/Art/Goal/SPR_Goal_Connected.SPR_Goal_Connected"));
	}

	FORCEINLINE static UPaperSprite* GetGoalRippedSprite()
	{
		return LoadObject<UPaperSprite>(nullptr, TEXT("/Game/MashRunner/Art/Goal/SPR_Goal_Ripped.SPR_Goal_Ripped"));
	}
	
	FORCEINLINE static UPaperFlipbook* GetRunnerIdlePaperFlipbook()
	{
		return LoadObject<UPaperFlipbook>(nullptr, TEXT("/Game/MashRunner/Art/Characters/PFB_Runner_Idle.PFB_Runner_Idle"));
	}

	FORCEINLINE static UPaperFlipbook* GetRunnerRunPaperFlipbook()
	{
		return LoadObject<UPaperFlipbook>(nullptr, TEXT("/Game/MashRunner/Art/Characters/PFB_Runner_Run.PFB_Runner_Run"));
	}

	FORCEINLINE static TSubclassOf<UPaperZDAnimInstance> GetRunnerAnimationBlueprintClass()
	{
		return ConstructorHelpers::FClassFinder<UPaperZDAnimInstance>(TEXT("/Game/MashRunner/Characters/ABP_Runner_2D.ABP_Runner_2D_C")).Class;
	}

	FORCEINLINE static UCurveFloat* GetSpeedDecreaseCurveFloat()
	{
		return LoadObject<UCurveFloat>(nullptr, TEXT("/Game/MashRunner/Characters/Curve_SpeedDecrease_Float.Curve_SpeedDecrease_Float"));
	}

	FORCEINLINE static UCurveFloat* GetSpeedIncreaseCurveFloat()
	{
		return LoadObject<UCurveFloat>(nullptr, TEXT("/Game/MashRunner/Characters/Curve_SpeedIncrease_Float.Curve_SpeedIncrease_Float"));
	}
};
