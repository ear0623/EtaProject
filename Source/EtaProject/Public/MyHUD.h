// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UObject/Object.h"
#include "MyMainWidget.h"
#include "MyPlayerController.h"
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
	UPROPERTY(EditAnywhere, Category = "class Types")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "Runtime")
	class UMyMainWidget* MainWidget;


	virtual void BeginPlay() override;
	

	AMyPlayerController* MyplayerController;
	
};
