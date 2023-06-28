#include "types.h"

#include "gl/main.h"
#include "gl/structures.h"

bool keyStates[256];
struct KeyMap input;

/* Configure keys ASCII/DEC */
void configureKeys(void)
{
  input.pause     = 27;
  input.up        = 'w';
  input.down      = 's';
  input.left      = 'a';
  input.right     = 'd';
  input.transform = 32;
}

int returnKey(u8 key)
{
  return keyStates[key];
}

void handleKeys(struct Camera *camera, float colour[])
{
  bool pauseKey     = returnKey(input.pause);
  bool upKey        = returnKey(input.up);
  bool downKey      = returnKey(input.down);
  bool leftKey      = returnKey(input.left);
  bool rightKey     = returnKey(input.right);
  bool transformKey = returnKey(input.transform);

  switch(pauseKey)
  {
    case 1: exit(0); break;
    default: break;
  }

  switch(upKey)
  {
    case 1: camera->y += 0.0005f; break;
    default: break;
  }

  switch(downKey)
  {
    case 1: camera->y -= 0.0005f; break;
    default: break;
  }

  switch(leftKey)
  {
    case 1: camera->x -= 0.0005f; break;
    default: break;
  }

  switch(rightKey)
  {
    case 1: camera->x += 0.0005f; break;
    default: break;
  }

  switch(transformKey)
  {
    case 1: colour[2] = 0.2f; break;
    default: colour[2] = 0.8f; break;
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

