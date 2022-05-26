#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"
#include "GameFramework/Actor.h"

#include "CCGatherOrder.generated.h"

// Orders the actor to gather resources from another actor
UCLASS()
class UCCGatherOrder : public UCCOrder
{
	GENERATED_BODY()

public:
	UCCGatherOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void IsValidTarget(const AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const;
};