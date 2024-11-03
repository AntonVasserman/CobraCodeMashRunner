// Copyright Anton Vasserman, All Rights Reserved.

#include "MRGoal.h"

#include "PaperSpriteComponent.h"
#include "CobraCodeMashRunner/Characters/MRRunnerCharacter.h"
#include "CobraCodeMashRunner/Core/GameModes/MRGameModeBase.h"
#include "CobraCodeMashRunner/Core/Utility/MashRunnerStatics.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AMRGoal::AMRGoal()
{
	PrimaryActorTick.bCanEverTick = true;

	// Setup Paper Sprite Component
	PaperSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Paper Sprite Component"));
	PaperSpriteComp->SetupAttachment(RootComponent);
	PaperSpriteComp->SetSprite(UMashRunnerStatics::GetGoalConnectedSprite());

	// Setup Box Collision Component
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComp->SetupAttachment(PaperSpriteComp);
	BoxComp->SetBoxExtent(FVector(10.f, 300.f, 50.f));
}

void AMRGoal::BeginPlay()
{
	Super::BeginPlay();

	GameModeRef = Cast<AMRGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AMRGoal::OnComponentBeginOverlap);
}

void AMRGoal::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bRipped)
	{
		if (AMRRunnerCharacter* RunnerCharacter = Cast<AMRRunnerCharacter>(OtherActor);
			IsValid(RunnerCharacter))
		{
			PaperSpriteComp->SetSprite(UMashRunnerStatics::GetGoalRippedSprite());
			bRipped = true;
			GameModeRef->AnnounceWinner(LaneNumber);
		}
	}
}
