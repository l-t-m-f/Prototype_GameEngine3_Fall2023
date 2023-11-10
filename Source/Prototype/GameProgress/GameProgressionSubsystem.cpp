#include "GameProgressionSubsystem.h"

#include "Kismet/KismetSystemLibrary.h"

void
UGameProgressionSubsystem::Initialize(FSubsystemCollectionBase &Collection)
{
   Super::Initialize(Collection);
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Initialized"));

   NPC_Details = TMap<FName, FNPC_Details>();
   NPC_Details.Add(FName("Test1"), FNPC_Details(0));
   NPC_Details.Add(FName("Test2"), FNPC_Details(2));
}

void
UGameProgressionSubsystem::Deinitialize()
{
   Super::Deinitialize();
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Deinitialized"));
}

void
UGameProgressionSubsystem::SavePointsToSubsystem(const int InPoints)
{
   LocalPoints = InPoints;
}

int
UGameProgressionSubsystem::GetLocalSavedPoints() const
{
   return LocalPoints;
}

FNPC_Details
UGameProgressionSubsystem::GetNPC_Details(const FName &InName) const
{
   return NPC_Details.FindRef(InName);
}

void
UGameProgressionSubsystem::UpdateNPC_Details(const FName &InName,
                                          EDialogAction InAction)
{
   FNPC_Details Details = NPC_Details.FindRef(InName);

   switch(InAction)
      {
      case EDialogAction::ACTION_CloseDialog:
         break;
      case EDialogAction::ACTION_NextQuestLine:
         Details.CurrentQuestLine = Details.CurrentQuestLine + 1;
         break;
      case EDialogAction::ACTION_NextSlide:
         Details.QuestLineSlideProgressArray[Details.CurrentQuestLine] += 1;
         break;
      default:;
      }

   UKismetSystemLibrary::PrintString(
      this,
      InName.ToString() + " " + FString::FromInt(Details.CurrentQuestLine)
         + " "
         + FString::FromInt(
            Details.QuestLineSlideProgressArray[Details.CurrentQuestLine]));

   NPC_Details.Add(InName, Details);
}
