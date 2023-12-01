// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "MyPlayableCharacter.generated.h"



class AMyPlayerController;
class AMybaseCharacter;
class UAnimInstance;
class UKismetSystemLibrary;
class UPlayMontageCallbackProxy;
class FOnMontageEndedMCDelegate;
class AMyEnermyCharacter;
class UDamageType;


// DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnMontageEndedMCDelegate, UanimMontage*, Montage, bool, bInterrupted);
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
	UPROPERTY(VisibleAnywhere,BluePrintreadOnly, Category = "Camera",meta=(AlowwPrivateAccess = "true"))
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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="State")
	float HP_Char=10;
	
	

public:
	AMyPlayableCharacter();

	void Tick(float DeltaTime) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//
	void MoveFoward(float InputValue);
	void MoveRight(float InputValue);
	void MouseMoveX(float InputValue);
	void MouseMoveY(float Inputvalue);
	void CheckJump();
	void AttackMotion();
	UPROPERTY(BlueprintReadOnly,Category="Move")
	bool bIsJumping;
	//
	//
	bool bIsAttack;
	virtual void AttackAction()override;
	//
	//
	UDamageType* MyDamageType = NewObject<UDamageType>();


	UFUNCTION(BlueprintCallable)
	virtual float HitLinetrace() override;
	virtual float HitedActor(float Hitdamaged, bool Trace, AActor* DamagedActor)override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;
	virtual void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* Instigatedby, AActor* DamagedCauser)override;
	//
	//
	UAnimInstance* AnimInstance;
	UPROPERTY(BlueprintReadWrite, Category = "AttackCombo")
	AttackCombo CurrentAttackCombo;
	UFUNCTION()
	void OnMontageEnded(UAnimMontage* Montage, bool Value);
	//
	//
	//AMyEnermyCharacter* MyEnermyCha= NewObject<AMyEnermyCharacter>();
	//TSharedPtr<AMyEnermyCharacter> MyEnermy;
	//AMyEnermyCharacter* Enermy = Cast<AMyEnermyCharacter>(ACharacter);

};
