#include "types.h"
#include "register.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/structures.h"

bool keyStates[256];
bool bTransformKeyDelay;
struct KeyMap input;
u16 delay = 0;

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
  return keyStates[key];
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

  switch(delay)
  {
    case 100:
    {
      delay = 0;
      bTransformKeyDelay = false;
      break;
    }
    default: break;
  }
  delay += 1;

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
      keyStates[input.sprint[0]] = false;
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
      keyStates[input.sprint[1]] = false;
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
      keyStates[input.sprint[2]] = false;
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
      keyStates[input.sprint[3]] = false;
      break;
    }
    case 1: camera->x -= fSprint*0.01f; break;
    default: break;
  }

  switch(transformKey)
  {
    case 1:
    {
      switch(bTransformKeyDelay)
      {
        case 1: break;
        default:
        {
          struct Object object = {1, 0, {-(camera->x), -(camera->y), -(camera->z)-5}, 1.0f, {0.7f, 0.1f, 0.1f}, 1.0f};
          bool bIsObjectCreated = addObjectData(&object);
          switch(bIsObjectCreated)
          {
            case 1: debug("Could not create object. MAX size reached.\n", 3); break;
            default: break;
          }
          bTransformKeyDelay = true;
          debug("Object created.", 1);
          break;
        }
      }
      break;
    }
    default: break;
  }
}

void keyPressed(u8 key, i32 x, i32 y)
{
  keyStates[key] = true;
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

