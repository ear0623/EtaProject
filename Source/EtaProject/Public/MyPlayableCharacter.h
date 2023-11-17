// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyPlayableCharacter : public AMyBaseCharacter
{
	GENERATED_BODY()
	
protected:
	
	UPROPERTY(BluePrintreadOnly, Category = "Camera")
	class USpringArmComponent* SpringArm;
	UPROPERTY(BluePrintreadOnly, Category = "Camera")
	class UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, Category ="Camera")
	float ArmLenthValue;
	
	
	

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
