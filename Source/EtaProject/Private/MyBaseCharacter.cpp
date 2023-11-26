// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseCharacter.h"
#include <Engine/DamageEvents.h>
#include "Engine/World.h"


// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AActor::PrimaryActorTick.bCanEverTick = true;

	HP = DefaultHP;
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

float AMyBaseCharacter::MyTraceSingleByChannel()
{
	FHitResult MyHitResult;
	FVector StartLocation = WeaponStaticMesh->GetSocketLocation(FName("LineTraceStartPoint"));
	FVector EndLocation = WeaponStaticMesh->GetSocketLocation(FName("LineTraceEndPoint"));
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);
	TraceParams.AddIgnoredComponent(WeaponStaticMesh);

	ReturnLintrece = GetWorld()->LineTraceSingleByChannel(MyHitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("LinetraceOn"));
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1.0f, 0, 5.333);
	
	if (ReturnLintrece)
	{
		
		if (Doonce == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("True"));
			Doonce = true;
			//HitedActor(HitDamage, ReturnLintrece);
			MyHitResult.GetActor()->K2_DestroyActor();
			
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("DoOnceTrue"));
			return 0.0f;
		}
	}
	else
	{
		return 0.0f;
		
	}
	

	return 0.0f;
}

float AMyBaseCharacter::HitedActor(float Hitdamaged, bool Trace)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Parant"));
	return DefaultHP;
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
			
			if (AnimInstance != nullptr&&AttackAnimMontage !=nullptr)
			{
				AnimInstance->Montage_Play(AttackAnimMontage,1.0f, EMontagePlayReturnType::Duration,0.0f,true);
			
				

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









