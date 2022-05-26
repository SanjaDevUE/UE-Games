#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCContinueConstructionOrder.generated.h"

// Orders the actor to continue constructing a building
UCLASS()
class UCCContinueConstructionOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCContinueConstructionOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
