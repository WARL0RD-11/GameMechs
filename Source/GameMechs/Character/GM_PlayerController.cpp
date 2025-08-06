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

	check(GameMappingContext);

	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem = ULocalPlayer::
		GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(GameMappingContext, 0);
	}
}


void AGM_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}