#include "GameProgressSubsystem.h"

void
UGameProgressSubsystem::Initialize(FSubsystemCollectionBase &Collection)
{
   Super::Initialize(Collection);
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Initialized"));
}

void
UGameProgressSubsystem::Deinitialize()
{
   Super::Deinitialize();
   UE_LOG(LogTemp, Warning, TEXT("Progress subsystem - Deinitialized"));
}