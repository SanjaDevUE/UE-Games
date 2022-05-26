#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CCOrder.h"

#include "CCOrderData.generated.h"

class AActor;

// Order to be issued to an actor
USTRUCT(BlueprintType)
struct FCCOrderData
{
	GENERATED_BODY()

public:
	FCCOrderData();

	// Type of the order to issue
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "RTS")
	TSubclassOf<UCCOrder> OrderClass;

	// Target Order
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "RTS")
	AActor* TargetActor;

	// Target location
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "RTS")
	FVector TargetLocation;

	// Additional index
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "RTS")
	int32 Index;
};
