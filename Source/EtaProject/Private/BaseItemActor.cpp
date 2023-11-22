// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItemActor.h"

// Sets default values
ABaseItemActor::ABaseItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FText ABaseItemActor::GetUseActionText_Implementtation()
{
	return FText();
}

bool ABaseItemActor::GetIsUseable_Implementtation()
{
	return false;
}

bool ABaseItemActor::BeginOutLineFocus_Implementtation()
{
	return false;
}

bool ABaseItemActor::EndOutLineFocus_Implementtation()
{
	return false;
}

bool ABaseItemActor::OnActorUsed_Implementtation(APlayerController* Controller)
{
	return false;
}

// Called when the game starts or when spawned
void ABaseItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseItemActor::GetLifeTimeRepLicatedProps(TArray<FLifetimeProperty>& outLifeTimeProps) const
{
}

bool ABaseItemActor::OnWasUsed()
{
	return false;
}

void ABaseItemActor::OnRep_WasUsed()
{
}

void ABaseItemActor::SetInteractText(FText text)
{
}

void ABaseItemActor::SetScreenPosition(FVector2D ScreenPosition)
{
}

