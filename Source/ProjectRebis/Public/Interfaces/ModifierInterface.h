// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModifierInterface.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class UModifierInterface : public UInterface
{
	GENERATED_BODY()
};

class IModifierInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void ModifierAbility();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void ApplyModifier();
	
};