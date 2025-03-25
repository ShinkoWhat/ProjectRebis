// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BasePlayerSaveData.h"
#include "BaseSaveData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTREBIS_API UBaseSaveData : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FBasePlayerSaveData PlayerSaveData;
	
	UPROPERTY(BlueprintReadWrite)
	ULevel* LastLevel;

	//..Add stats
};
