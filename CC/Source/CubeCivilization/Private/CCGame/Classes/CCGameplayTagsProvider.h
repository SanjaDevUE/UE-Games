#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "CCGameplayTagsProvider.generated.h"

// Provides initial gameplay tags for actors
UINTERFACE(MinimalAPI)
class UCCGameplayTagsProvider : public UInterface
{
	GENERATED_BODY()
};

// Provides initial gameplay tags fpr actors
class ICCGameplayTagsProvider
{
	GENERATED_BODY()

public:
	// Adds gameplay tags to the specified tag container
	virtual void AddGameplayTags(FGameplayTagContainer& InOutTagContainer);
};