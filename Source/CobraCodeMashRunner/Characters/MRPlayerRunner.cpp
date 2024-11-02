// Copyright Anton Vasserman, All Rights Reserved.

#include "MRPlayerRunner.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMRPlayerRunner::AMRPlayerRunner()
{
	// Setup Spring Arm Component
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->SetRelativeLocation(FVector(350.f, 0.f, -100.f));
	SpringArmComp->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	SpringArmComp->TargetArmLength = 600.f;
	SpringArmComp->bDoCollisionTest = false;

	// Setup Camera Component
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->PostProcessSettings.bOverride_AutoExposureMethod = true;
	CameraComp->PostProcessSettings.AutoExposureMethod = AEM_Manual;
	CameraComp->PostProcessSettings.bOverride_AutoExposureBias = true;
	CameraComp->PostProcessSettings.AutoExposureBias = 10.2f;
}
