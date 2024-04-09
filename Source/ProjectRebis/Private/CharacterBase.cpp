// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"

#include "BaseWeapon.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(GetCapsuleComponent());
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("DefaultCamera"));
	Camera->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraControlComponent>(TEXT("DefaultCameraControl"));
	ArmsComponent = CreateDefaultSubobject<UArmsComponent>(TEXT("DefaultArmsComponent"));
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

void ACharacterBase::AddPropulsion(double PropulsionValue)
{
}

