// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnermyCharacter.h"
#include "MyAICodeController.h"

AMyEnermyCharacter::AMyEnermyCharacter()
{
	DefaultHP = 10;
	AIControllerClass = AMyAICodeController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}


void AMyEnermyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

float AMyEnermyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	return 0.0f;
}

void AMyEnermyCharacter::ReceiveAnyDamage(float Damage, const UDamageType* DamageType, AController* Instigatedby, AActor* DamagedCauser)
{
	Super::ReceiveAnyDamage(Damage, DamageType, Instigatedby, DamagedCauser);

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("ReceiveAnyDamage_Enermy"));
	
	if (DefaultHP > 0)
	{
		DefaultHP -= Damage;
	}
	else
	{
		this->K2_DestroyActor();
	}

}


