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
	auto msg1 = TEXT("OOOOOOOOOOOOOOOOO");
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	if (DamageData.OtherComp->GetClass()->ImplementsInterface(UDamageHandler::StaticClass()))
	{
		Cast<UDamageManagerComponent>(DamageData.OtherComp)->OnRecieveDamageDelegate.Broadcast(DamageData);
	}
}

void UDamageManagerComponent::RecieveDamage_Implementation(FDamageData DamageData)
{
	auto msg1 = TEXT("AAAAAAAAAAAAAAAA");
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	GetOwner()->Destroy();
	IDamageHandler::RecieveDamage_Implementation(DamageData);
}

void UDamageManagerComponent::SendDamageHandler(FDamageData DamageData)
{
	auto msg1 = TEXT("OOOOOOOOOOOOOOOOO");
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	if (Cast<class ANPCBase>(DamageData.OtherActor)->DamageManagerComponent)
	{
		auto msg2 = TEXT("AAAAAAAAAAAAAAAA");
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg2);
		Cast<class ANPCBase>(DamageData.OtherActor)->DamageManagerComponent->OnRecieveDamageDelegate.Broadcast(DamageData);
	}
}

void UDamageManagerComponent::RecieveDamageHandler(FDamageData DamageData)
{
	
	GetOwner()->Destroy();
}

void UDamageManagerComponent::AddPropulsion()
{
}

