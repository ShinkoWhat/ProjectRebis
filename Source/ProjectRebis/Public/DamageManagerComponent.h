// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageHandler.h"
#include "Components/ActorComponent.h"
#include "DamageManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSendDamageDelegate, FDamageData, DamageData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRecieveDamageDelegate, FDamageData, DamageData);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTREBIS_API UDamageManagerComponent : public UActorComponent, public IDamageHandler
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	FOnSendDamageDelegate OnSendDamageDelegate;
	FOnRecieveDamageDelegate OnRecieveDamageDelegate;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void SendDamage(FDamageData DamageData);
	virtual void SendDamage_Implementation(FDamageData DamageData) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interface")
	void RecieveDamage(FDamageData DamageData);
	virtual void RecieveDamage_Implementation(FDamageData DamageData) override;

	UFUNCTION(BlueprintCallable)
	void SendDamageHandler(FDamageData DamageData);
	
	UFUNCTION(BlueprintCallable)
	void RecieveDamageHandler(FDamageData DamageData);

	UFUNCTION(BlueprintCallable)
	void AddPropulsion();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double BaseDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default",
		meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	double CritChance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double CritMultiplier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double DefenseMultiplier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double AttackSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default",
		meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	double Poise;
	
};
