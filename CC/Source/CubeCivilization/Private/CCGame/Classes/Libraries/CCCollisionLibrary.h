#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"

#include "CCCollisionLibrary.generated.h"

class UObject;
class UShapeComponent;

// Utility functions for calculating actor collisions
UCLASS()
class UCCCollisionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// Gets the distance between the two specified actors optionally subtracting their collision sizes
	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetActorDistance(AActor* First, AActor* Second, bool bConsiderCollisionSize);

	// Gets the approximated collision size of actors of the specified class
	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetCollisionSize(TSubclassOf<AActor> ActorClass);

	// Gets the approximated collision size of the specified actor
	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetCollisionHeight(TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetActorCollisionSize(AActor* Actor);

	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetActorCollisionHeight(AActor* Actor);

	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetShapeCollisionSize(UShapeComponent* ShapeComponent);

	UFUNCTION(BlueprintPure, Category= "RTS")
	static float GetShapeCollisionHeight(UShapeComponent* ShapeComponent);

	UFUNCTION(BlueprintPure, Category= "RTS", meta=(WorldContext = "WorldContextObject"))
	static FVector GetGroundLocation(UObject* WorldContextObject, FVector Location);

	UFUNCTION(BlueprintPure, Category= "RTS")
	static bool IsSuitableLocationForActor(UWorld* World, TSubclassOf<AActor> ActorClass, const FVector& Location);
};
