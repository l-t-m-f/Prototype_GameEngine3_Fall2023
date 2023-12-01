// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AdvRpg_PlayerCameraManager.generated.h"

UCLASS(BlueprintType, Blueprintable)

class PROTOTYPE_API AAdvRpg_PlayerCameraManager : public APlayerCameraManager
{
   GENERATED_BODY()

public:
   UFUNCTION(BlueprintCallable)
   UCameraShakeBase *AddShake(TSubclassOf<UCameraShakeBase> ShakeClass, const float Scale);

   UFUNCTION(BlueprintCallable)
   void RemoveShake(UCameraShakeBase *ShakeInstance);

   UFUNCTION(BlueprintCallable)
   void RemoveAllShakes();
};
