// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnermyCharacter.h"
#include "MyAICodeController.h"
#include "GameFramework/Actor.h"
#include "Engine/DamageEvents.h"
#include "MyPlayableCharacter.h"


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
	if (DamageCauser)
	{
		AMyPlayableCharacter* Player = Cast<AMyPlayableCharacter>(DamageCauser);
		UDamageType* MyDamageType = NewObject<UDamageType>();

		if (Player && MyDamageType)
		{
			Player->ReceiveAnyDamage(DamageAmount, MyDamageType, EventInstigator, DamageCauser);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("DamageCauser_True"));
			if (MyDamageType)
			{
				MyDamageType->ConditionalBeginDestroy();
				MyDamageType = nullptr;
			}
		}

	}
	else
	{

	}
	//ReceiveAnyDamage(DamageAmount,MyDamageType, EventInstigator, DamageCauser);
	return DamageAmount;
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

float AMyEnermyCharacter::HitLinetrace()
{
	FHitResult MyHitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);
	//FCollisionShape
	
	//FVector EndLocation = Actor->GetActorLocation() + (Actor->GetActorForwardVector()*100);
	//ReturnLintrece = GetWorld()->SweepSingleByChannel(MyHitResult, Actor->GetActorLocation(), EndLocation, ,ECC_Visibility, FCollisionShape::,TraceParams);
	//DrawDebugLine(GetWorld(), Actor->GetActorLocation(), EndLocation, FColor::Red, false, 1.0f, 0, 5.333);

	if (ReturnLintrece)
	{

		if (Doonce == false)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("True"));
			Doonce = true;
			FDamageEvent DamageEvent;
			TakeDamage(HitDamage, DamageEvent, GetController(), MyHitResult.GetActor());
		}
		else
		{

		}
	}
	else
	{

	}
	return 0.0f;
}


