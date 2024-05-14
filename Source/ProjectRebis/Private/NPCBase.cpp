// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"

// Sets default values
ANPCBase::ANPCBase(const FObjectInitializer& ObjectInitializer)
	: ACharacterBase(ObjectInitializer.DoNotCreateDefaultSubobject(TEXT("DefaultCamera")).
		DoNotCreateDefaultSubobject(TEXT("DefaultCameraControl")).
		DoNotCreateDefaultSubobject(TEXT("DefaultArmsComponent")))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ANPCBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANPCBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


