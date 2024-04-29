// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"

#include "ArmsComponent.h"
#include "DamageManagerComponent.h"

// Sets default values
ANPCBase::ANPCBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ArmsComponent = CreateDefaultSubobject<UArmsComponent>(TEXT("DefaultArmsComponent"));
	DamageManagerComponent = CreateDefaultSubobject<UDamageManagerComponent>(TEXT("DefaultDamageManager"));
	//CurrentWeapon = nullptr;
}

// Called when the game starts or when spawned
void ANPCBase::BeginPlay()
{
	Super::BeginPlay();

	SkeletalMesh = GetMesh();
}

// Called every frame
void ANPCBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

