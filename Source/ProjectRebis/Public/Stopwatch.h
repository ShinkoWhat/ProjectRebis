// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Stopwatch.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTREBIS_API UStopwatch : public UObject
{
	GENERATED_BODY()

public:
	// Initializes stopwatch with a zero time
	UStopwatch();

	// Starts the stopwatch
	UFUNCTION(BlueprintCallable)
	void Start();

	// Stops the stopwatch
	UFUNCTION(BlueprintCallable)
	void Stop();

	// Resets the stopwatch to zero
	UFUNCTION(BlueprintCallable)
	void Reset();

	// Returns elapsed time in seconds
	UFUNCTION(BlueprintCallable)
	float GetElapsedTime() const;

private:
	// Whether the stopwatch is currently running
	bool bIsRunning;

	// Time when the stopwatch was started
	float StartTime;

	// Accumulated time when not running
	float AccumulatedTime;
};
