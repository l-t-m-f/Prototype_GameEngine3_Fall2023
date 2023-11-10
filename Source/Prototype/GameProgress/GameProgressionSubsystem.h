// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameProgressionSubsystem.generated.h"

UENUM(BlueprintType)
enum class EDialogAction : uint8
{
   ACTION_None UMETA(DisplayName = "None", HIDDEN),

   ACTION_CloseDialog UMETA(DisplayName = "Close Dialog"),
   ACTION_NextQuestLine UMETA(DisplayName = "Next Quest line"),
   ACTION_NextSlide UMETA(DisplayName = "Next Slide"),

   ACTION_MAX UMETA(HIDDEN)
};

USTRUCT(BlueprintType)

struct FNPC_Details
{

   GENERATED_BODY()

   UPROPERTY(EditAnywhere, BlueprintReadOnly)
   int CurrentQuestLine;

   UPROPERTY(EditAnywhere, BlueprintReadOnly)
   TArray<int> QuestLineSlideProgressArray;

   // Ways to create this structure:

   FNPC_Details(int InCurrentQuestLine)
      : CurrentQuestLine(InCurrentQuestLine),
        QuestLineSlideProgressArray(TArray<int>())
   {
      constexpr int MaxQuestLines = 10;
      QuestLineSlideProgressArray.SetNum(MaxQuestLines);
   }

   // Default :
   FNPC_Details()
      : CurrentQuestLine(0), QuestLineSlideProgressArray(TArray<int>())
   {
   }
};

UCLASS(Config=GameProgress)

class PROTOTYPE_API UGameProgressionSubsystem : public UGameInstanceSubsystem
{
   GENERATED_BODY()

public:
   virtual void Initialize(FSubsystemCollectionBase &Collection) override;

   virtual void Deinitialize() override;

   /* Point system */
   UFUNCTION(BlueprintCallable)
   void SavePointsToSubsystem(const int InPoints);

   UFUNCTION(BlueprintCallable, BlueprintPure)
   int GetLocalSavedPoints() const;

   /* NPC progress system */

   /**
    * Returns an NPC detail status structure from the given NPC name.
    * @param InName
    * @return
    */
   UFUNCTION(BlueprintCallable, BlueprintPure)
   FNPC_Details GetNPC_Details(const FName &InName) const;

   /**
    * Updates a NPC detail based on a specific action to be performed on the
    * data. That action is defined by the enum EDialogAction.
    * @param InName
    * @param InAction
    */
   UFUNCTION(BlueprintCallable)
   void UpdateNPC_Details(const FName &InName, EDialogAction InAction);

private:
   /**
    * Associative array of NPC names and their current quest status.
    */
   UPROPERTY()
   TMap<FName, FNPC_Details> NPC_Details;

   int LocalPoints;

   UPROPERTY(Config)
   int ConfigTest;

   UPROPERTY(Config)
   FVector ConfigVector;
};
