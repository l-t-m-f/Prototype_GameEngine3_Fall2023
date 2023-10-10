#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPrototypeMoveDirection : uint8
{
   None UMETA(DisplayName = "None"),
   Up UMETA(DisplayName = "Up direction (0)"),
   Left UMETA(DisplayName = "Left direction (1)"),
   Down UMETA(DisplayName = "Down direction (2)"),
   Right UMETA(DisplayName = "Right direction (3)"),
   MAX UMETA(HIDDEN)
};