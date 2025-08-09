// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

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
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,
				10.f, FColor::Red, (TEXT("Hello"))
			);
			
		}*/

		GMInputComponent->BindAction(GMMoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		GMInputComponent->BindAction(GMLookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	}
}

void AGM_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementDirection = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MovementDirection.Y);
		ControlledPawn->AddMovementInput(RightDirection, MovementDirection.X);
	}
}

void AGM_PlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookDirection = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawm = GetPawn())
	{
		ControlledPawm->AddControllerPitchInput(LookDirection.Y);
		ControlledPawm->AddControllerYawInput(LookDirection.X);
	}
}
