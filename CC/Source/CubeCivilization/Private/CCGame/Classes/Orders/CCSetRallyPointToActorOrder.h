#pragma once

#include "CoreMinimal.h"
#include "CCOrder.h"

#include "CCSetRallyPointToActorOrder.generated.h"

// Order a production actor to set its rally point to a specific target actor
UCLASS()
class UCCSetRallyPointToActorOrder : public UCCOrder
{
	GENERATED_BODY()
public:
	UCCSetRallyPointToActorOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void IssueOrder(AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const override;
};
