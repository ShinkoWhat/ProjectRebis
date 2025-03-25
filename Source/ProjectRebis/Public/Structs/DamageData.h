// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageData.generated.h"

USTRUCT(BlueprintType)
struct FDamageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	AActor* OtherActor;

	UPROPERTY()
	UPrimitiveComponent* OtherComp;
	
	UPROPERTY(BlueprintReadWrite)
	double DamageValue;

	UPROPERTY(BlueprintReadWrite)
	double Poise;
	// ..Add more parameters
};
