#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCStopOrder.generated.h"

// Orders the actor to stop whatever theyre currently doing
UCLASS()
class UCCStopOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCStopOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
