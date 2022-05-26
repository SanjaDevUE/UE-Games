﻿#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "CCGame/Classes/Economy/CCResourceType.h"

#include "CCPlayerResourcesComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FCCPlayerResourcesComponentResourcesChangedSignature, TSubclassOf<UCCResourceType>, ResourceType, float, OldResourceAmount, float, NewResourceAmount, bool, bSyncedFromServer);


/**
* Attach to player or AI controllers. Allows the controller to store resources
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class UCCPlayerResourcesComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCCPlayerResourcesComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    void BeginPlay() override;


    // Gets the amount of resources in stock of this player
    UFUNCTION(BlueprintPure)
    float GetResources(TSubclassOf<UCCResourceType> ResourceType) const;

    // Gets the types of resources available to this player
    TArray<TSubclassOf<UCCResourceType>> GetResourceTypes() const;

    // Checks the amount of resources in stock of this player
    UFUNCTION(BlueprintPure)
    bool CanPayResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount) const;

    // Checks the amount of resources in stock of this player
    UFUNCTION(BlueprintPure)
    bool CanPayAllResources(TMap<TSubclassOf<UCCResourceType>, float> Resources) const;

    // Adds the specified resources to the stock of this player
    UFUNCTION(BlueprintCallable)
    virtual float AddResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount);

    // Removes the specified resources from the stock of this player
    UFUNCTION(BlueprintCallable)
    virtual float PayResources(TSubclassOf<UCCResourceType> ResourceType, float ResourceAmount);

    // Removes the specified resources from the stock of this player
    UFUNCTION(BlueprintCallable)
    virtual void PayAllResources(TMap<TSubclassOf<UCCResourceType>, float> Resources);


    // Event when the current resource stock amount for the player has changed
    UPROPERTY(BlueprintAssignable, Category = "RTS")
    FCCPlayerResourcesComponentResourcesChangedSignature OnResourcesChanged;

private:
    // Types of resources currently available to this player. Num must match ResourceAmounts. Need to use an array here instead of map for replication
    UPROPERTY(EditDefaultsOnly, Category = "RTS|Resources")
    TArray<TSubclassOf<UCCResourceType>> ResourceTypes;

    // Resources currently available to this player. Num must match ResourceTypes. Need to use an array here instead of map for replication
    UPROPERTY(EditDefaultsOnly, Category = "RTS|Resources", ReplicatedUsing = ReceivedResourceAmounts)
    TArray<float> ResourceAmounts;

    UFUNCTION()
    void ReceivedResourceAmounts();
};