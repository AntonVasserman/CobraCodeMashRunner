// Copyright Anton Vasserman, All Rights Reserved.

#include "MRField.h"
#include "PaperSpriteComponent.h"
#include "CobraCodeMashRunner/Core/Utility/MRStatics.h"
#include "Components/BoxComponent.h"

AMRField::AMRField()
{
	// Setup the Root Component
	RootSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootSceneComp;

	// Setup the Collision Boxes
	TopBoxComp = CreateDefaultSubobject<UBoxComponent>("Top Box");
	TopBoxComp->SetCollisionProfileName(UMRStatics::GetCollisionProfileNameBlockAll());
	TopBoxComp->SetupAttachment(RootComponent);
	BottomBoxComp = CreateDefaultSubobject<UBoxComponent>("Bottom Box");
	BottomBoxComp->SetCollisionProfileName(UMRStatics::GetCollisionProfileNameBlockAll());
	BottomBoxComp->SetupAttachment(RootComponent);

	// Setup the Goals
	TopGoal = CreateDefaultSubobject<UChildActorComponent>("Top Goal");
	TopGoal->SetChildActorClass(AMRGoal::StaticClass());
	TopGoal->SetupAttachment(RootComponent);
	BottomGoal = CreateDefaultSubobject<UChildActorComponent>("Bottom Goal");
	BottomGoal->SetChildActorClass(AMRGoal::StaticClass());
	BottomGoal->SetupAttachment(RootComponent);
}

void AMRField::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	for (UPaperSpriteComponent* SpriteComp : StageSpriteComps)
	{
		SpriteComp->DestroyComponent();
	}

	StageSpriteComps.Empty();

	// This creation and destruction of components is required in OnConstruction to enable the length control
	for (int i = 0; i < SpritesCount; i++)
	{
		StageSpriteComps.Add(NewObject<UPaperSpriteComponent>(this));
		StageSpriteComps[i]->SetupAttachment(RootSceneComp);
		StageSpriteComps[i]->SetSprite(UMRStatics::GetFieldStageSprite());
		StageSpriteComps[i]->SetRelativeLocation(FVector(Transform.GetLocation().X + SpriteLength * i, Transform.GetLocation().Y, Transform.GetLocation().Z));
		StageSpriteComps[i]->RegisterComponent();
	}

	const float BoxCompExtentX = SpriteLength / 2.f * SpritesCount; 
	BottomBoxComp->SetBoxExtent(FVector(BoxCompExtentX, 350.f, 10.f));
	TopBoxComp->SetBoxExtent(FVector(BoxCompExtentX, 350.f, 10.f));

	const float BoxCompRelativeOffsetX = SpriteLength * SpritesCount / 2.f - SpriteLength / 2.f;
	BottomBoxComp->SetRelativeLocation(FVector(Transform.GetLocation().X + BoxCompRelativeOffsetX, Transform.GetLocation().Y, Transform.GetLocation().Z - 380.f));
	TopBoxComp->SetRelativeLocation(FVector(Transform.GetLocation().X + BoxCompRelativeOffsetX, Transform.GetLocation().Y, Transform.GetLocation().Z - 60.f));

	const float GoalRelativeOffsetX = (SpritesCount - 1) * SpriteLength;
	BottomGoal->SetRelativeLocation(FVector(Transform.GetLocation().X + GoalRelativeOffsetX, Transform.GetLocation().Y + 100.f, Transform.GetLocation().Z - 270.f));
	TopGoal->SetRelativeLocation(FVector(Transform.GetLocation().X + GoalRelativeOffsetX, Transform.GetLocation().Y + 100.f, Transform.GetLocation().Z + 50.f));
}
