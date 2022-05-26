#pragma once

#include "CoreMinimal.h"
#include "CCOrderGroupExecutionType.generated.h"

// How many and which of the selected actors an orders should be issued to
UENUM(BlueprintType)
enum class ECCOrderGroupExecutionType : uint8
{
	// Order is simply, issued to all selected actors
	ORDERGROUPEXECUTION_ALL,
	// Order is issued to a single selected actor
	ODERGROUPEXECUTION_Any,
};
