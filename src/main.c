#include "types.h"
#include "tools/debug.h"
#include "tools/getopt.h"
#include "gl/render.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  checkGLFW();

  u8 i;
  bool bFullscreen = false;

  struct Render main;
  main.width = WINDOW_WIDTH;
  main.height = WINDOW_HEIGHT;
  strcpy(main.name, "glProject");

  for(i=0; i<argc-1; i++)
  {
    u8 got;

    got = getopt(argv[i+1], "-F", "--fullscreen");
    bFullscreen = got;
  }
  switch(bFullscreen)
  {
    case 0: main.window = glfwCreateWindow(main.width, main.height, main.name, NULL, NULL); break;
    case 1: main.window = glfwCreateWindow(main.width, main.height, main.name, glfwGetPrimaryMonitor(), NULL); break;
    default: break;
  }

  handleRender(main);

  glfwDestroyWindow(main.window);
  glfwTerminate();
  debug("glProject closed.", 0);
  return 0;
}
