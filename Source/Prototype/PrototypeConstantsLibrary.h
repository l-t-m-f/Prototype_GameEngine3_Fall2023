// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PrototypeConstantsLibrary.generated.h"

enum class EPrototypeMoveDirection : uint8;

UCLASS()
class PROTOTYPE_API UPrototypeConstantsLibrary : public UBlueprintFunctionLibrary
{
   GENERATED_BODY()

   UFUNCTION(BlueprintCallable, BlueprintPure)
   static int GetDefaultHealth();

   UFUNCTION(BlueprintCallable, BlueprintPure)
   static int GetIntFromMoveDirection(EPrototypeMoveDirection Direction);
};
