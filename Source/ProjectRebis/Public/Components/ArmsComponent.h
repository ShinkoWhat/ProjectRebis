// Fill out your copyright notice in the Description page of Project Settings.
// https://www.tomlooman.com/unreal-engine-cpp-guide/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/StreamableManager.h"
#include "ArmsComponent.generated.h"

struct FStreamableManager;
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

	UFUNCTION(BlueprintCallable)
	void OnWeaponChange(double InputValue);

	UFUNCTION(BlueprintCallable)
	void NextWeapon();

	UFUNCTION(BlueprintCallable)
	void PreviousWeapon();
	
	FOnWeaponChangeSignature OnWeaponChangeDelegate;

	UFUNCTION(BlueprintCallable)
	FString GetMapKeyByValue(class ABaseWeapon* Value);

	UFUNCTION(BlueprintCallable)
	void AssignNewWeapon(int32 Id);

	
public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	class ACharacterBase* PlayerCharacterReference;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Default")
	TMap<FString, ABaseWeapon*> WeaponArray;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TArray<FString> WeaponArrayKeys;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	int32 CurrentWeaponID;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Default")
	TMap<FString, TSoftClassPtr<class UBaseModifier>> ModifierArray;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sockets")
	FName PrimarySocket;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Sockets")
	FName SecondarySocket;

	UPROPERTY(BlueprintReadOnly, Category="Sockets")
	FName RecoverySocketName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Sockets")
	TMap<FString, FName> SocketArray;
};
