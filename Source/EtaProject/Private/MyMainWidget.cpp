// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/VerticalBox.h"
#include "GameFramework/GameUserSettings.h"



void UMyMainWidget::FStartLevel()
{
	FString FindLevelName = TEXT("MyFindLevelName_") + FGuid::NewGuid().ToString();

	FName LevelName(*FindLevelName);

	UGameplayStatics::OpenLevel(GetWorld(),LevelName, true, FString("Optional"));

	//StartButton
}

void UMyMainWidget::FExit()
{
	APlayerController* MyPlayerController =UGameplayStatics::GetPlayerController(GetWorld(),0);

	UKismetSystemLibrary::QuitGame(GetWorld(),MyPlayerController, EQuitPreference::Quit, false);
}

void UMyMainWidget::FOptionOpen()
{
	if (MenuBar)
	{
		MenuBar->SetVisibility(ESlateVisibility::Hidden);
		OptionBar->SetVisibility(ESlateVisibility::Visible);
	}
	
}

void UMyMainWidget::FResolve01()
{
	FIntPoint Option01(640, 480);
	UGameUserSettings* gameUserSetting= UGameUserSettings::GetGameUserSettings();
	gameUserSetting->SetScreenResolution(Option01);
	gameUserSetting->SetFullscreenMode(EWindowMode::Windowed);
	gameUserSetting->ApplyResolutionSettings(true);	
}
void UMyMainWidget::FResolve02()
{
	FIntPoint Option02(1024, 768);
	UGameUserSettings* gameUserSetting = UGameUserSettings::GetGameUserSettings();
	gameUserSetting->SetScreenResolution(Option02);
	gameUserSetting->SetFullscreenMode(EWindowMode::Windowed);
	gameUserSetting->ApplyResolutionSettings(true);
}
void UMyMainWidget::FResolve03()
{
	FIntPoint Option03(1280, 960);
	UGameUserSettings* gameUserSetting = UGameUserSettings::GetGameUserSettings();
	gameUserSetting->SetScreenResolution(Option03);
	gameUserSetting->SetFullscreenMode(EWindowMode::Windowed);
	gameUserSetting->ApplyResolutionSettings(true);
}
void UMyMainWidget::Back()
{
	MenuBar->SetVisibility(ESlateVisibility::Visible);
	OptionBar->SetVisibility(ESlateVisibility::Hidden);
}
//12801024