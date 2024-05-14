// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModifierType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EModifierType : uint8
{
	MT_Dexterity		UMETA(DisplayName = "Dexterity"),
	MT_Strength			UMETA(DisplayName = "Strength"),
	MT_Support			UMETA(DisplayName = "Support")
};
