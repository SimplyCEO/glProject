#include "types.h"
#include "matrix.h"

#include "gl/main.h"

#include <math.h>

struct MouseMap
{
  struct Matrix2 pos[3];
  i32 lmb;
  i32 mmb;
  i32 rmb;
}mouseInput;

i32 bMouseKeyState[16];
float mouseDragX = 0.0f,
      mouseDragY = 0.0f,
      mouseSensitivityX = 0.2f,
      mouseSensitivityY = 0.2f,
      mouseSensitivityZ = 0.3f;

void configureMouseKeys(void)
{
  mouseInput.pos[0].x = DEFAULT_WINDOW_WIDTH/2;
  mouseInput.pos[0].y = DEFAULT_WINDOW_HEIGHT/2;
  mouseInput.lmb = 0x0000;
  mouseInput.mmb = 0x0001;
  mouseInput.rmb = 0x0002;
}

bool returnMouseKeyState(u8 key)
{
  return bMouseKeyState[key];
}

struct Rotation3 getCameraAngle(u8 axis)
{
  struct Rotation3 rotation = {0.0f, {0.0f, 0.0f, 0.0f}};

  switch(axis)
  {
    case 0: rotation = (struct Rotation3){mouseDragX, {0.0f, mouseSensitivityY, 0.0f}}; break;
    default: rotation = (struct Rotation3){mouseDragY, {mouseSensitivityX, 0.0f, 0.0f}}; break;
  }

  return rotation;
}

void calculateAngle(struct Matrix2 pos)
{
  float zeroX = mouseInput.pos[0].x;
  float zeroY = mouseInput.pos[0].y;

  mouseDragX = pos.x - zeroX;
  mouseDragY = pos.y - zeroY;
}

void mouseMovement(i32 x, i32 y)
{
  mouseInput.pos[1].x = x;
  mouseInput.pos[1].y = y;

  calculateAngle(mouseInput.pos[1]);

  mouseInput.pos[1].x = mouseInput.pos[0].x;
  mouseInput.pos[1].y = mouseInput.pos[0].y;
}

void mouseKeyEvent(i32 key, i32 state, i32 x, i32 y)
{
  bMouseKeyState[key] = state;
}

