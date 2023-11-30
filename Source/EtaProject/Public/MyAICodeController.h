// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAICodeController.generated.h"

class UBehaviorTree;
/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyAICodeController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAICodeController();
	virtual void OnPossess(APawn* Pawn)override;
	//void OnTargetPerceptionUpdated_Delegate(AActor* Actor,);

protected:
	UBehaviorTree* BTAsset;
	UPROPERTY(VisibleAnywhere, Category=AI)
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent = nullptr;
	

private:

	
};
