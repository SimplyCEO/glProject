#include "types.h"
#include "tools/getopt.h"
#include "tools/string.h"

#include <stdio.h>

int getopt(char *opt, char *shortFlag, char *longFlag)
{
  enum Flags flag;
  u8 i = 0;
  bool foundFlag = false;
  bool isExtendedFlag = false;

  while(!foundFlag)
  {
    switch(opt[i])
    {
      case '-':
        {
          switch (opt[i+1])
          {
            case '-': isExtendedFlag = true; break;
            default: break;
          }
          foundFlag = true;
        break;
        }
      default: foundFlag = nil; break;
    }
  }

  switch(foundFlag)
  {
    case 1:
      {
        switch(isExtendedFlag)
        {
          case 0:
            {
              const bool comparison = flagcmp(opt, shortFlag);
              return comparison;
            break;
            }
          case 1:
            {
              const bool comparison = flagcmp(opt, longFlag);
              return comparison;
            break;
            }
          default: break;
        }
      break;
      }
    case 0:
    case 2:
    default: break;
  }

  return 1;
}
