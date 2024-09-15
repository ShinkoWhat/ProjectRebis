// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameInstance.h"

void UBaseGameInstance::Init()
{
	Super::Init();

	AsyncLoadGameFromSlotDelegate.BindUObject(this, &UBaseGameInstance::OnAsyncLoadCallback);
	Execute_LoadGameData(this, false, SaveFileName, SaveDataInit);
}

void UBaseGameInstance::NewSaveGameData_Implementation(bool bIsAsync, UBaseSaveData*& BaseSaveData)
{
	auto BufferSaveData = UGameplayStatics::CreateSaveGameObject(SaveData);
	BaseSaveData = Cast<UBaseSaveData>(BufferSaveData);
}

void UBaseGameInstance::SaveGameData_Implementation(bool bIsAsync, UBaseSaveData* BaseSaveData, const FString& SaveSlotName)
{
	if (bIsAsync)
	{
		UGameplayStatics::AsyncSaveGameToSlot(BaseSaveData, SaveSlotName, 0);
	}
	else
	{
		UGameplayStatics::SaveGameToSlot(BaseSaveData, SaveSlotName, 0);
	}
}

void UBaseGameInstance::LoadGameData_Implementation(bool bIsAsync, const FString& SaveSlotName, UBaseSaveData*& BaseSaveData)
{
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		if (bIsAsync)
		{
			UGameplayStatics::AsyncLoadGameFromSlot(SaveSlotName, 0, AsyncLoadGameFromSlotDelegate);
		}
		else
		{
			BaseSaveData = Cast<UBaseSaveData>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error: No SaveGame file found."));
	}
}

UBaseSaveData* UBaseGameInstance::GetGameData_Implementation()
{
	return Cast<UBaseSaveData>(SaveData->GetDefaultObject());
}

void UBaseGameInstance::WritePlayerData_Implementation(FBasePlayerSaveData PlayerSaveData, bool bIsAsync = true)
{
	Cast<UBaseSaveData>(SaveData->GetDefaultObject())->PlayerSaveData = PlayerSaveData;
	Execute_SaveGameData(this, bIsAsync, SaveDataInit, SaveFileName);
}

void UBaseGameInstance::OnAsyncLoadCallback(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::Black, TEXT("Successfully Loaded " + SlotName));
}


void UBaseGameInstance::LoadMainMenu_Implementation()
{
	IBaseLevelManager::LoadMainMenu_Implementation();
}

void UBaseGameInstance::UnloadMainMenu_Implementation()
{
	IBaseLevelManager::UnloadMainMenu_Implementation();
}

void UBaseGameInstance::UnloadTargetLevel_Implementation(const FString& TargetLevel)
{
	IBaseLevelManager::UnloadTargetLevel_Implementation(TargetLevel);
}

void UBaseGameInstance::LoadTargetLevel_Implementation(const FString& TargetLevel)
{
	IBaseLevelManager::LoadTargetLevel_Implementation(TargetLevel);
}
