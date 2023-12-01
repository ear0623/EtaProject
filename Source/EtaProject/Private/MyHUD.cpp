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

	if (WidgetClass)
	{
		MainWidget = CreateWidget<UMyMainWidget>(GetWorld(), WidgetClass);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("WidgetClass-Invaild"));
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		
		}
		else
		{
		}
	}
	//create widget&make REF
		
	
}

