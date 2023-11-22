// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "Internationalization/StringTableRegistry.h"
#include "ABaseItemActor.generated.h"


UCLASS()
class ETAPROJECT_API ABaseItemActor : public AActor, public ABaseItemActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItemActor();

	//Interface begine
	virtual FText GetUseActionText_Implementtation()override;
	virtual bool GetIsUseable_Implementtation() override;
	virtual bool BeginOutLineFocus_Implementtation() override;
	virtual bool EndOutLineFocus_Implementtation() override;
	virtual bool OnActorUsed_Implementtation(APlayerController* Controller) override;
	//end

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(Replicated)
	FText Name;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Action;

	UPROPERTY(EditAnywhere,BlueprintReadwrite)
	USoundCue* UsedSound;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Replicated)
	bool IsUsable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,ReplicatedUsing="OnRep_WasUsed")
	bool WasUsed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifeTimeRepLicatedProps(TArray<FLifetimeProperty>& outLifeTimeProps) const override;

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnwasUsed"))
	virtual bool OnWasUsed();

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_WasUsed"))
	virtual void OnRep_WasUsed();

	UPROPERTY()
	UUserWidget* InteractUserWidget;

	UFUNCTION()
	void SetInteractText(FText text);

	UFUNCTION()
	void SetScreenPosition(FVector2D ScreenPosition);

};
