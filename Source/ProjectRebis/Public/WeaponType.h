// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EWeaponType : uint8
{
	WT_Melee		UMETA(DisplayName = "Melee"),
	WT_Ranged		UMETA(DisplayName = "Ranged"),
	WT_Special		UMETA(DisaplyName = "Special")
};

