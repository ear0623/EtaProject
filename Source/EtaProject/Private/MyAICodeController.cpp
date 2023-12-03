// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAICodeController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyEnermyCharacter.h"




AMyAICodeController::AMyAICodeController()
{
	MyAIPerceptionCompoenet = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPercetion"));
}

void AMyAICodeController::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
	this->RunBehaviorTree(BTAsset);
	//인식 업데이트
	if (MyAIPerceptionCompoenet)
	{
		MyAIPerceptionCompoenet->OnTargetPerceptionUpdated.AddDynamic(this, &AMyAICodeController::OnTargetPerceptionUpdated);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("OnPossess"));
	}
	else
	{

	}
	OnTargetPerceptionUpdated(MyPawn,Mystimulus);
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

void AMyAICodeController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("OnTargetPerceptionUpdate"));
}
