// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Templates/SubclassOf.h"
#include "CCGameMode.generated.h"

class AController;
class ACCPlayerAIController;
class ACCPlayerStart;
class ACCTeamInfo;

/**
 * Game mode with RTS features, such as spawning initial units for each player.
 */

UCLASS()
class ACCGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ACCGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	ACCPlayerStart* FindCCPlayerStart(AController* Player);

	virtual void RestartPlayer(AController* NewPlayer) override;
	virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot) override;
};
