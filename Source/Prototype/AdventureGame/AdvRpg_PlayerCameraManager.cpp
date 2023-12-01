#include "AdvRpg_PlayerCameraManager.h"

#include "Camera/CameraModifier_CameraShake.h"

UCameraShakeBase *
AAdvRpg_PlayerCameraManager::AddShake(
   TSubclassOf<UCameraShakeBase> ShakeClass, const float Scale)
{
   const FAddCameraShakeParams Params(Scale);
   return CachedCameraShakeMod->AddCameraShake(ShakeClass, Params);
}

void
AAdvRpg_PlayerCameraManager::RemoveShake(UCameraShakeBase *ShakeInstance)
{
   CachedCameraShakeMod->RemoveCameraShake(ShakeInstance);
}

void
AAdvRpg_PlayerCameraManager::RemoveAllShakes()
{
   CachedCameraShakeMod->RemoveAllCameraShakes();
}