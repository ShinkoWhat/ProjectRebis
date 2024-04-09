// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}

void ABaseWeapon::PrimaryAbility_Implementation(class ACharacterBase* PlayerReference, FVector TargetLocation)
{
	IBaseAbility::PrimaryAbility_Implementation(PlayerReference, TargetLocation);
}

void ABaseWeapon::SecondaryAbility_Implementation(ACharacterBase* PlayerReference, FVector TargetLocation)
{
	IBaseAbility::SecondaryAbility_Implementation(PlayerReference, TargetLocation);
}

void ABaseWeapon::TransitionAbility_Implementation(ACharacterBase* PlayerReference, FVector TargetLocation)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Changed!"));
	IBaseAbility::TransitionAbility_Implementation(PlayerReference, TargetLocation);
}



