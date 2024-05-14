// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BaseGamemode.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPreparePawnDelegate);

UCLASS()
class PROJECTREBIS_API ABaseGamemode : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	UWorld* CurrentLevel;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TSubclassOf<APawn> CharacterReference;
	
public:

	FOnPreparePawnDelegate OnPreparePawnDelegate;

	UFUNCTION(BlueprintCallable, Category="Default")
	void OnPreparePawnHandler();
	

};
