// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "MyPlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyPlayableCharacter : public AMyBaseCharacter
{
	GENERATED_BODY()
	


public:
	AMyPlayableCharacter();

	void Tick(float DeltaTime) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveFoward(float InputValue);
	void MoveRight(float InputValue);
	void MouseMoveX(float InputValue);
	void MouseMoveY(float Inputvalue);
	void CheckJump();
	bool bIsJumping;

	

};
