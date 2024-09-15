// Fill out your copyright notice in the Description page of Project Settings.


#include "Stopwatch.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"

UStopwatch::UStopwatch()
	: bIsRunning(false)
	, StartTime(0.f)
	, AccumulatedTime(0.f)
{
}

void UStopwatch::Start()
{
	if (!bIsRunning)
	{
		StartTime = FPlatformTime::Seconds();
		bIsRunning = true;
	}
}

void UStopwatch::Stop()
{
	if (bIsRunning)
	{
		AccumulatedTime += FPlatformTime::Seconds() - StartTime;
		bIsRunning = false;
	}
}

void UStopwatch::Reset()
{
	bIsRunning = false;
	StartTime = 0.f;
	AccumulatedTime = 0.f;
}

float UStopwatch::GetElapsedTime() const
{
	if (bIsRunning)
	{
		return AccumulatedTime + (FPlatformTime::Seconds() - StartTime);
	}

	return AccumulatedTime;
}