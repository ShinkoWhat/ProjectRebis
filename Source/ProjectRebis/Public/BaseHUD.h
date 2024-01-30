// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTREBIS_API ABaseHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	
	TSharedPtr<class SSRadialMenu> RadialWidget;
	TSharedPtr<class SWidget> RadialWidgetContainer;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void ShowMenu();

	UFUNCTION(BlueprintCallable)
	virtual void CloseMenu();
};
