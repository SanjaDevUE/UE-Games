#include "CCGame/Classes/CCActorComponent.h"

void UCCActorComponent::AddGameplayTags(FGameplayTagContainer& InOutTagContainer)
{
	InOutTagContainer.AppendTags(InitialGameplayTags);
}
