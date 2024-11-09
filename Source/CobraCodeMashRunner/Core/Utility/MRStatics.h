// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "Sound/SoundCue.h"
#include "MRStatics.generated.h"

UCLASS(MinimalAPI)
class UMRStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	FORCEINLINE static USoundCue* GetFootstepsSoundCue()
	{
		return LoadObject<USoundCue>(nullptr, TEXT("/Game/MashRunner/Audio/Footsteps/A_Steps_Cue.A_Steps_Cue"));
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

	FORCEINLINE static UCurveFloat* GetSpeedDecreaseCurveFloat()
	{
		return LoadObject<UCurveFloat>(nullptr, TEXT("/Game/MashRunner/Characters/Curve_SpeedDecrease_Float.Curve_SpeedDecrease_Float"));
	}

	FORCEINLINE static UCurveFloat* GetSpeedIncreaseCurveFloat()
	{
		return LoadObject<UCurveFloat>(nullptr, TEXT("/Game/MashRunner/Characters/Curve_SpeedIncrease_Float.Curve_SpeedIncrease_Float"));
	}
};