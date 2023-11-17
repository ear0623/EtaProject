// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseCharacter.h"
#include <Engine/DamageEvents.h>

// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AActor::PrimaryActorTick.bCanEverTick = true;

	HP = DefaultHP;

	
}

// Called when the game starts or when spawned
void AMyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMyBaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DefaultHP -= DamageAmount;
	if (DefaultHP <= 0)
	{
		//setsimulatePhysics
	}
	return DamageAmount;
}









