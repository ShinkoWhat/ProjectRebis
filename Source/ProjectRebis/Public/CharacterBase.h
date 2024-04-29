// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmsComponent.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CameraControlComponent.h"
#include "DamageManagerComponent.h"
#include "CharacterBase.generated.h"

UCLASS()
class PROJECTREBIS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UFUNCTION(BlueprintCallable)
	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintCallable)
	void OnWeaponPickup(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
					  int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	UCameraComponent* GetCamera() const { return Camera; }

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToCharacter(ABaseWeapon* WeaponToAttach, FName Socket);

	UFUNCTION(BlueprintCallable)
	void SetCameraTransform(FVector Value) { Camera->SetWorldLocation(Value); }

	UFUNCTION(BlueprintCallable)
	void TestOverlapHandler(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

//Components
public:

	UPROPERTY()
	USceneComponent* DefaultSceneComponent;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	//UCapsuleComponent* Capsule;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	USkeletalMeshComponent* SkeletalMesh;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	UCameraControlComponent* CameraComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	UArmsComponent* ArmsComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	UDamageManagerComponent* DamageManagerComponent;

//Properties
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	int32 HP;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FVector FloorNormal;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TSubclassOf<ABaseWeapon> WeaponClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	ABaseWeapon* CurrentWeapon;
};

