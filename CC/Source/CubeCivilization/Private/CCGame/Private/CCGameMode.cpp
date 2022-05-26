// Fill out your copyright notice in the Description page of Project Settings.


#include "CCGame/Classes/CCGameMode.h"

ACCGameMode::ACCGameMode(const FObjectInitializer& ObjectInitializer)
{
}

void ACCGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ACCGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

ACCPlayerStart* ACCGameMode::FindCCPlayerStart(AController* Player)
{
	return NULL;
}

void ACCGameMode::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);
}

void ACCGameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot)
{
	Super::RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}
