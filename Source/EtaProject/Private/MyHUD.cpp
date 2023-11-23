// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "UObject/Object.h"
#include "Blueprint/UserWidget.h"



AMyHUD::AMyHUD()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainWidgetClass(TEXT("/Game/MyContents/Eta/WBP/WBP_MainSlots.WBP_MainSlots"));

	if (MainWidgetClass.Class != nullptr)
	{
		// Set the WidgetClass property with the found class
		WidgetClass = MainWidgetClass.Class;
	}
	MainWidget = nullptr;

}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass != nullptr)
	{
		MainWidget = CreateWidget<UMyMainWidget>(GetWorld(), WidgetClass);

		if (MainWidget != nullptr)
		{
			MainWidget->AddToViewport();
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("HudOn"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("HudOff"));
		}
	}
	//create widget&make REF
		
	
}

