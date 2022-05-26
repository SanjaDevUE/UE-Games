#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "CCOrderTargetData.generated.h"

class AActor;

// Target data (actor, location) for an order
USTRUCT(BlueprintType)
struct FCCOrderTargetData
{
	GENERATED_BODY()

public:
	// Target Actor
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	AActor* Actor;

	// Target Location
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	FVector Location;

	// Gameplay tags of target
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	FGameplayTagContainer TargetTags;
};
