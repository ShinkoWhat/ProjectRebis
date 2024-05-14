// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "InputConfigData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTREBIS_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputPrimary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputSecondary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputScroll;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMiddleMouse;

	// DEBUG

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* DEBUGInputSave;
};
