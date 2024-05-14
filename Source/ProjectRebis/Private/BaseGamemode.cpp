// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGamemode.h"

#include "Kismet/GameplayStatics.h"

void ABaseGamemode::OnPreparePawnHandler()
{
	DefaultPawnClass = CharacterReference;
	APlayerController* SpawnedPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	SpawnDefaultPawnFor(SpawnedPlayerController,
		ChoosePlayerStart(SpawnedPlayerController));
}


