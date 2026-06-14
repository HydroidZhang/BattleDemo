// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BattleCharacter.generated.h"

class UGameplayAbility;
class UAbilitySystemComponent;

UCLASS()
class BATTLEDEMO_API ABattleCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABattleCharacter();
	
	virtual void PossessedBy(AController* NewController);

	virtual void OnRep_PlayerState() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual  void InitAbilitySystemInfo();
	
	void AddCharacterAbilities();
protected:
	UPROPERTY(EditAnywhere, Category = "GameAbility")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
public:
	UPROPERTY(EditAnywhere, Category = "GameAbility")
	TArray<TSubclassOf<UGameplayAbility>> StartUpAbilities;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
