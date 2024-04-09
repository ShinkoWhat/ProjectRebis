// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "CameraControlComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTREBIS_API UCameraControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraControlComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FVector CurrentLocation;
		
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FVector TargetLocation;
	
public:

	UFUNCTION(BlueprintCallable)
	void SetTargetLocation(FVector _Target)
	{
		TargetLocation = _Target;
	}

	UFUNCTION()
	void CameraSpring(double Alpha);
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	class ACharacterBase* PlayerCharacterReference;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double Tolerance;
};
