// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UWidgetInterface.h"
#include "MyMainWidget.generated.h"

class ULevelStreaming;

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

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* OptionBar;

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

	UPROPERTY(BlueprintReadWrite,meta =(BindWidget))
	class UTextBlock* OptionBarText01;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* OptionBarText02;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* OptionBarText03;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* BackText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Option01_Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Option02_Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Option03_Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Back_Button;

	UFUNCTION(BlueprintCallable)
	virtual void FStartLevel()override;

	UFUNCTION(BlueprintCallable)
	virtual void FExit()override;

	UFUNCTION(BlueprintCallable)
	virtual void FOptionOpen()override;

	UFUNCTION(BlueprintCallable)
	virtual void FResolve01()override;

	UFUNCTION(BlueprintCallable)
	virtual void FResolve02()override;

	UFUNCTION(BlueprintCallable)
	virtual void FResolve03()override;

	UFUNCTION(BlueprintCallable)
	virtual void Back()override;

	//Level
};
