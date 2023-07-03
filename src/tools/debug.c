#include "types.h"

#include <stdio.h>

void debug(char *log, u8 priority)
{
  switch(priority)
  {
    case 1: printf("%sOK: %s%s\n",      COLOUR_GREEN,   log, COLOUR_RESET); break;
    case 2: printf("%sWARNING: %s%s\n", COLOUR_YELLOW,  log, COLOUR_RESET); break;
    case 3: printf("%sERROR: %s%s\n",   COLOUR_RED,     log, COLOUR_RESET); break;
    default: printf("DEBUG: %s\n", log); break;
  }
}

