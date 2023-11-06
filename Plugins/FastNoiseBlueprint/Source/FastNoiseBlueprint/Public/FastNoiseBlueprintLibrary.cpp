#include "FastNoiseBlueprintLibrary.h"

FastNoiseLite UFastNoiseBlueprintLibrary::PerlinGenerator = FastNoiseLite();

UFastNoiseBlueprintLibrary::UFastNoiseBlueprintLibrary()
{
   PerlinGenerator.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
   PerlinGenerator.SetSeed(FMath::FRandRange(999.f, 99999.f));
}

float
UFastNoiseBlueprintLibrary::GetPerlinNoise3D(const FIntVector &Coordinates)
{
   return PerlinGenerator.GetNoise<float>(Coordinates.X, Coordinates.Y,
                                          Coordinates.Z);
}