// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageData.h"
#include "DamageHandler.generated.h"

UINTERFACE(BlueprintType)
class UDamageHandler : public UInterface
{
	GENERATED_BODY()
};

class IDamageHandler
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void SendDamage(FDamageData DamageData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void RecieveDamage(FDamageData DamageData);
};
