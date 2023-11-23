// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "MyPlayableCharacter.generated.h"

class AMyPlayerController;

/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyPlayableCharacter : public AMyBaseCharacter
{
	GENERATED_BODY()
	
protected:
	
	UPROPERTY(VisibleAnywhere,BluePrintreadOnly, Category = "Camera",meta=(AllowPrivateAccess ="true"))
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere,BluePrintreadOnly, Category = "Camera",meta=(AlowwPrivateAccess = "tue"))
	class UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, Category ="Camera")
	float ArmLenthValue;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Character")
	float BaseTurnRate;
	UPROPERTY()
	AMyPlayerController* MyPlayerCharacter;
	UPROPERTY(EditAnywhere,Category="MiniMap",meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* MinimapSpringArm;
	UPROPERTY(EditAnywhere, Category = "MiniMap", meta = (AlowwPrivateAccess = "tue"))
	class USceneCaptureComponent2D* Minimap;

	
	

public:
	AMyPlayableCharacter();

	void Tick(float DeltaTime) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveFoward(float InputValue);
	void MoveRight(float InputValue);
	void MouseMoveX(float InputValue);
	void MouseMoveY(float Inputvalue);
	void CheckJump();
	UPROPERTY(BlueprintReadOnly,Category="Move")
	bool bIsJumping;





};
