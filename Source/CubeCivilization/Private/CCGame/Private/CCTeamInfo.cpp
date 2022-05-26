#include "CCGame/Classes/CCTeamInfo.h"

#include "CCGame/Classes/CCPlayerState.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

ACCTeamInfo::ACCTeamInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	bAlwaysRelevant = true;
	NetUpdateFrequency = 1.0f;

	// Force ReceivedTeamIndex() on clients
	TeamIndex = 255;
}

void ACCTeamInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ACCTeamInfo, TeamIndex, COND_InitialOnly);
}

void ACCTeamInfo::AddToTeam(AController* Player)
{
	if (Player == nullptr)
	{
		return;
	}

	ACCPlayerState* PlayerState = Cast<ACCPlayerState>(Player->PlayerState);
	if (PlayerState == nullptr)
	{
		return;
	}

	if (PlayerState->GetTeam() != nullptr)
	{
		RemoveFromTeam(Player);
	}

	PlayerState->SetTeam(this);
	PlayerState->NotifyOnTeamChanged(this);

	TeamMembers.Add(Player);
}

void ACCTeamInfo::RemoveFromTeam(AController* Player)
{
	if (Player == nullptr)
	{
		return;
	}

	if (!TeamMembers.Contains(Player))
	{
		return;
	}

	TeamMembers.Remove(Player);
	ACCPlayerState* PlayerState = Cast<ACCPlayerState>(Player->PlayerState);

	if (PlayerState != nullptr)
	{
		PlayerState->SetTeam(nullptr);
		PlayerState->NotifyOnTeamChanged(nullptr);
	}
}

uint8 ACCTeamInfo::GetTeamIndex() const
{
	return TeamIndex;
}

TArray<AController*> ACCTeamInfo::GetTeamMembers() const
{
	return TeamMembers;
}

void ACCTeamInfo::SetTeamIndex(uint8 InTeamIndex)
{
	TeamIndex = InTeamIndex;
}
