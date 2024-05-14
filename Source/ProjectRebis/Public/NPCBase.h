// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GameFramework/Character.h"
#include "NPCBase.generated.h"

UCLASS(CustomConstructor)
class PROJECTREBIS_API ANPCBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
