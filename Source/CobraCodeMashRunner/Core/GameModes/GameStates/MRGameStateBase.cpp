// Copyright Anton Vasserman, All Rights Reserved.

#include "MRGameStateBase.h"

void AMRGameStateBase::SetPhase(EMRPhase NewPhase)
{
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
}