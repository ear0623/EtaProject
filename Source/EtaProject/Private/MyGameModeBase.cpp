// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyHUD.h"

AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<AMyPlayerController>PlayerControllerClassFinder(TEXT("/Script/EtaProject.MyPlayerController"));
	PlayerControllerClass = PlayerControllerClassFinder.Class;

	ConstructorHelpers::FClassFinder<AMyHUD> HUDClassFinder(TEXT("/Script/EtaProject.MyHUD"));
	HUDClass = HUDClassFinder.Class;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/CoreUObject.Class"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
}
