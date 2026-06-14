// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BattlePlayerController.generated.h"

class UAbilitySystemComponent;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class BATTLEDEMO_API ABattlePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABattlePlayerController();
	
protected:
	UPROPERTY(EditAnywhere, Category = "GameAbility")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> Battle_Context;
	
	// input action 
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InputAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InputAction_Jump;
	
	void Move(const FInputActionValue& Value);
	
	void Jump(const FInputActionValue& Value);
};
