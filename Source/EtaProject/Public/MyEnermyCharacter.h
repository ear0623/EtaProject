// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "MyEnermyCharacter.generated.h"

class AActor;
/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyEnermyCharacter : public AMyBaseCharacter
{
	GENERATED_BODY()

public:

	AMyEnermyCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;
	virtual void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* Instigatedby, AActor* DamagedCauser)override;

	UFUNCTION(BlueprintCallable)
	virtual float HitLinetrace() override;

protected:
	
	AActor* Actor;

	
};
