// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "DamageData.h"
#include "BaseWeapon.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(GetCapsuleComponent());
	
	Camera = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("DefaultCamera"));
	Camera->SetupAttachment(RootComponent);
	CameraComponent = CreateOptionalDefaultSubobject<UCameraControlComponent>(TEXT("DefaultCameraControl"));
	ArmsComponent = CreateDefaultSubobject<UArmsComponent>(TEXT("DefaultArmsComponent"));
	DamageManagerComponent = CreateDefaultSubobject<UDamageManagerComponent>(TEXT("DefaultDamageManager"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	SkeletalMesh = Super::GetMesh();
	Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharacterBase::OnWeaponPickup);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharacterBase::TestOverlapHandler);
}

void ACharacterBase::OnWeaponPickup(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABaseWeapon* OtherWeapon = Cast<ABaseWeapon>(OtherActor);

	FString ReplaceID = ArmsComponent->GetMapKeyByValue(nullptr);

	if (ArmsComponent->WeaponArrayKeys.Contains(ReplaceID))
	{
		ArmsComponent->WeaponArray.Emplace(ReplaceID, OtherWeapon);
	}
}

void ACharacterBase::AttachWeaponToCharacter(ABaseWeapon* WeaponToAttach, FName Socket)
{
	//auto msg1 = TEXT("AAAAAAAAAAAAAAAA");
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	if (IsValid(WeaponToAttach))
	{
		//auto msg = TEXT("OOOOOOOOOOO");
		//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg);
		WeaponToAttach->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, Socket);
		CurrentWeapon = WeaponToAttach;
	}
}

void ACharacterBase::TestOverlapHandler(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto msg1 = TEXT("UUUUUUUUUUUu");
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, msg1);
	FDamageData NewDamageData;
	NewDamageData.OtherActor = OtherActor;
	NewDamageData.DamageValue = DamageManagerComponent->BaseDamage;
	NewDamageData.OtherComp = OtherComp;
	DamageManagerComponent->OnSendDamageDelegate.Broadcast(NewDamageData);
}

