#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCAttackOrder.generated.h"

// Orders the actor of attack another actor
UCLASS()
class UCCAttackOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCAttackOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
