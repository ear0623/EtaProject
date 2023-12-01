// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAICodeController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyEnermyCharacter.h"




AMyAICodeController::AMyAICodeController()
{
	AMyEnermyCharacter* MyEnermy = Cast<AMyEnermyCharacter>(this);
	FAIStimulus Mystimulus;
}

void AMyAICodeController::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("OnPossess"));
	this->RunBehaviorTree(BTAsset);
	AIPerceptioncompoenet->OnTargetPerceptionUpdated.AddDynamic(this,&AMyAICodeController::OnTargetPerceptionUpdated_Delegate);
}

void AMyAICodeController::OnTargetPerceptionUpdated_Delegate(AActor* Actor, FAIStimulus stimulus)
{
	Actor->ActorHasTag("Player");
	FTimerHandle TimerHandle;
	FTimerDynamicDelegate DynamicTimer;
	UObject* ObjectValue = nullptr;
	if (stimulus.WasSuccessfullySensed())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		StartEnermyTimer(true, Actor);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("AI"));
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle,DynamicTimer, 1.0f, false, 4.0f);
		StartEnermyTimer(false,ObjectValue);
	}

}

void AMyAICodeController::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AMyAICodeController::StartEnermyTimer(bool InValue, UObject* objectvalue)
{
	MyblackBoard->SetValueAsBool("HasLineOfSight", InValue);
	MyblackBoard->SetValueAsObject("EnermyActor",objectvalue);
}
