#pragma once

#include "CoreMinimal.h"

#include "CCOrder.h"

#include "CCSetRallyPointToLocationOrder.generated.h"


// Orders a production actor to set its rally point to a specific target location
UCLASS()
class UCCSetRallyPointToLocationOrder : public UCCOrder
{
	GENERATED_BODY()

public:
	UCCSetRallyPointToLocationOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void IssueOrder(AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const override;
};