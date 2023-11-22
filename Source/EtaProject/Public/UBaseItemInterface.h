// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Sound/SoundCue.h"
#include "Internationalization/StringTableRegistry.h"
#include "UBaseItemInterface.generated.h"




// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUBaseItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ETAPROJECT_API IUBaseItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category="Default")
	FText GetUseActionText();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	bool GetIsActorUsable();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent,Category="Default")
	bool BeginOutLineFocus();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category ="Default")
	bool EndOtLineFocus();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category ="Default")
	bool OnActorUse(APlayerController* controller);
};
