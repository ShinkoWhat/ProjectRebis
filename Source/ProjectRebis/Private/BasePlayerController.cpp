// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

#include "BaseGameInstance.h"
#include "BaseWeapon.h"
#include "PlayerCharacter.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);
	//SetupPlayerInputComponent(InputComponent);
	OnInitializePawn.AddDynamic(this, &ABasePlayerController::SetupPlayerInputComponent);
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (PlayerCharacterReference)
	{
		GetHitResultUnderCursorForObjects(TypeQuery, false, Hit);
		CachedCursorLocation = Hit.Location;

		auto msg = TEXT("Cursor Loc: ") + CachedCursorLocation.ToString();
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, msg);
		PlayerCharacterReference->CameraComponent->SetTargetLocation(CachedCursorLocation);
	}
}

void ABasePlayerController::SetupPlayerInputComponent()
{
	PlayerCharacterReference = Cast<ACharacterBase>(GetPawn());
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent);

	PEI->BindAction(InputActions->InputPrimary, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionPrimary);
	PEI->BindAction(InputActions->InputSecondary, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionSecondary);
	PEI->BindAction(InputActions->InputScroll, ETriggerEvent::Triggered, this, &ABasePlayerController::ActionTransition);
	PEI->BindAction(InputActions->DEBUGInputSave, ETriggerEvent::Triggered, this, &ABasePlayerController::DEBUGActionSave);
}

void ABasePlayerController::ActionPrimary(const FInputActionInstance& Instance)
{
	if (PlayerCharacterReference->CurrentWeapon->Implements<UBaseAbility>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Action: Primary!"));
		PlayerCharacterReference->CurrentWeapon->Execute_PrimaryAbility(PlayerCharacterReference->CurrentWeapon,
			PlayerCharacterReference, CachedCursorLocation, CurrentMinVelocity, CurrentMaxVelocity, CurrentVelocity);
	}
}

void ABasePlayerController::ActionSecondary(const FInputActionInstance& Instance)
{
	UE_LOG(LogTemp, Warning, TEXT("Action: Secondary!"));
}

void ABasePlayerController::ActionTransition(const FInputActionInstance& Instance)
{
	PlayerCharacterReference->ArmsComponent->OnWeaponChangeDelegate.Broadcast(Instance.GetValue().GetMagnitude());
}

void ABasePlayerController::DEBUGActionSave(const FInputActionInstance& Instance)
{
	if (PlayerCharacterReference)
	{
		FBasePlayerSaveData PlayerSaveData = PlayerCharacterReference->GetPlayerSaveData();
		Cast<UBaseGameInstance>(GetGameInstance())->Execute_WritePlayerData(this, PlayerSaveData, true);
	}
}

