// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAICodeController.h"
#include "BehaviorTree/BehaviorTree.h"

AMyAICodeController::AMyAICodeController()
{
}

void AMyAICodeController::OnPossess(APawn* Pawn)
{
	this->RunBehaviorTree(BTAsset);
}
