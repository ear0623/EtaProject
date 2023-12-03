// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UObject/Object.h"
#include "MyMainWidget.h"
#include "MyPlayerController.h"
#include "IngameWidget.h"
#include "Blueprint/UserWidget.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

	AMyHUD();


protected:
	TSubclassOf<UMyMainWidget> MainWidget;
	TSubclassOf<UIngameWidget> IngameWidget;
	AMyPlayerController* MyplayerController;
	virtual void BeginPlay() override;

	UUserWidget* MyWidget;
	
};
