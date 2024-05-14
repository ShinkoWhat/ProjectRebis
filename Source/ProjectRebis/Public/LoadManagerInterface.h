// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSaveData.h"
#include "UObject/NoExportTypes.h"
#include "LoadManagerInterface.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class ULoadManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class ILoadManagerInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void SaveGameData(bool bIsAsync);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void LoadGameData(bool bIsAsync);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	UBaseSaveData* GetGameData();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void WritePlayerData(FBasePlayerSaveData PlayerSaveData, bool bIsAsync);
};