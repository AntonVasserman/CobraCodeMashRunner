// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MRGoal.generated.h"

UCLASS()
class COBRACODEMASHRUNNER_API AMRGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	AMRGoal();

protected:
	UPROPERTY(EditAnywhere)
	int LaneNumber = 0;

	UPROPERTY(EditAnywhere)
	class UPaperSpriteComponent* PaperSpriteComp;
	
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComp;

	virtual void BeginPlay() override;

private:
	bool bRipped = false;

	UPROPERTY()
	class AMRGameModeBase* GameModeRef = nullptr;
	
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
