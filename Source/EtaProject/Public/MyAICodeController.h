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
	UFUNCTION(BlueprintCallable)
	virtual void OnPossess(APawn* MyPawn)override;
	UFUNCTION()
	void OnTargetPerceptionUpdated_Delegate(AActor* Actor,FAIStimulus stimulus);
	virtual void BeginPlay() override;

	//check
	class UAISenseConfig_Sight* Sight;
	//
	void StartEnermyTimer(bool Invalue, UObject* objectvalue);
	

protected:
	UBehaviorTree* BTAsset;
	UPROPERTY(VisibleAnywhere, Category="AI")
	//TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent = nullptr;
	//TObjectPtr<UBlackboardComponent> BlackboardComponent = nullptr;
	UBlackboardComponent* MyblackBoard = GetBlackboardComponent();
	UPROPERTY(VisibleAnywhere, Category = "AI")
	UAIPerceptionComponent* AIPerceptioncompoenet;
	

private:

	
};
