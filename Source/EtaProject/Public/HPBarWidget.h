// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API UHPBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Main_Hpbar;

	UPROPERTY(BlueprintReadWrite ,meta = (BindWidget))
	class USizeBox* WidgetSize;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UProgressBar* HPBar;

	
};
