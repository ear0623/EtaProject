// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "MyBaseCharacter.generated.h"


UENUM(BlueprintType)
enum class AttackCombo : uint8
{
	None UMETA(DisplayName = "NONE"),
	Attack01 UMETA(DisplayName = "Attack01"),
	Attack02 UMETA(Displayname = "Attack02"),
};



UCLASS()
class ETAPROJECT_API AMyBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="State")
	float DefaultHP = 10;

	UPROPERTY(EditAnywhere, Category = "State")
	float HitDamage = 10;

	UPROPERTY(editAnywhere,BlueprintReadWrite,Category="Animation")
	bool Doonce;

	UPROPERTY(VisibleAnywhere,Category="StaticMesh")
	class UStaticMeshComponent* WeaponStaticMesh;

	UPROPERTY(EditAnywhere, Category="Animation")
	class UAnimMontage* AttackAnimMontage;


	virtual float HitLinetrace();
	virtual void AttackAction();
	bool ReturnLintrece;

	bool bIsAttacking;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//
	//Damage
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const& DamageEvent,class AController* EventInstigator,AActor* DamageCauser);
	virtual void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* Instigatedby, AActor* DamagedCauser);


};
