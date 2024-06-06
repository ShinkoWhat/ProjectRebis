// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmsComponent.h"

#include <string>

#include "BaseWeapon.h"
#include "CharacterBase.h"
#include "Engine/StreamableManager.h"

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

	InstantiatePlayer();

	OnWeaponChangeDelegate.AddUObject(this, &UArmsComponent::OnWeaponChange);
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
	
	
	
}

void UArmsComponent::OnWeaponChange(double InputValue)
{
	if (InputValue == 1)
	{
		NextWeapon();
	}
	else if (InputValue == -1)
	{
		PreviousWeapon();
	}
}

void UArmsComponent::NextWeapon()
{
	if (CurrentWeaponID < WeaponArrayKeys.Num())
	{
		CurrentWeaponID = (CurrentWeaponID + 1) % 3;
		AssignNewWeapon(CurrentWeaponID);
	}
}

void UArmsComponent::PreviousWeapon()
{
	if (CurrentWeaponID >= 0)
	{
		CurrentWeaponID == 0 ? CurrentWeaponID = WeaponArrayKeys.Num() - 1 : CurrentWeaponID = CurrentWeaponID - 1;
		AssignNewWeapon(CurrentWeaponID);
	}
}

FString UArmsComponent::GetMapKeyByValue(ABaseWeapon* Value)
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
	//PlayerCharacterReference->CurrentWeapon->AttachToComponent(PlayerCharacterReference->GetMesh(),
	//	FAttachmentTransformRules::SnapToTargetIncludingScale,
	//	SocketArray.FindRef(WeaponArray.FindKey(WeaponArrayKeys[])));
	//RecoverySocketName = WeaponArray.FindRef(WeaponArrayKeys[Id])->GetAttachParentSocketName();
	//PlayerCharacterReference->CurrentWeapon->AttachToComponent(PlayerCharacterReference->GetMesh(),
	//	FAttachmentTransformRules::SnapToTargetIncludingScale,
	//	RecoverySocketName);
	PlayerCharacterReference->CurrentWeapon = WeaponArray.FindRef(WeaponArrayKeys[Id]);
	PlayerCharacterReference->AttachWeaponToCharacter(PlayerCharacterReference->CurrentWeapon, PrimarySocket);
}

void UArmsComponent::InstantiatePlayer()
{
	//Save character reference
	PlayerCharacterReference = Cast<ACharacterBase>(GetOwner());

	WeaponArray.Add("Dexterity", nullptr);
	WeaponArray.Add("Strength", nullptr);
	WeaponArray.Add("Support", nullptr);

	SocketArray.Add("Dexterity", "LeftShoulderSocket");
	SocketArray.Add("Strength", "Spine2Socket");
	SocketArray.Add("Support", "RightShoulderSocket");
	
	WeaponArray.GenerateKeyArray(WeaponArrayKeys);

	CurrentWeaponID = 0;
	AssignNewWeapon(CurrentWeaponID);
}


