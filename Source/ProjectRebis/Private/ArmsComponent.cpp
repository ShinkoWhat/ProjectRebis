// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmsComponent.h"

#include "CharacterBase.h"

// Sets default values for this component's properties
UArmsComponent::UArmsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UArmsComponent::BeginPlay()
{
	Super::BeginPlay();
	
	//OnWeaponChangeDelegate.AddUObject(this, &UArmsComponent::OnWeaponChange);
}


// Called every frame
void UArmsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UArmsComponent::PostLoad() 
{
	Super::PostLoad();

	InstantiatePlayer();

	OnWeaponChangeDelegate.AddUObject(this, &UArmsComponent::OnWeaponChange);

	CurrentWeaponID = 0;
	AssignNewWeapon(CurrentWeaponID);
}

void UArmsComponent::OnWeaponChange(double InputValue)
{
	if (InputValue > 0)
	{
		if (CurrentWeaponID < WeaponArrayKeys.Num())
		{
			CurrentWeaponID++;
			AssignNewWeapon(CurrentWeaponID);
		}
		else if (CurrentWeaponID == WeaponArray.Num() - 1)
		{
			CurrentWeaponID = 0;
			AssignNewWeapon(CurrentWeaponID);
		}
	}
	else
	{
		if (CurrentWeaponID > 0)
		{
			CurrentWeaponID--;
			AssignNewWeapon(CurrentWeaponID);
		}
		else if (CurrentWeaponID == 0)
		{
			CurrentWeaponID = WeaponArrayKeys.Num() - 1;
			AssignNewWeapon(CurrentWeaponID);
		}
	}
}

FString UArmsComponent::GetMapKeyByValue(TSoftObjectPtr<ABaseWeapon> Value)
{
	for (auto& Pair : WeaponArray)
	{
		if (Pair.Value == Value)
		{
			return Pair.Key; 
		}
	}
	return "";
}

void UArmsComponent::AssignNewWeapon(int32 Id)
{
	PlayerCharacterReference->CurrentWeapon = WeaponArray.FindRef(WeaponArrayKeys[Id]);
}

void UArmsComponent::InstantiatePlayer()
{
	//Save character reference
	PlayerCharacterReference = Cast<ACharacterBase>(GetOwner());

	WeaponArray.Add("Dexterity", nullptr);
	WeaponArray.Add("Strength", nullptr);
	WeaponArray.Add("Support", nullptr);
	
	WeaponArray.GenerateKeyArray(WeaponArrayKeys);
}


