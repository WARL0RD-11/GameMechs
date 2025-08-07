// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AGM_PlayerCharacter::AGM_PlayerCharacter()
{

	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void AGM_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGM_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


