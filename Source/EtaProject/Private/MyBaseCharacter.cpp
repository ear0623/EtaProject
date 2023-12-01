// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseCharacter.h"
#include <Engine/DamageEvents.h>
#include "Engine/World.h"


// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AActor::PrimaryActorTick.bCanEverTick = true;

	HitDamage = 10.0f;
	bIsAttacking = false;
	Doonce = false;
	ReturnLintrece = false;
	WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
	WeaponStaticMesh->SetupAttachment(GetMesh(), FName("RightHand_Weapons"));
	
}

// Called when the game starts or when spawned
void AMyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	
}


float AMyBaseCharacter::HitLinetrace()
{
	return 0.0f;
}

void AMyBaseCharacter::AttackAction()
{

}


// Called every frame
void AMyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAction("Attack", IE_Pressed,this,&AMyBaseCharacter::AttackAction);
}

float AMyBaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	return DamageAmount;
}

void AMyBaseCharacter::ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, AController* Instigatedby, AActor* DamagedCauser)
{
	Super::ReceiveAnyDamage(Damage,DamageType,Instigatedby, DamagedCauser);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("ReceiveAnyDamage_Base"));
}









