// Fill out your copyright notice in the Description page of Project Settings.


#include "CCGame/Classes/CCPlayerStart.h"

int32 ACCPlayerStart::GetTeamIndex() const
{
	return TeamIndex;
}

AController* ACCPlayerStart::GetPlayer() const
{
	return Player;
}

void ACCPlayerStart::SetPlayer(AController* InPlayer)
{
	Player = InPlayer;
}
