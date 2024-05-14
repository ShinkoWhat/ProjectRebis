// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageManagerComponent.h"
#include "DamageData.h"
#include "NPCBase.h"

// Sets default values for this component's properties
UDamageManagerComponent::UDamageManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	OnSendDamageDelegate.AddDynamic(this, &UDamageManagerComponent::SendDamageHandler);
	OnRecieveDamageDelegate.AddDynamic(this, &UDamageManagerComponent::RecieveDamageHandler);
}


// Called when the game starts
void UDamageManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UDamageManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void UDamageManagerComponent::SendDamage_Implementation(FDamageData DamageData)
{
	IDamageHandler::SendDamage_Implementation(DamageData);
}

void UDamageManagerComponent::RecieveDamage_Implementation(FDamageData DamageData)
{
	IDamageHandler::RecieveDamage_Implementation(DamageData);
}

void UDamageManagerComponent::SendDamageHandler(FDamageData DamageData)
{
	if (Cast<ACharacterBase>(DamageData.OtherActor)->DamageManagerComponent)
	{
		auto msg2 = TEXT("Hit Event");
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg2);
		AddPropulsion(DamageData);
		Cast<ACharacterBase>(DamageData.OtherActor)->DamageManagerComponent->OnRecieveDamageDelegate.Broadcast(DamageData);
	}
}

void UDamageManagerComponent::RecieveDamageHandler(FDamageData DamageData)
{
	auto msg1 = TEXT("NPC Damaged: " + GetOwner()->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	
	if (DamageData.OtherActor == GetOwner())
	{
		Cast<ACharacterBase>(GetOwner())->HP = Cast<ACharacterBase>(GetOwner())->HP - DamageData.DamageValue;
	}
}

void UDamageManagerComponent::AddPropulsion(FDamageData DamageData)
{
	if (DamageData.OtherActor)
	{
		FVector ActorVelocity = Cast<ACharacterBase>(GetOwner())->GetVelocity();
		double OtherActorPoise = Cast<ACharacterBase>(DamageData.OtherActor)->DamageManagerComponent->Poise;
		ActorVelocity *= (1 - OtherActorPoise);
		Cast<ACharacterBase>(DamageData.OtherActor)->LaunchCharacter(ActorVelocity, false, false);
	}
}

