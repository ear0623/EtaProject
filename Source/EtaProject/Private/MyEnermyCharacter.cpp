// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnermyCharacter.h"

AMyEnermyCharacter::AMyEnermyCharacter()
{
	DefaultHP = 10;
}

float AMyEnermyCharacter::HitedActor(float Hitdamaged, bool Trace)
{
	Super::HitedActor(Hitdamaged,Trace);

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("HP0"));
	if (Trace == true)
	{
		DefaultHP -= Hitdamaged;
		if (DefaultHP < 0)
		{

			this->K2_DestroyActor();
		}

	}
	
	return DefaultHP;

}