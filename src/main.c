#include "types.h"
#include "register.h"

#include "tools/debug.h"
#include "tools/getopt.h"

#include "gl/main.h"
#include "gl/structures.h"
#include "gl/input.h"
#include "gl/render.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);

  u8 i;
  bool bFullscreen = false;

  struct Render main;
  main.width = DEFAULT_WINDOW_WIDTH;
  main.height = DEFAULT_WINDOW_HEIGHT;
  strcpy(main.name, "glProject");

  registerObjects();
  configureKeys();
  configureCamera();

  for(i=0; i<argc-1; i++)
  {
    u8 got;

    got = getopt(argv[i+1], "-F", "--fullscreen");
    bFullscreen = got;
  }

  initializeGL(main);

  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);

  glutKeyboardFunc(keyPressed);
  glutKeyboardUpFunc(keyReleased);

  glutMainLoop();

  debug("glProject closed.", 0);
  return 0;
}
