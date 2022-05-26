#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"

#include "CCCameraBoundsVolume.generated.h"

/**
* Volume that restricts RTS Camera Movement
* RTS Cameras are not allowed to outside of this volume
* there should never be more than one camera bounds volume per level
*/
UCLASS()
class ACCCameraBoundsVolume : public AVolume
{
	GENERATED_BODY()
	
};
