// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class UBaseAbility : public UInterface
{
	GENERATED_BODY()
};

class IBaseAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void PrimaryAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void SecondaryAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void TransitionAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);
};

