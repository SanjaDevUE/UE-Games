#include "CCGame/Classes/Economy/CCPlayerResourcesComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "CCGame/Classes/CCLog.h"
#include "CCGame/Classes/Economy/CCResourceType.h"

UCCPlayerResourcesComponent::UCCPlayerResourcesComponent(const FObjectInitializer& ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UCCPlayerResourcesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCCPlayerResourcesComponent, ResourceAmounts);
}

void UCCPlayerResourcesComponent::BeginPlay()
{
	Super::BeginPlay();

	// Check resource types
	int32 ResourceTypeNum = ResourceTypes.Num();
	int32 ResourceAmountNum = ResourceAmounts.Num();

	for (int32 Index = ResourceAmountNum; Index < ResourceTypeNum; ++Index)
	{
		UE_LOG(LogCC, Warning, TEXT("Starting amount for resource type %s not set for player %s, assuming zero."),
			*ResourceTypes[Index]->GetName(),
			*GetOwner()->GetName());

		ResourceAmounts.Add(0);
	}
}

float UCCPlayerResourcesComponent::GetResources(TSubclassOf<UCCResourceType> ResourceType) const
{
	// Get current resource amount
	int32 ResourceIndex = ResourceTypes.IndexOfByKey(ResourceType);

	if (ResourceIndex == INDEX_NONE)
	{
		UE_LOG(LogCC, Error, TEXT("Unknown resource type %s for player %s."),
			*ResourceType->GetName(),
			*GetOwner()->GetName());

		return 0.0f;
	}
	return ResourceAmounts[ResourceIndex];
}

TArray<TSubclassOf<UCCResourceType>> UCCPlayerResourcesComponent::GetResourceTypes() const
{
	return ResourceTypes;
}

bool UCCPlayerResourcesComponent::CanPayResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount) const
{
	float AvailableResources = GetResources(ResourceType);
	return AvailableResources >= ResourceAmount;
}

bool UCCPlayerResourcesComponent::CanPayAllResources(TMap<TSubclassOf<UCCResourceType>, float> Resources) const
{
	for (auto& Resource : Resources)
	{
		if (!CanPayResources(Resource.Key, Resource.Value))
		{
			return false;
		}
	}
	return true;
}

float UCCPlayerResourcesComponent::AddResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount)
{
	int32 ResourceIndex = ResourceTypes.IndexOfByKey(ResourceType);

	if (ResourceIndex == INDEX_NONE)
	{
		return 0.0f;
	}

	// Get current resource amount
	float OldResourceAmount = GetResources(ResourceType);

	// Add resources
	float NewResourceAmount = OldResourceAmount + ResourceAmount;
	ResourceAmounts[ResourceIndex] = NewResourceAmount;

	UE_LOG(LogCC, Verbose, TEXT("Player %s stock of %s has changed to %f."),
		*GetOwner()->GetName(),
		*ResourceType->GetName(),
		NewResourceAmount);

	// Notify listeners
	OnResourcesChanged.Broadcast(ResourceType, OldResourceAmount, NewResourceAmount, false);
	return ResourceAmount;
}

float UCCPlayerResourcesComponent::PayResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount)
{
	// Get current resource amount
	float OldResourceAmount = GetResources(ResourceType);

	if (OldResourceAmount < ResourceAmount)
	{
		return 0.0f;
	}

	// Deduct resources
	return AddResources(ResourceType, -ResourceAmount);
}

void UCCPlayerResourcesComponent::PayAllResources(TMap<TSubclassOf<UCCResourceType>, float> Resources)
{
	for (auto& Resource : Resources)
	{
		PayResources(Resource.Key, Resource.Value);
	}
}

void UCCPlayerResourcesComponent::ReceivedResourceAmounts()
{
	for (int32 Index = 0; Index < ResourceTypes.Num(); ++Index)
	{
		OnResourcesChanged.Broadcast(ResourceTypes[Index], 0.0f, ResourceAmounts[Index], true);
	}
}