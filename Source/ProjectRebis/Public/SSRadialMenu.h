// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class PROJECTREBIS_API SSRadialMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSRadialMenu)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class ABaseHUD>, ParentHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	/* Base HUD init */
	TWeakObjectPtr<class ABaseHUD> ParentHUD;

	/* Keyboard support */
	virtual bool SupportsKeyboardFocus() const override { return true; }

};
