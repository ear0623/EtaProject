// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MiniMap.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API UMiniMap : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* BackGround;

	UPROPERTY(meta = (BindWidget))
	class UImage* MiniMap;
	
};
