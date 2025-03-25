

#pragma once

#include <UnrealWidgetFwd.h>
#include <Engine/DataTable.h>

#include "CoreMinimal.h"
#include <UObject/Object.h>
#include "StatFieldData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FStatFieldData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FText FormatText;

	//UPROPERTY(BlueprintReadWrite)
	//UUserWidget* WidgetToFormat = nullptr;

	UPROPERTY(BlueprintReadWrite)
	FText InText;
};
