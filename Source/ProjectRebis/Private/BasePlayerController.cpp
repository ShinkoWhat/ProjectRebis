// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

#include "BaseWeapon.h"
#include "PlayerCharacter.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);

	PlayerCharacterReference = Cast<ACharacterBase>(GetPawn());

	SetupPlayerInputComponent(InputComponent);
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	GetHitResultUnderCursorForObjects(TypeQuery, false, Hit);
	CachedCursorLocation = Hit.Location;

	auto msg = TEXT("Cursor Loc: ") + CachedCursorLocation.ToString();
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, msg);
	PlayerCharacterReference->CameraComponent->SetTargetLocation(CachedCursorLocation);
}

void ABasePlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	PEI->BindAction(InputActions->InputPrimary, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionPrimary);
	PEI->BindAction(InputActions->InputSecondary, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionSecondary);
	PEI->BindAction(InputActions->InputScroll, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionTransition);
}

void ABasePlayerController::ActionPrimary(const FInputActionInstance& Instance)
{
	IBaseAbility* AbilityInterface = Cast<IBaseAbility>(PlayerCharacterReference->CurrentWeapon.Get());
	if (AbilityInterface)
	{
		AbilityInterface->Execute_PrimaryAbility(PlayerCharacterReference->CurrentWeapon.Get(), PlayerCharacterReference, CachedCursorLocation);
		UE_LOG(LogTemp, Warning, TEXT("Action: Primary!"));
	}
}

void ABasePlayerController::ActionSecondary(const FInputActionInstance& Instance)
{
	UE_LOG(LogTemp, Warning, TEXT("Action: Secondary!"));
}

void ABasePlayerController::ActionTransition(const FInputActionValue& Value)
{
	PlayerCharacterReference->ArmsComponent->OnWeaponChangeDelegate.Broadcast(Value.GetMagnitude());
}

