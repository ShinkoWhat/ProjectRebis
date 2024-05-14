// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseAbility.h"
#include "Animation/SkeletalMeshActor.h"
#include "Components/BoxComponent.h"
#include "WeaponType.h"
#include "BaseWeapon.generated.h"

UCLASS(Blueprintable)
class PROJECTREBIS_API ABaseWeapon : public ASkeletalMeshActor, public IBaseAbility
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintCallable)
	virtual void PostInitializeComponents() override;

public:
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TArray<UAnimMontage*> ComboMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="DefaultCollision")
	UBoxComponent* BoxCollision;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Default")
	TEnumAsByte<EWeaponType> WeaponType;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void PrimaryAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);
	virtual void PrimaryAbility_Implementation(class ACharacterBase* PlayerReference, FVector TargetLocation) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void SecondaryAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);
	virtual void SecondaryAbility_Implementation(class ACharacterBase* PlayerReference, FVector TargetLocation) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void TransitionAbility(class ACharacterBase* PlayerReference, FVector TargetLocation);
	virtual void TransitionAbility_Implementation(class ACharacterBase* PlayerReference, FVector TargetLocation) override;
};
