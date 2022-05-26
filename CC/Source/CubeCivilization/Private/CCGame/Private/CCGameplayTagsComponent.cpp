#include "CCGame/Classes/CCGameplayTagsComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "CCGame/Classes/CCGameplayTagsProvider.h"
#include "CCGame/Classes/CCLog.h"
/**LOG CC failet*/

UCCGameplayTagsComponent::UCCGameplayTagsComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UCCGameplayTagsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCCGameplayTagsComponent, CurrentTags);
}

void UCCGameplayTagsComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (!IsValid(Owner))
	{
		return;
	}

	ICCGameplayTagsProvider* GameplayTagsProvider = Cast<ICCGameplayTagsProvider>(Owner);

	if (GameplayTagsProvider)
	{
		GameplayTagsProvider->AddGameplayTags(InitialTags);
	}

	for (UActorComponent* Component : Owner->GetComponents())
	{
		GameplayTagsProvider = Cast<ICCGameplayTagsProvider>(Component);

		if (GameplayTagsProvider)
		{
			GameplayTagsProvider->AddGameplayTags(InitialTags);
		}
	}

	for (const FGameplayTag& Tag : InitialTags)
	{
		CurrentTags.AddTagFast(Tag);
		
		/**UE_LOG(LogCC, Log, TEXT("Added initial gameplay tag %s for %s."), *Tag.ToString(), *GetOwner()->GetName());*/
	}
}

void UCCGameplayTagsComponent::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer.AppendTags(CurrentTags);
}

FGameplayTagContainer UCCGameplayTagsComponent::GetCurrentTags() const
{
	FGameplayTagContainer GameplayTagContainer;
	GetOwnedGameplayTags(GameplayTagContainer);
	return GameplayTagContainer;
}

void UCCGameplayTagsComponent::AddGameplayTag(const FGameplayTag& NewTag)
{
	CurrentTags.AddTag(NewTag);

	/**UE_LOG(LogCC, Log, TEXT("Added gameplay tag %s for %s."), *NewTag.ToString(), *GetOwner()->GetName());*/

	NotifyOnCurrentTagsChanged();
}

bool UCCGameplayTagsComponent::RemoveGameplayTag(const FGameplayTag& TagToRemove)
{
	bool bRemoved = CurrentTags.RemoveTag(TagToRemove);

	if (bRemoved)
	{
		/**UE_LOG(LogCC, Log, TEXT("Removed gameplay tag %s from %s."), *TagToRemove.ToString(), *GetOwner()->GetName());*/

		NotifyOnCurrentTagsChanged();
	}

	return bRemoved;
}

void UCCGameplayTagsComponent::RemoveGameplayTags(const FGameplayTagContainer& TagsToRemove)
{
	CurrentTags.RemoveTags(TagsToRemove);

	/**UE_LOG(LogCC, Log, TEXT("Removed gameplay tags %s from %s."), *TagsToRemove.ToString(), *GetOwner()->GetName());*/

	NotifyOnCurrentTagsChanged();
}

void UCCGameplayTagsComponent::NotifyOnCurrentTagsChanged()
{
	CurrentTagsChanged.Broadcast(GetOwner(), CurrentTags);
}

void UCCGameplayTagsComponent::ReceivedCurrentTags()
{
	NotifyOnCurrentTagsChanged();
}