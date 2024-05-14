// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModifierInterface.h"
#include "ModifierType.h"
#include "UObject/NoExportTypes.h"
#include "BaseModifier.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTREBIS_API UBaseModifier : public UObject, public IModifierInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<class ACharacterBase> PlayerCharacterReference;

	UPROPERTY(BlueprintReadOnly)
	TEnumAsByte<EModifierType> ModifierType;

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void ModifierAbility();
	void ModifierAbility_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void ApplyModifier();
	void ApplyModifier_Implementation() override;
};
