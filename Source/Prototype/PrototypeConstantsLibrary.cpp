#include "PrototypeConstantsLibrary.h"

#include "PrototypeMoveDirection.h"

int
UPrototypeConstantsLibrary::GetDefaultHealth()
{
   return 10;
}

int
UPrototypeConstantsLibrary::GetIntFromMoveDirection(
   EPrototypeMoveDirection Direction)
{
   if(static_cast<int>(Direction)
      > static_cast<int>(EPrototypeMoveDirection::MAX))
      {
         return static_cast<int>(EPrototypeMoveDirection::MAX);
      }
   return static_cast<int>(Direction);
}