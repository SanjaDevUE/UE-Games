#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CCGameplayTagsProvider.h"
#include "GameplayTagContainer.h"

#include "CCActorComponent.generated.h"

// Base class for actor component with additional functionality e.g initial gameplay tags
UCLASS(meta=(BlueprintSpawnableComponent))
class UCCActorComponent : public UActorComponent, public ICCGameplayTagsProvider
 {
	GENERATED_BODY()
public:
	virtual void AddGameplayTags(FGameplayTagContainer& InOutTagContainer) override;

protected:
	// Gameplay tags to add the actor on beginplay
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	FGameplayTagContainer InitialGameplayTags;
};