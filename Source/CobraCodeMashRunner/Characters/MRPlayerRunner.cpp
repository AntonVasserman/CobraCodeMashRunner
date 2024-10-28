// Copyright Anton Vasserman, All Rights Reserved.

#include "MRPlayerRunner.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMRPlayerRunner::AMRPlayerRunner()
{
	// Setup Spring Arm Component
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);

	// Setup Camera Component
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp);
}

void AMRPlayerRunner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SpringArmComp->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
}
