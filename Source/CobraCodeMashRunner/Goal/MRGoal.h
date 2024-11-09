// Copyright Anton Vasserman, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MRGoal.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRipped, int, LaneIndex);

UCLASS()
class COBRACODEMASHRUNNER_API AMRGoal : public AActor
{
	GENERATED_BODY()
	
public:
	FOnRipped OnRipped;
	
	AMRGoal();

protected:
	UPROPERTY(EditAnywhere, Category = "Config | Goal")
	int LaneIndex = 0;

	UPROPERTY(EditAnywhere, Category = "Config | Sprite")
	class UPaperSpriteComponent* PaperSpriteComp;
	
	UPROPERTY(EditAnywhere, Category = "Config | Goal")
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
