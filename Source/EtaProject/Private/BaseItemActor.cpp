// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItemActor.h"

// Sets default values
ABaseItemActor::ABaseItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FText ABaseItemActor::GetUseActionText_Implementation()
{
	return FText();
}

bool ABaseItemActor::GetIsActorUsable_Implementation()
{
	return false;
}

bool ABaseItemActor::BeginOutLineFocus_Implementation()
{
	return false;
}

bool ABaseItemActor::EndOtLineFocus_Implementation()
{
	return false;
}

bool ABaseItemActor::OnActorUse_Implementation(APlayerController* Controller)
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

