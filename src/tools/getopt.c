#include "types.h"

#include "tools/string.h"

int getopt(char *opt, char *shortFlag, char *longFlag)
{
  bool bFoundFlag = false;
  bool bExtendedFlag = false;

  while(!bFoundFlag)
  {
    switch(opt[0])
    {
      case '-':
        {
          switch (opt[1])
          {
            case '-': bExtendedFlag = true; break;
            default: break;
          }
          bFoundFlag = true;
        break;
        }
      default: bFoundFlag = nil; break;
    }
  }

  switch(bFoundFlag)
  {
    case 1:
      {
        switch(bExtendedFlag)
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
