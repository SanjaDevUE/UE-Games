#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CCOrderGroupExecutionType.h"
#include "CCOrderTagRequirements.h"
#include "CCOrderTargetData.h"
#include "CCOrderTargetType.h"

#include "CCOrder.generated.h"

class UTexture2D;

// Order that can be issued to an actor
UCLASS(BlueprintType, Blueprintable)
class UCCOrder : public UObject
{
	GENERATED_BODY()
public:
	// Whether the specified actor can obey this order
	virtual bool CanObeyOrder(const AActor* OrderActor, int32 Index) const;
	// Whether the specified actor and/or location is a valid target for this order
	virtual bool IsValidTarget(const AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const;
	// Issues this order to the specified actor
	virtual void IssueOrder(AActor* OrderedActor, const FCCOrderTargetData& TargetData, int32 Index) const;
	
	// Gets the target required by this order
	ECCOrderTargetType GetTargetType() const;
	// Gets how many and which of the selected actors the order should be issued to
	ECCOrderGroupExecutionType GetGroupExecution() const;
	// Gets the tag requirements that must be fulfilled to issue the order
	FCCOrderTagRequirements GetIssueTagRequirements() const;
	
	// Gets the normal icon of the order
	UTexture2D* GetNormalIcon() const;
	// Gets the hovered icon of the order
	UTexture2D* GetHoveredIcon() const;
	// Get the pressed icon of the order
	UTexture2D* GetPressedIcon() const;
	// Get the disable icon of the order
	UTexture2D* GetDisableIcon() const;
	// Get the name of the order
	FText GetName() const;

	// Gets the description of the order
	virtual FText GetDescription(const AActor* OrderedActor, int32 Index) const;

protected:
	// Target required by this order
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	ECCOrderTargetType TargetType;

	// How many and which of the selected actors the order should be issued to
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	ECCOrderGroupExecutionType GroupExecutionType;

	// Tag requirements that must be fulfilled to issue the order
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	FCCOrderTagRequirements IssueTagRequirements;

	// Tag requirements that must be fulfilled for the order to be successful
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	FCCOrderTagRequirements SuccessTagRequirements;

	// Normal icon of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	UTexture2D* NormalIcon;

	// Hovered icon of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	UTexture2D* HoveredIcon;

	// Pressed icon of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	UTexture2D* PressedIcon;

	// Disabled icon of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	UTexture2D* DisabledIcon;

	// Name of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	FText Name;

	// Default description of the order. Can be shown in the UI
	UPROPERTY(EditDefaultsOnly, Category = "RTS")
	FText Description;
};
