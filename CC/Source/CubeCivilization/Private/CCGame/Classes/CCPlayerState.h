#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "CCPlayerState.generated.h"

class AActor;
class ACCTeamInfo;

/**
* Player state with rts features, such as teams
*/
UCLASS()
class ACCPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	static const uint8 PLAYER_INDEX_NONE;

	ACCPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// Gets the index of the player
	UFUNCTION(BlueprintPure)
	uint8 GetPlayerIndex() const;
	// Gets the team this player belongs to
	UFUNCTION(BlueprintPure)
	ACCTeamInfo* GetTeam() const;

	// Sets the index of the player
	void SetPlayerIndex(uint8 InPlayerIndex);
	// Sets the team this player belongs to
	void SetTeam(ACCTeamInfo* InTeam);

	// Checks whether this player belong to the same team as specified one
	UFUNCTION(BlueprintPure)
	bool IsSameTeamAs(const ACCPlayerState* Other) const;
	// Gets the list of actors currently owned by this player
	UFUNCTION(BlueprintPure)
	TArray<AActor*> GetOwnActors() const;

	// Looks for all actors currently owned by this player an caches their references
	void DiscoverOwnActors();

	// Event when this player changed team
	virtual void NotifyOnTeamChanged(ACCTeamInfo* NewTeam);
	// Event when this player is now owning or no longer owning the specified actor
	virtual void NotifyOnActorOwnerChanged(AActor* Actor, ACCPlayerState* OldOwner, ACCPlayerState* NewOwner);
	
	// Event when this player changed team
	UFUNCTION(BlueprintImplementableEvent, Category= "RTS|Team", meta=(DisplayName = "OnTeamChanged"))
	void ReceiveOnTeamChanged(ACCTeamInfo* NewTeam);

private:
	// Index of the player
	UPROPERTY(Replicated)
	uint8 PlayerIndex;

	// Team this player belongs to
	UPROPERTY(ReplicatedUsing = OnTeamChanged)
	ACCTeamInfo* Team;

	// Actors this player owns
	UPROPERTY()
	TArray<AActor*> OwnActors;

	UFUNCTION()
	void OnTeamChanged();
};
