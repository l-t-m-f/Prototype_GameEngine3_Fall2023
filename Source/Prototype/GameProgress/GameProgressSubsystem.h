// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameProgressSubsystem.generated.h"

UCLASS()
class PROTOTYPE_API UGameProgressSubsystem : public UGameInstanceSubsystem
{
   GENERATED_BODY()

public:
   virtual void Initialize(FSubsystemCollectionBase &Collection) override;

   virtual void Deinitialize() override;

   UFUNCTION(BlueprintCallable)
   void SavePointsToSubsystem(const int InPoints);

   UFUNCTION(BlueprintCallable, BlueprintPure)
   int GetLocalSavedPoints() const;

private:
   int LocalPoints;
   
};
