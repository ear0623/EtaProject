// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "UObject/Object.h"
#include "Blueprint/UserWidget.h"



AMyHUD::AMyHUD()
{
	//ConstructorHelpers::FClassFinder<UUserWidget> MainWidgetClass(TEXT("/Game/MyContents/Eta/WBP/WBP_MainSlots.WBP_MainSlots"));

}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(MainWidget))
	{
		MyWidget = CreateWidget(GetWorld(), MainWidget);
		MyWidget->AddToViewport();
	}
}

