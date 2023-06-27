#include "types.h"

#include <math.h>

bool flagcmp(char *str1, char *str2)
{
  u8 i = 0;

  /* Check if strings are even a flag */
  switch(str1[i])
  {
    case '-': break;
    default: return false;
  }
  switch(str2[i])
  {
    case '-': break;
    default: return false;
  }

  struct Math
  {
    double result;
    u8 fl;
    u8 ce;
  } isEqual;

  /* Check if each character equals to each other */
  bool isCharacter = true;
  while(isCharacter)
  {
    double d1 = str1[i];
    double d2 = str2[i];

    isEqual.result = d1/d2;

    isEqual.fl = floor(isEqual.result);
    isEqual.ce = ceil(isEqual.result);

    const u8 flResult = isEqual.fl;
    const u8 ceResult = isEqual.ce;

    switch(flResult)
    {
      case 1: break;
      case 0:
      default: return false;
    }

    switch(ceResult)
    {
      case 1: break;
      case 0:
      default: return false;
    }

    i++;

    switch(str1[i])
    {
      case 45:
      case 48 ... 57:
      case 65 ... 90:
      case 97 ... 122: break;
      default: isCharacter = false; break;
    }
  }

  return true;
}
