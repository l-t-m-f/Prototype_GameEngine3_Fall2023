// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FastNoiseLite.h"

#include "FastNoiseBlueprintLibrary.generated.h"

UCLASS()
class FASTNOISEBLUEPRINT_API UFastNoiseBlueprintLibrary
   : public UBlueprintFunctionLibrary
{
   GENERATED_BODY()

public:
   UFastNoiseBlueprintLibrary();

   UFUNCTION(BlueprintCallable, BlueprintPure)
   static float GetPerlinNoise3D(const FIntVector &Coordinates);

private:
   static FastNoiseLite PerlinGenerator;
};
