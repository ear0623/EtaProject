// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Perception/AIPerceptionTypes.h>
#include "MyAICodeController.generated.h"



class UBehaviorTree;
class UAIPerceptionComponent;
class UBlackboardComponent;
/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyAICodeController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAICodeController();
	UFUNCTION()
	virtual void OnPossess(APawn* MyPawn)override;
	virtual void BeginPlay() override;
	//timer
	void StartEnermyTimer(bool Invalue, UObject* objectvalue);
	//
	//component
	UAIPerceptionComponent* MyAIPerceptionCompoenet;
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	

protected:
	UBehaviorTree* BTAsset;
	UBlackboardComponent* MyblackBoard = GetBlackboardComponent();
	FAIStimulus Mystimulus;


private:

	
};
