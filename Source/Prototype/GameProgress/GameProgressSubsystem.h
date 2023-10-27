// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameProgressSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FNPC_Details {
   
   GENERATED_BODY()

   UPROPERTY(EditAnywhere, BlueprintReadOnly)
   int CurrentQuestLine;

   UPROPERTY(EditAnywhere, BlueprintReadOnly)
   int CurrentDialogSlide;

   // Ways to create this structure: 

   FNPC_Details(int InCurrentQuestLine, int InCurrentDialogSlide)
      : CurrentQuestLine(InCurrentQuestLine), CurrentDialogSlide(InCurrentDialogSlide) {}

   // Default :
   FNPC_Details() : CurrentQuestLine(0), CurrentDialogSlide(0) {}
   
};

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

   UFUNCTION(BlueprintCallable, BlueprintPure)
   FNPC_Details GetNPC_Details(const FName &InName) const;


private:
   UPROPERTY()
   TMap<FName, FNPC_Details> NPC_Details;
   
   int LocalPoints;
   
};
