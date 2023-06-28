#include "types.h"
#include "gl/main.h"

#include <stdio.h>

bool keyStates[256];

void handleKeys(void)
{
  /*
  * TODO: Move key calls from 'keyPressed'.
  *       For some reason it's not working.
  */
}

void keyPressed(u8 key, i32 x, i32 y)
{
  keyStates[key] = true;

  /* ESC - Close window */
  switch(keyStates[27])
  {
    case 1: exit(0); break;
    default: break;
  }
}

void keyReleased(u8 key, i32 x, i32 y)
{
  /*
  *   TODO:  This function will be used later for something.
  *          or be totally removed since it appears to do
  *          nothing useful.
  */

  keyStates[key] = false;
}

