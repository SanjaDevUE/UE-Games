#pragma once

#include "CoreMinimal.h"
#include "CCPaymentType.generated.h"

UENUM(BlueprintType)
enum class ECCPaymentType : uint8
{
	// Pay whole production cost as soon as production starts
	PAYMENT_PayImmediately,

	// Pay production costs every tick while production proceeds
	PAYMENT_PayOverTime,

	// Don't pay production costs automatically
	PAYMENT_PayCustom
};
