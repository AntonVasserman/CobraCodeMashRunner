// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EMRPhase : uint8
{
	None			UMETA(DisplayName = "None", Description = "Race hasn't started yet"),
	Wait			UMETA(DisplayName = "Wait", Description = "Waiting for race to start"),
	InProgress		UMETA(DisplayName = "InProgress", Description = "The race is in progress"),
	Finished		UMETA(DisplayName = "Finished", Description = "The winner was announced"),
};
