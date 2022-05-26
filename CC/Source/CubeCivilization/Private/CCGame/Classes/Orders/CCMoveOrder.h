#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCMoveOrder.generated.h"

// Order the actor to move to the specified location
UCLASS()
class UCCMoveOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCMoveOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
