// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "BattlePlayerState.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class BATTLEDEMO_API ABattlePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ABattlePlayerState();
	
	// asc 
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
