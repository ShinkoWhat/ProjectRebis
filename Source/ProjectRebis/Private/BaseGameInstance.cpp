// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameInstance.h"

void UBaseGameInstance::Init()
{
	Super::Init();

	AsyncLoadGameFromSlotDelegate.BindUObject(this, &UBaseGameInstance::OnAsyncLoadCallback);
	Execute_LoadGameData(this, false);
}

void UBaseGameInstance::SaveGameData_Implementation(bool bIsAsync = true)
{
	if (bIsAsync)
	{
		UGameplayStatics::AsyncSaveGameToSlot(SaveDataInit, SaveFileName, 0);
	}
	else
	{
		UGameplayStatics::SaveGameToSlot(SaveDataInit, SaveFileName, 0);
	}
}

void UBaseGameInstance::LoadGameData_Implementation(bool bIsAsync = true)
{
	if (UGameplayStatics::DoesSaveGameExist(SaveFileName, 0))
	{
		if (bIsAsync)
		{
			UGameplayStatics::AsyncLoadGameFromSlot(SaveFileName, 0, AsyncLoadGameFromSlotDelegate);
		}
		else
		{
			UGameplayStatics::LoadGameFromSlot(SaveFileName, 0);
		}
	}
	else
	{
		UGameplayStatics::CreateSaveGameObject(SaveData.Get());
	}
}

UBaseSaveData* UBaseGameInstance::GetGameData_Implementation()
{
	return SaveDataInit;
}

void UBaseGameInstance::WritePlayerData_Implementation(FBasePlayerSaveData PlayerSaveData, bool bIsAsync = true)
{
	SaveDataInit->PlayerSaveData = PlayerSaveData;
	Execute_SaveGameData(this, bIsAsync);
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
