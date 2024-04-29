// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCBase.generated.h"

UCLASS()
class PROJECTREBIS_API ANPCBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	USkeletalMeshComponent* SkeletalMesh;

	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	//class UArmsComponent* ArmsComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	class UDamageManagerComponent* DamageManagerComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	int32 HP;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FVector FloorNormal;

	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	//TSubclassOf<class ABaseWeapon> WeaponClass;
	
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	//class ABaseWeapon* CurrentWeapon;

};
