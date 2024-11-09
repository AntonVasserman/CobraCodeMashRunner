// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CobraCodeMashRunner/Core/GameModes/MRPhase.h"
#include "GameFramework/GameStateBase.h"
#include "MRGameStateBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhaseChanged, EMRPhase, Phase);

UCLASS()
class COBRACODEMASHRUNNER_API AMRGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	FOnPhaseChanged OnPhaseChanged;
	
	FORCEINLINE EMRPhase GetPhase() const { return Phase; }

protected:
	virtual void SetPhase(EMRPhase NewPhase);

private:
	EMRPhase Phase = EMRPhase::None;

	friend class AMRGameModeBase;
};
