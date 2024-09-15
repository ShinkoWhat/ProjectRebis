// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttemptData.generated.h"

/**
 * 
 */

USTRUCT(Blueprintable)
struct FAttemptData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite)
	FString PlayerDiagnosis;

	UPROPERTY(BlueprintReadWrite)
	FName LevelName;

	UPROPERTY(BlueprintReadWrite)
	int32 AttemptNumber;

	UPROPERTY(BlueprintReadWrite)
	double TimeElapsed;

	UPROPERTY(BlueprintReadWrite)
	int32 EnemiesDefeated;

	UPROPERTY(BlueprintReadWrite)
	int32 HitsTaken;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalScore;
};

