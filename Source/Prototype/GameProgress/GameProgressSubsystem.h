// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameProgressSubsystem.generated.h"

UCLASS()
class PROTOTYPE_API UGameProgressSubsystem : public UGameInstanceSubsystem
{
   GENERATED_BODY()
   
   virtual void Initialize(FSubsystemCollectionBase &Collection) override;

   virtual void Deinitialize() override;

   UFUNCTION(BlueprintCallable)
   FString GetMessage() const {
      return Message;
   }
   
   FString Message = "I am the Progress!!!!";
   
};
