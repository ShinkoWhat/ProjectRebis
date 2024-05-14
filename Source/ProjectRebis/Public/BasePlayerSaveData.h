// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BasePlayerSaveData.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct FBasePlayerSaveData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class ABaseWeapon> CurrentWeapon;

	UPROPERTY(BlueprintReadWrite)
	TMap<FString, TSoftClassPtr<ABaseWeapon>> EquippedWeapons;

	//..Add more parameters
};
