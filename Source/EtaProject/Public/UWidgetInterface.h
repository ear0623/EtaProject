 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Kismet/GameplayStatics.h"
#include "UWidgetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UUWidgetInterface : public UInterface
{
	GENERATED_BODY()


};

/**
 * 
 */
class ETAPROJECT_API IUWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual void FStartLevel();

	UFUNCTION(BlueprintCallable)
	virtual void FOptionOpen();

	UFUNCTION(BlueprintCallable)
	virtual void FExit();

	UFUNCTION(BlueprintCallable)
	virtual void FResolve01();

	UFUNCTION(BlueprintCallable)
	virtual void FResolve02();

	UFUNCTION(BlueprintCallable)
	virtual void FResolve03();
};
