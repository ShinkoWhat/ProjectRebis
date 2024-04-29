// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjectBase.h"

#include "DamageManagerComponent.h"

// Sets default values
AGameObjectBase::AGameObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageManagerComponent = CreateDefaultSubobject<UDamageManagerComponent>(TEXT("DefaultDamageManager"));
}

// Called when the game starts or when spawned
void AGameObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

