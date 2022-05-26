#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCBeginConstructionOrder.generated.h"

// Order the actor to start constructing a building

UCLASS()
class UCCBeginConstructionOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCBeginConstructionOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
