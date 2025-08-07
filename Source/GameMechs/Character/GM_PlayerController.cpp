// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AGM_PlayerController::AGM_PlayerController()
{
	
}

void AGM_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* GMSubsystem = ULocalPlayer::
		GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (GMSubsystem)
	{
		GMSubsystem->AddMappingContext(GMMappingContext, 0);
	}
}

void AGM_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	GMInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	if (GMInputComponent)
	{    
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,
				10.f, FColor::Red, (TEXT("Hello"))
			);

		}
	}
}

void AGM_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementDirection = InputActionValue.Get<FVector2D>();
}
