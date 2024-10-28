// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"

#include "MRRunnerCharacter.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRRunnerCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMRRunnerCharacter();

	void PowerLeft();
	void PowerRight();
};
