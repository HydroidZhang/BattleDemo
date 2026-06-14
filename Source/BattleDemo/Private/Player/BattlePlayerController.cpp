// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BattlePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

ABattlePlayerController::ABattlePlayerController()
{
	this->bReplicates = true;
}

void ABattlePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// init input context
	check(Battle_Context);
	
	UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		// Add the input mapping context, with a higher priority than the default
		Subsystem->AddMappingContext(Battle_Context, 0);
	}
}

void ABattlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//get inputComponet
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &ABattlePlayerController::Move);
	
	EnhancedInputComponent->BindAction(InputAction_Jump, ETriggerEvent::Triggered, this, &ABattlePlayerController::Jump);
	
}

void ABattlePlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();

	// rotation
	const FRotator CurrentControlRotation = GetControlRotation();
	const FRotator YawRotation(0, CurrentControlRotation.Yaw, 0);

	// get forward and right vector
	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	//set pawn movement
	if (APawn* MyPawn = GetPawn())
	{
		MyPawn->AddMovementInput(ForwardVector, MoveValue.Y);
		MyPawn->AddMovementInput(RightVector, MoveValue.X);
	}
}

void ABattlePlayerController::Jump(const FInputActionValue& Value)
{
	if (APawn* MyPawn = GetPawn())
	{
		if (ACharacter* MyChar = Cast<ACharacter>(MyPawn))
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.8f, FColor::Blue, "Print Current Value");
			MyChar->Jump();
			
		}
	}
}
