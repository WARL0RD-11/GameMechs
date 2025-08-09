// Fill out your copyright notice in the Description page of Project Settings.


#include "GMAnimInstance.h"
#include "GM_PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGMAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	GMCharacter = Cast<AGM_PlayerCharacter>(TryGetPawnOwner());
}

void UGMAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (GMCharacter == nullptr)
	{
		GMCharacter = Cast<AGM_PlayerCharacter>(TryGetPawnOwner());
	}

	if (GMCharacter == nullptr) return;

	FVector Velocity = GMCharacter->GetVelocity();
	Velocity.Z = 0;
	Speed = Velocity.Size();
}
