#include "types.h"
#include "object.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/draw.h"
#include "gl/renderer.h"

struct KeyboardMap
{
  u8 pause;
  u8 up;
  u8 down;
  u8 left;
  u8 right;
  u8 transform;
  u8 sprint[4];
}input;

bool bKeyState[256];
u8 keyDelay = 0;

/* Configure keys ASCII/DEC */
void configureKeys(void)
{
  input.pause     = 27;
  input.up        = 'w';
  input.down      = 's';
  input.left      = 'a';
  input.right     = 'd';
  input.transform = 32;
  input.sprint[0] = input.up-32;
  input.sprint[1] = input.down-32;
  input.sprint[2] = input.left-32;
  input.sprint[3] = input.right-32;
}

int returnKey(u8 key)
{
  return bKeyState[key];
}

void handleKeys(struct Camera *camera)
{
  u8 i;
  bool pauseKey     = returnKey(input.pause);
  bool upKey        = returnKey(input.up);
  bool downKey      = returnKey(input.down);
  bool leftKey      = returnKey(input.left);
  bool rightKey     = returnKey(input.right);
  bool transformKey = returnKey(input.transform);
  bool bSprintKey   = false;
  float fSprint     = 1.0f;

  switch(keyDelay)
  {
    case 0: break;
    case 50:
    {
      keyDelay = 0;
      break;
    }
    default: keyDelay++; break;
  }

  switch(pauseKey){case 1: exit(0); break; default: break;}

  for(i=0; i<4; i++)
  {
    bool bBufferSprintKey = returnKey(input.sprint[i]);

    switch(bBufferSprintKey)
    {
      case 1: bSprintKey = true; break;
      default: break;
    }
  }

  switch(bSprintKey)
  {
    case 1: fSprint = 3.5f; break;
    default: break;
  }

  switch(upKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyState[input.sprint[0]] = false;
      break;
    }
    case 1: camera->z += fSprint*0.01f; break;
    default: break;
  }

  switch(downKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyState[input.sprint[1]] = false;
      break;
    }
    case 1: camera->z -= fSprint*0.01f; break;
    default: break;
  }

  switch(leftKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyState[input.sprint[2]] = false;
      break;
    }
    case 1: camera->x += fSprint*0.01f; break;
    default: break;
  }

  switch(rightKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyState[input.sprint[3]] = false;
      break;
    }
    case 1: camera->x -= fSprint*0.01f; break;
    default: break;
  }

  switch(transformKey)
  {
    case 1:
    {
      switch(keyDelay)
      {
        case 0:
        {
          drawWireframe();
          keyDelay = 1;
          break;
        }
        default: break;
      }
      break;
    }
    default: break;
  }
}

void keyPressed(u8 key, i32 x, i32 y)
{
  bKeyState[key] = true;
}

void keyReleased(u8 key, i32 x, i32 y)
{
  /*
  *   TODO:  This function will be used later for something.
  *          or be totally removed since it appears to do
  *          nothing useful.
  */

  bKeyState[key] = false;
}

