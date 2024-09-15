// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AttemptData.h"
#include "ScoringSubsystem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBaseScoreValues
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 ENEMY = 500;

	UPROPERTY(BlueprintReadOnly)
	int32 HIT_PENALTY = 100;

	UPROPERTY(BlueprintReadOnly)
	int32 TIME_1 = 500;

	UPROPERTY(BlueprintReadOnly)
	int32 TIME_2 = 1500;

	UPROPERTY(BlueprintReadOnly)
	int32 TIME_3 = 3000;

	UPROPERTY(BlueprintReadOnly)
	int32 TIME_4 = 5000;
};

UCLASS()
class PROJECTREBIS_API UScoringSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UScoringSubsystem();

public:

	UPROPERTY(BlueprintReadOnly)
	FBaseScoreValues BaseScoreValues;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalScore;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentScore;

public:

	UFUNCTION(BlueprintCallable)
	int32 WriteTotalScore(double TimeElapsed);

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentScore(double Multiplier);

	UFUNCTION(BlueprintCallable)
	void SubtractCurrentScore();

	UFUNCTION(BlueprintCallable)
	void ResetCurrentScore();
};
