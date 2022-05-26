#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCReturnResourcesOrder.generated.h"

// Orders the actor to return resources to another actor
UCLASS()
class UCCReturnResourcesOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCReturnResourcesOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	virtual bool IsValidTarget(const AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const override;
};
