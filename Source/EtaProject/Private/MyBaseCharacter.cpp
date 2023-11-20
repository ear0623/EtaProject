// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseCharacter.h"
#include <Engine/DamageEvents.h>

// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AActor::PrimaryActorTick.bCanEverTick = true;

	HP = DefaultHP;
	bIsAttacking = false;
	WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
	WeaponStaticMesh->SetupAttachment(GetMesh(), FName("RightHand_Weapons"));
	
}

// Called when the game starts or when spawned
void AMyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();


}

void AMyBaseCharacter::SecondAttack()
{
	
}

void AMyBaseCharacter::AttackAction()
{
	
		if (bIsAttacking ==false)
		{
			bIsAttacking = true;
			UAnimInstance* AnimInstance;
			AnimInstance = GetMesh()->GetAnimInstance();
			
			if (AnimInstance != nullptr&&AtaackAnimMontage !=nullptr)
			{
				AnimInstance->Montage_Play(AtaackAnimMontage,1.0f, EMontagePlayReturnType::Duration,0.0f,true);
				//AnimInstance->Montage_JumpToSection(,AtaackAnimMontage);
				
				
				//AnimInstance->Montage_Stop(2.26f, AtaackAnimMontage);
				//printstring
				//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("montage_Play"));
			}
			else
			{

			}
			
			
		}
		else
		{

		}
		bIsAttacking = false;
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



	PlayerInputComponent->BindAction("Attack", IE_Pressed,this,&AMyBaseCharacter::AttackAction);


}

float AMyBaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DefaultHP -= DamageAmount;
	if (DefaultHP <= 0)
	{
		//setsimulatePhysics
	}
	return DamageAmount;
}









