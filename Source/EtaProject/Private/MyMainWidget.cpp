// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

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
