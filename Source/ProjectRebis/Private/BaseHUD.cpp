// Fill out your copyright notice in the Description page of Project Settings.
// Check later https://snorristurluson.github.io/CustomSlateWidgets/

#include "BaseHUD.h"
#include "SSRadialMenu.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "Layout/Geometry.h"
#include "Input/Events.h"
#include "GameFramework/PlayerController.h"

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseHUD::ShowMenu()
{

	if (GEngine && GEngine->GameViewport)
	{
		RadialWidget = SNew(SSRadialMenu).ParentHUD(this);

		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(RadialWidgetContainer, SWeakWidget)
			.PossiblyNullContent(RadialWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			//PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void ABaseHUD::CloseMenu()
{
	if (GEngine && GEngine->GameViewport && RadialWidget.IsValid() && RadialWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(RadialWidgetContainer.ToSharedRef());
		if (PlayerOwner)
		{
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
