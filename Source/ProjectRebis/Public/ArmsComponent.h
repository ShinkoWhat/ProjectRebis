// Fill out your copyright notice in the Description page of Project Settings.
// https://www.tomlooman.com/unreal-engine-cpp-guide/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArmsComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWeaponChangeSignature, double)

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class PROJECTREBIS_API UArmsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArmsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void InstantiatePlayer();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PostLoad() override;
	
	void OnWeaponChange(double InputValue);
	
	FOnWeaponChangeSignature OnWeaponChangeDelegate;

	UFUNCTION(BlueprintCallable)
	FString GetMapKeyByValue(TSoftObjectPtr<class ABaseWeapon> Value);

	UFUNCTION(BlueprintCallable)
	void AssignNewWeapon(int32 Id);
	
public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	class ACharacterBase* PlayerCharacterReference;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	int32 WeaponID;
	
	UPROPERTY(BlueprintReadWrite, Category="Default")
	TMap<FString, TSoftObjectPtr<ABaseWeapon>> WeaponArray;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TArray<FString> WeaponArrayKeys;

	UPROPERTY(BlueprintReadOnly)
	int32 CurrentWeaponID;
};
