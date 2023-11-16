// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayableCharacter.h"

AMyPlayableCharacter::AMyPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bIsJumping = false;
}

void AMyPlayableCharacter::Tick(float DeltaTime)
{
	if (bIsJumping)
	{
		Jump();
	}
}

void AMyPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveFoward", this, &AMyPlayableCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayableCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseMoveX", this, &AMyPlayableCharacter::MouseMoveX);
	PlayerInputComponent->BindAxis("MouseMoveY", this, &AMyPlayableCharacter::MouseMoveY);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayableCharacter::CheckJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPlayableCharacter::CheckJump);
}

void AMyPlayableCharacter::MoveFoward(float InputValue)
{
	FVector MoveFoward = GetActorForwardVector();
	AddMovementInput(MoveFoward, InputValue);
}

void AMyPlayableCharacter::MoveRight(float InputValue)
{
	FVector Moveright = GetActorRightVector();
	AddMovementInput(Moveright, InputValue);
}

void AMyPlayableCharacter::MouseMoveX(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void AMyPlayableCharacter::MouseMoveY(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void AMyPlayableCharacter::CheckJump()
{
	if (bIsJumping)
	{
		bIsJumping = false;
	}
	else
	{
		bIsJumping = true;
	}
}


