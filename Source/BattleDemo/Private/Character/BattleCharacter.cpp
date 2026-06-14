// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BattleCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/BattlePlayerState.h"

// Sets default values
ABattleCharacter::ABattleCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
}

void ABattleCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilitySystemInfo();
	AddCharacterAbilities();
}

void ABattleCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilitySystemInfo();
}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABattleCharacter::InitAbilitySystemInfo()
{
	// get PlayState and Cast it
	ABattlePlayerState* MyPlayerState = GetPlayerState<ABattlePlayerState>();
	
	check(MyPlayerState);
	
	AbilitySystemComponent = MyPlayerState->GetAbilitySystemComponent();
	
	AbilitySystemComponent->InitAbilityActorInfo(MyPlayerState, this);
}

void ABattleCharacter::AddCharacterAbilities()
{
	for (TSubclassOf<UGameplayAbility> Ability : StartUpAbilities)
	{
		//create Ability
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability,1);
		if (const UGameplayAbility* AuraAbility = Cast<UGameplayAbility>(Ability->GetDefaultObject()))
		{
			// // add startup tag to ability spec
			// AbilitySpec.DynamicAbilityTags.AddTag(AuraAbility->StartupTag);
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
		
	}
}

// Called every frame
void ABattleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

