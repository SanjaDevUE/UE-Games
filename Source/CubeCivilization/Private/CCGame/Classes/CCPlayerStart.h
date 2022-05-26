// Copyright SanjaDev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "CCPlayerStart.generated.h"

/**
 * Player start with RTS features, such as which player has been spawned at this start.
 */
UCLASS()
class ACCPlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	//Get the team to add the spawned player to
	UFUNCTION(BlueprintPure)
	int32 GetTeamIndex() const;

	//Get the player who's been spawned at this start
	UFUNCTION(BlueprintPure)
	AController* GetPlayer() const;

	//Sets the player who's been spawned at this start
	void SetPlayer(AController* InPlayer);

private:
	//Team to add the spawned player to
	UPROPERTY(EditInstanceOnly, Category= "Team")
	uint8 TeamIndex;

	//Player who's been spawned at this start
	UPROPERTY()
	AController* Player;
};
