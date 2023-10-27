// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameProgressSubsystem.generated.h"

UENUM(BlueprintType)
enum class EDialogAction : uint8 {
   ACTION_None UMETA(DisplayName="None", HIDDEN),
   ACTION_CloseDialog UMETA(DisplayName="Close Dialog"),
   ACTION_NextQuestLine UMETA(DisplayName="Next Quest line"),
   ACTION_NextSlide UMETA(DisplayName="Next Slide"),
   ACTION_MAX UMETA(HIDDEN)
};

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

   UFUNCTION(BlueprintCallable)
   void UpdateNPC_Details(const FName &InName, EDialogAction InAction);


private:
   UPROPERTY()
   TMap<FName, FNPC_Details> NPC_Details;
   
   int LocalPoints;
   
};
