// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BattlePlayerState.h"

#include "AbilitySystemComponent.h"

ABattlePlayerState::ABattlePlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//set replication
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ABattlePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
