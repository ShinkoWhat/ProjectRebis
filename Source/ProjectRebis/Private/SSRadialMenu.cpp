// Fill out your copyright notice in the Description page of Project Settings.


#include "SSRadialMenu.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "RadialMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSRadialMenu::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	ParentHUD = InArgs._ParentHUD;

	const FText TestText = LOCTEXT("Test", "Test");

	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 60.f;

	ChildSlot
	[
		SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Bottom)
			[
				SNew(STextBlock)
					.Font(TextStyle)
					.Text(TestText)
					.Justification(ETextJustify::Center)
			]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
