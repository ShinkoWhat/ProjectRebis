// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseLevelManager.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class UBaseLevelManager : public UInterface
{
	GENERATED_BODY()
};

class IBaseLevelManager
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void LoadMainMenu();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void UnloadMainMenu();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void LoadTargetLevel(const FString& TargetLevel);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void UnloadTargetLevel(const FString& TargetLevel);
};
