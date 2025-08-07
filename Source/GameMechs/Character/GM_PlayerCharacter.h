// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GM_PlayerCharacter.generated.h"

UCLASS()
class GAMEMECHS_API AGM_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGM_PlayerCharacter();
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere)
	TObjectPtr <class UCameraComponent> Camera;


};
