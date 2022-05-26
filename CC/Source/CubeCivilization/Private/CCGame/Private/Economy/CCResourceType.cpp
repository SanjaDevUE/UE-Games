#include  "CCGame/Classes/Economy/CCResourceType.h"

FText UCCResourceType::GetResourceName() const
{
	return ResourceName;
}

UTexture2D* UCCResourceType::GetResourceIcon() const
{
	return ResourceIcon;
}

FLinearColor UCCResourceType::GetResourceColor() const
{
	return ResourceColor;
}
