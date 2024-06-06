// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputConfigData.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitializePawn);

UCLASS(BlueprintType, Blueprintable)
class PROJECTREBIS_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

protected:

	UFUNCTION()
	void SetupPlayerInputComponent();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* InputMapping;

public:

	UPROPERTY(BlueprintCallable, Category="Default")
	FOnInitializePawn OnInitializePawn;

	UFUNCTION(BlueprintCallable)
	void ActionPrimary(const FInputActionInstance& Instance);
	
	UFUNCTION(BlueprintCallable)
	void ActionSecondary(const FInputActionInstance& Instance);

	UFUNCTION(BlueprintCallable)
	void ActionTransition(const FInputActionInstance& Instance);

	UFUNCTION(BlueprintCallable)
	void DEBUGActionSave(const FInputActionInstance& Instance);
	
public:

	FHitResult Hit;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	class ACharacterBase* PlayerCharacterReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputConfigData* InputActions;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Default")
	FVector CachedCursorLocation;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	TArray<TEnumAsByte<EObjectTypeQuery>> TypeQuery;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Movement")
	double CurrentAcceleration;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Movement")
	double CurrentMaxVelocity;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Movement")
	double CurrentMinVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Movement")
	double CurrentVelocity;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Movement")
	double CurrentTravelDistance;
};
