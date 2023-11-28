// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseCharacter.h"
#include "MyEnermyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyEnermyCharacter : public AMyBaseCharacter
{
	GENERATED_BODY()

public:

	AMyEnermyCharacter();
	virtual float HitedActor(float Hitdamaged, bool Trace, AActor* DamagedActor)override;
	virtual void Tick(float DeltaTime) override;
	
};
