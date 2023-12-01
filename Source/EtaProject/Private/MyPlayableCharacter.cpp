// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayableCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyEnermyCharacter.h"
#include "GameFramework/DamageType.h"
#include "UObject/ObjectMacros.h"




AMyPlayableCharacter::AMyPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bIsJumping = false;
	bIsAttack = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeLocation(FVector(0.0f,0.0f,50.0f));

	MinimapSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MiniMapSpringArm"));
	MinimapSpringArm->SetupAttachment(GetRootComponent());
	Minimap = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("ScenComponent2D"));
	Minimap->SetupAttachment(MinimapSpringArm);


	CurrentAttackCombo = AttackCombo::None;

}

void AMyPlayableCharacter::Tick(float DeltaTime)
{
	if (bIsJumping)
	{
		Jump();
		AddMovementInput(FVector(0, 0, 0), 0);
	}
}

void AMyPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveFoward", this, &AMyPlayableCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayableCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseMoveX", this, &AMyPlayableCharacter::MouseMoveX);
	PlayerInputComponent->BindAxis("MouseMoveY", this, &AMyPlayableCharacter::MouseMoveY);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayableCharacter::CheckJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPlayableCharacter::CheckJump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyPlayableCharacter::AttackMotion);
}

void AMyPlayableCharacter::MoveFoward(float InputValue)
{
	FVector MoveFoward = GetActorForwardVector();
	AddMovementInput(MoveFoward, InputValue);
}
void AMyPlayableCharacter::MoveRight(float InputValue)
{
	FVector Moveright = GetActorRightVector();
	AddMovementInput(Moveright, InputValue);
}

void AMyPlayableCharacter::MouseMoveX(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void AMyPlayableCharacter::MouseMoveY(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void AMyPlayableCharacter::CheckJump()
{
	if (bIsJumping)
	{
		bIsJumping = false;
	}
	else
	{
		bIsJumping = true;
	}
}

void AMyPlayableCharacter::AttackMotion()
{
	AttackAction();
}

void AMyPlayableCharacter::AttackAction()
{
	Super::AttackAction();
	
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("AttackAction"));
	if (bIsAttack == false)
	{
		AnimInstance = GetMesh()->GetAnimInstance();
		
		if (AnimInstance != nullptr && AttackAnimMontage != nullptr&&Doonce==false&&bIsAttack==false)
		{
			bIsAttack = true;
			switch (CurrentAttackCombo)
			{
			case AttackCombo::None:
				AnimInstance->Montage_Play(AttackAnimMontage, 1.0f, EMontagePlayReturnType::Duration, 0.0f, true);
				CurrentAttackCombo = AttackCombo::Attack01;
				this->GetCharacterMovement()->MaxWalkSpeed = 0.0f;
				break;

			case AttackCombo::Attack01:
				AnimInstance->Montage_Play(AttackAnimMontage, 1.0f, EMontagePlayReturnType::Duration, 1.6f, true);
				CurrentAttackCombo = AttackCombo::Attack02;
				this->GetCharacterMovement()->MaxWalkSpeed = 0.0f;
				break;

			case AttackCombo::Attack02:
				AnimInstance->Montage_Play(AttackAnimMontage, 1.0f, EMontagePlayReturnType::Duration, 2.9f, true);
				CurrentAttackCombo = AttackCombo::None;
				this->GetCharacterMovement()->MaxWalkSpeed = 0.0f;
				break;

			default:
				break;
			}
			AnimInstance->OnMontageEnded.AddDynamic(this, &AMyPlayableCharacter::OnMontageEnded);
			//printstring
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT(""));
		}
		else
		{

		}
		
	}
	else
	{

	}
}

float AMyPlayableCharacter::HitLinetrace()
{
	Super::HitLinetrace();

	FHitResult MyHitResult;
	FVector StartLocation = WeaponStaticMesh->GetSocketLocation(FName("LineTraceStartPoint"));
	FVector EndLocation = WeaponStaticMesh->GetSocketLocation(FName("LineTraceEndPoint"));
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);
	TraceParams.AddIgnoredComponent(WeaponStaticMesh);

	ReturnLintrece = GetWorld()->LineTraceSingleByChannel(MyHitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1.0f, 0, 5.333);

	if (ReturnLintrece)
	{

		if (Doonce == false)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("True"));
			Doonce = true;
			FDamageEvent DamageEvent;
			TakeDamage(HitDamage, DamageEvent, GetController(), MyHitResult.GetActor());
		}
		else
		{
		
		}
	}
	else
	{

	}
	return 0.0f;
}

float AMyPlayableCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (DamageCauser)
	{
		AMyEnermyCharacter* MyEnermy = Cast<AMyEnermyCharacter>(DamageCauser);
		if (MyEnermy&&MyDamageType)
		{
			MyEnermy->ReceiveAnyDamage(DamageAmount, MyDamageType, EventInstigator, DamageCauser);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("DamageCauser_True"));
		}
		
	}
	else
	{
		
	}
	//ReceiveAnyDamage(DamageAmount,MyDamageType, EventInstigator, DamageCauser);
	return DamageAmount;
}

void AMyPlayableCharacter::ReceiveAnyDamage(float Damage, const UDamageType* DamageType, AController* Instigatedby, AActor* DamagedCauser)
{
	Super::ReceiveAnyDamage(Damage, DamageType, Instigatedby, DamagedCauser);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("ReceiveDamage_Player"));
}

void AMyPlayableCharacter::OnMontageEnded(UAnimMontage* Montage, bool Value)
{
	
	Doonce = Value;
	bIsAttack = Value;
	this->GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	if (!Doonce)
	{
		AnimInstance->OnMontageEnded.RemoveDynamic(this, &AMyPlayableCharacter::OnMontageEnded);
	}
}







