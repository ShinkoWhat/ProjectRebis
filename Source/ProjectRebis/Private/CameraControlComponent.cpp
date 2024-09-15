// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControlComponent.h"

#include "CharacterBase.h"
#include "ClearReplacementShaders.h"
#include "VectorTypes.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UCameraControlComponent::UCameraControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}

// Called when the game starts
void UCameraControlComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacterReference = Cast<ACharacterBase>(GetOwner());

	Camera = PlayerCharacterReference->GetCamera();
	CameraOrigin = Camera->GetRelativeLocation();

	//Tolerance = 0.2f;
	FalloffRange = 500.0f;
}

// Called every frame
void UCameraControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//FString CameraName = Camera->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Camera Object: %ls"), *PlayerCharacterReference->GetName());
	CameraSpring(0.0f);
	double Alpha = 1 - pow(Tolerance, DeltaTime);
	FVector OffsetLerp = FMath::Lerp(CurrentLocation, TargetLocation, Alpha);
	Camera->SetWorldLocation(OffsetLerp);
}

void UCameraControlComponent::CameraSpring(const double Alpha = 0.5f)
{
	FVector SkeletalMeshLoc = PlayerCharacterReference->SkeletalMesh->GetComponentLocation();
	FVector DistanceFromCharacterToCursor = SkeletalMeshLoc - TargetLocation;
	FVector CameraLocation = PlayerCharacterReference->GetCamera()->GetComponentLocation();
	CurrentLocation.Set(CameraLocation.X, CameraLocation.Y, CameraLocation.Z);

	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Cyan, DistanceFromCharacterToCursor.ToString());

	double dAlpha = FMath::Exp(-DistanceFromCharacterToCursor.Length() / FalloffRange);
	
	auto msg = FString::SanitizeFloat(dAlpha);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, msg);
	
	FVector BufferLerp = FMath::Lerp(FVector(SkeletalMeshLoc.X, SkeletalMeshLoc.Y, CameraLocation.Z),
		FVector(TargetLocation.X, TargetLocation.Y, CameraLocation.Z), dAlpha);
	TargetLocation = FVector(BufferLerp.X + CameraOrigin.X, BufferLerp.Y + CameraOrigin.Y, SkeletalMeshLoc.Z + CameraOrigin.Z);
}

void UCameraControlComponent::NearestCentroidSpring(TArray<AActor*> OtherActors)
{
	FVector SkeletalMeshLoc = PlayerCharacterReference->SkeletalMesh->GetComponentLocation();
	TArray<double> DistanceArray;
	for (auto iter : OtherActors)
	{
		auto Buffer = (iter->GetActorLocation() - SkeletalMeshLoc).Length();
		DistanceArray.Add(Buffer);
	}
}



