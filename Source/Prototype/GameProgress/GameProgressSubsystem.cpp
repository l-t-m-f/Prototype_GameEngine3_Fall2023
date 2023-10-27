#include "GameProgressSubsystem.h"

void
UGameProgressSubsystem::Initialize(FSubsystemCollectionBase &Collection)
{
   Super::Initialize(Collection);
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Initialized"));

   NPC_Details = TMap<FName, FNPC_Details>();
   NPC_Details.Add(FName("Test1"), FNPC_Details());
   NPC_Details.Add(FName("Test2"), FNPC_Details(2,3));
   
}

void
UGameProgressSubsystem::Deinitialize()
{
   Super::Deinitialize();
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Deinitialized"));
}

void
UGameProgressSubsystem::SavePointsToSubsystem(const int InPoints)
{
   LocalPoints = InPoints;
}

int
UGameProgressSubsystem::GetLocalSavedPoints() const
{
   return LocalPoints;
}

FNPC_Details
UGameProgressSubsystem::GetNPC_Details(const FName &InName) const
{
   return NPC_Details.FindRef(InName);
}
