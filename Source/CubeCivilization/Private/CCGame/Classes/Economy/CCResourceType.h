#pragma once

#include "CoreMinimal.h"
#include "CCResourceType.generated.h"

class UTexture2D;

//Resource that can be gathered and spent for construction, production and researach
UCLASS(Blueprintable, BlueprintType)
class UCCResourceType : public UObject
{
	GENERATED_BODY()
public:
	// Get the display name of the resource
	UFUNCTION(BlueprintPure)
	FText GetResourceName() const;

	// Gets the icon to show next to resource amounts in the UI
	UFUNCTION(BlueprintPure)
	UTexture2D* GetResourceIcon() const;
	
	// Gets the color to use when showing resource amounts in the UI
	UFUNCTION(BlueprintPure)
	FLinearColor GetResourceColor() const;

private:
	// Display nae of the resource
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	FText ResourceName;

	// Icon to show next to resource amounts in the UI
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	UTexture2D* ResourceIcon;
	
	// Color to use when showing resource amounts in the UI
	UPROPERTY(EditDefaultsOnly, Category= "RTS")
	FLinearColor ResourceColor;
};
