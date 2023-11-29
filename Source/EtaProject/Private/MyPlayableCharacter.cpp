// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayableCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayMontageCallbackProxy.h"



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
	//AMyBaseCharacter::MyTraceSingleByChannel();
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
	//this->GetCharacterMovement()->MaxWalkSpeed = 600.0f;

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
	//Delay();
	
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
				PlayMontageCallBackProxy->OnBlendOut;
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

			HitedActor(HitDamage, ReturnLintrece, MyHitResult.GetActor());
			
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("DoOnceTrue"));
		}
	}
	else
	{

	}
	return 0.0f;
}

float AMyPlayableCharacter::HitedActor(float Hitdamaged, bool Trace, AActor* DamagedActor)
{

	Super::HitedActor(Hitdamaged, Trace, DamagedActor);
	if (DamagedActor&&Trace)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("NotHere"));
		FDamageEvent DamageEvent;
		DamagedActor->TakeDamage(Hitdamaged,DamageEvent, GetController(), DamagedActor);
	}
	//float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor * DamageCauser);
	return 0.0f;
}

void AMyPlayableCharacter::Delay()
{
	Doonce = false;
	bIsAttack = false;
	this->GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}





