#ifndef RENDER_HEADER_FILE
#define RENDER_HEADER_FILE

#include "gl/main.h"

struct Render
{
  GLFWwindow  *window;
  GLFWimage   icon[2];
  i32         width;
  i32         height;
  char        name[10];
};

int checkGLFW(void);
int handleRender(struct Render render);

#endif

