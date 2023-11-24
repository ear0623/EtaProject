// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UWidgetInterface.h"
#include "MyMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class ETAPROJECT_API UMyMainWidget : public UUserWidget, public IUWidgetInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta= (BindWidget))
	class UCanvasPanel* BackGround;

	UPROPERTY(meta =(BindWidget))
	class UVerticalBox* MenuBar;

	UPROPERTY(BlueprintReadWrite,meta=(BindWidget))
	class UTextBlock* TextStart;

	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	class UButton* StartButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextOption;

	UPROPERTY(BlueprintReadWrite,meta=(BindWidget))
	class UButton* Option;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextExit;

	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	class UButton* Exit;

	UFUNCTION(BlueprintCallable)
	virtual void FStartLevel()override;

	UFUNCTION(BlueprintCallable)
	virtual void FExit()override;
};
