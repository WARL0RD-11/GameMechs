// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "GM_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMECHS_API AGM_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGM_PlayerController();
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> GameMappingContext;
};
