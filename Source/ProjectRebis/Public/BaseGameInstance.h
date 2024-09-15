// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseLevelManager.h"
#include "LoadManagerInterface.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SaveGame.h"
#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTREBIS_API UBaseGameInstance : public UGameInstance, public ILoadManagerInterface, public IBaseLevelManager
{
	GENERATED_BODY()

protected:
	virtual void Init() override;
	
public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TMap<FString, TSoftObjectPtr<UWorld>> LevelsArray;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TSubclassOf<UBaseSaveData> SaveData;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Default")
	UBaseSaveData* SaveDataInit;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Default")
	FString SaveFileName;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void NewSaveGameData(bool bIsAsync, UBaseSaveData*& BaseSaveData);
	virtual void NewSaveGameData_Implementation(bool bIsAsync, UBaseSaveData*& BaseSaveData) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void SaveGameData(bool bIsAsync, UBaseSaveData* BaseSaveData, const FString& SaveSlotName);
	virtual void SaveGameData_Implementation(bool bIsAsync, UBaseSaveData* BaseSaveData, const FString& SaveSlotName) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void LoadGameData(bool bIsAsync, const FString& SaveSlotName, UBaseSaveData*& BaseSaveData);
	virtual void LoadGameData_Implementation(bool bIsAsync, const FString& SaveSlotName, UBaseSaveData*& BaseSaveData) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	UBaseSaveData* GetGameData();
	virtual UBaseSaveData* GetGameData_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void WritePlayerData(FBasePlayerSaveData PlayerSaveData, bool bIsAsync);
	virtual void WritePlayerData_Implementation(FBasePlayerSaveData PlayerSaveData, bool bIsAsync) override;

	FAsyncLoadGameFromSlotDelegate AsyncLoadGameFromSlotDelegate;

	UFUNCTION(BlueprintCallable)
	void OnAsyncLoadCallback(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void LoadMainMenu();
	virtual void LoadMainMenu_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void UnloadMainMenu();
	virtual void UnloadMainMenu_Implementation() override;

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void LoadTargetLevel(const FString& TargetLevel);
	virtual void LoadTargetLevel_Implementation(const FString& TargetLevel);

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void UnloadTargetLevel(const FString& TargetLevel);
	virtual void UnloadTargetLevel_Implementation(const FString& TargetLevel);
};
