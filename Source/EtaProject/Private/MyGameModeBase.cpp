// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyHUD.h"
#include "MyGameStateBase.h"

AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<AMyPlayerController>PlayerControllerClassFinder(TEXT("/Script/EtaProject.MyPlayerController"));
	PlayerControllerClass = PlayerControllerClassFinder.Class;

	ConstructorHelpers::FClassFinder<AMyHUD> HUDClassFinder(TEXT("/Script/EtaProject.MyHUD"));
	HUDClass = HUDClassFinder.Class;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MyContents/Eta/BP_CheckCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	ConstructorHelpers::FClassFinder<AMyGameStateBase>MyGameStateClass(TEXT("/Script/EtaProject.MyGameStateBase"));
	GameStateClass = MyGameStateClass.Class;
	
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("HereisGameModeBase"));

	
}
