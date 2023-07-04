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
}keyboardInput;

bool bKeyboardKeyState[256];
u8 keyboardKeyDelay = 0;

/* Configure keys ASCII/DEC */
void configureKeyboardKeys(void)
{
  keyboardInput.pause     = 27;
  keyboardInput.up        = 'w';
  keyboardInput.down      = 's';
  keyboardInput.left      = 'a';
  keyboardInput.right     = 'd';
  keyboardInput.transform = 32;
  keyboardInput.sprint[0] = keyboardInput.up-32;
  keyboardInput.sprint[1] = keyboardInput.down-32;
  keyboardInput.sprint[2] = keyboardInput.left-32;
  keyboardInput.sprint[3] = keyboardInput.right-32;
}

int returnKeyboardKey(u8 key)
{
  return bKeyboardKeyState[key];
}

void handleKeyboardKeys(struct Camera *camera)
{
  u8 i;
  bool pauseKey     = returnKeyboardKey(keyboardInput.pause);
  bool upKey        = returnKeyboardKey(keyboardInput.up);
  bool downKey      = returnKeyboardKey(keyboardInput.down);
  bool leftKey      = returnKeyboardKey(keyboardInput.left);
  bool rightKey     = returnKeyboardKey(keyboardInput.right);
  bool transformKey = returnKeyboardKey(keyboardInput.transform);
  bool bSprintKey   = false;
  float fSprint     = 1.0f;

  switch(keyboardKeyDelay)
  {
    case 0: break;
    case 50:
    {
      keyboardKeyDelay = 0;
      break;
    }
    default: keyboardKeyDelay++; break;
  }

  switch(pauseKey){case 1: exit(0); break; default: break;}

  for(i=0; i<4; i++)
  {
    bool bBufferSprintKey = returnKeyboardKey(keyboardInput.sprint[i]);

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
      bKeyboardKeyState[keyboardInput.sprint[0]] = false;
      break;
    }
    case 1: camera->pos.z += fSprint*0.01f; break;
    default: break;
  }

  switch(downKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyboardKeyState[keyboardInput.sprint[1]] = false;
      break;
    }
    case 1: camera->pos.z -= fSprint*0.01f; break;
    default: break;
  }

  switch(leftKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyboardKeyState[keyboardInput.sprint[2]] = false;
      break;
    }
    case 1: camera->pos.x += fSprint*0.01f; break;
    default: break;
  }

  switch(rightKey)
  {
    case 0:
    {
      bSprintKey = false;
      bKeyboardKeyState[keyboardInput.sprint[3]] = false;
      break;
    }
    case 1: camera->pos.x -= fSprint*0.01f; break;
    default: break;
  }

  switch(transformKey)
  {
    case 1:
    {
      switch(keyboardKeyDelay)
      {
        case 0:
        {
          drawWireframe();
          keyboardKeyDelay = 1;
          break;
        }
        default: break;
      }
      break;
    }
    default: break;
  }
}

void keyboardKeyPressed(u8 key, i32 x, i32 y)
{
  bKeyboardKeyState[key] = true;
}

void keyboardKeyReleased(u8 key, i32 x, i32 y)
{
  /*
  *   TODO:  This function will be used later for something.
  *          or be totally removed since it appears to do
  *          nothing useful.
  */

  bKeyboardKeyState[key] = false;
}

