// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayableCharacter.h"


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
	if (!bIsAttack)
	{
		PlayerInputComponent->BindAxis("MoveFoward", this, &AMyPlayableCharacter::MoveFoward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayableCharacter::MoveRight);
		PlayerInputComponent->BindAxis("MouseMoveX", this, &AMyPlayableCharacter::MouseMoveX);
		PlayerInputComponent->BindAxis("MouseMoveY", this, &AMyPlayableCharacter::MouseMoveY);
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayableCharacter::CheckJump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPlayableCharacter::CheckJump);
		PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyPlayableCharacter::AttackMotion);
	}
	
}

void AMyPlayableCharacter::MoveFoward(float InputValue)
{
	if (InputValue != 0.0f)
	{
		FVector MoveFoward = GetActorForwardVector();
		AddMovementInput(MoveFoward, InputValue);
	}
	
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
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("AttackMotion"));
	AttackAction();
}

void AMyPlayableCharacter::AttackAction()
{
	Super::AttackAction();

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("AttackAction"));
	if (bIsAttack == false)
	{
		bIsAttack = true;
		UAnimInstance* AnimInstance;
		AnimInstance = GetMesh()->GetAnimInstance();

		if (AnimInstance != nullptr && AttackAnimMontage != nullptr)
		{
			AnimInstance->Montage_Play(AttackAnimMontage, 1.0f, EMontagePlayReturnType::Duration, 0.0f, true);

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
	bIsAttack = false;

}




