// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CobraCodeMashRunner/Goal/MRGoal.h"
#include "GameFramework/Actor.h"
#include "MRField.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRField : public AActor
{
	GENERATED_BODY()
	
public:	
	AMRField();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Sprites", meta = (ClampMin=1, ClampMax=10, UIMin=1, UIMax=10))
	int32 SpritesCount = 3;

	UPROPERTY(BlueprintReadWrite)
	float SpriteLength = 1920.f;

	UPROPERTY(VisibleAnywhere, Category = "Field")
	USceneComponent* RootSceneComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Field")
	UBoxComponent* BottomBoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Field")
	UBoxComponent* TopBoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Field")
	UChildActorComponent* BottomGoal;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Field")
	UChildActorComponent* TopGoal;
	
private:
	TArray<UPaperSpriteComponent*> StageSpriteComps;
};
