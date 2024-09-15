// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttemptData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "http.h"
#include "Dom/JsonObject.h"
#include "TelemetrySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTREBIS_API UTelemetrySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UTelemetrySubsystem();
	
public:

	UFUNCTION(BlueprintCallable)
	void ReadIndices();

	UFUNCTION(BlueprintCallable)
	void WriteIndices(FAttemptData AttemptData);


private:

	UPROPERTY()
	FString URL;

	UPROPERTY()
	FString IndicesName;
};
