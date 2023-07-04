#include "types.h"
#include "register.h"

#include "tools/debug.h"
#include "tools/getopt.h"

#include "gl/main.h"
#include "gl/renderer.h"

#include "input/keyboard.h"
#include "input/mouse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  struct Renderer main;
  main.width = DEFAULT_WINDOW_WIDTH;
  main.height = DEFAULT_WINDOW_HEIGHT;
  strcpy(main.name, "glProject");

  registerEvents(); 

  /*
  u8 i;
  bool bFullscreen = false;
  for(i=0; i<argc-1; i++)
  {
    u8 got;

    got = getopt(argv[i+1], "-F", "--fullscreen");
    bFullscreen = got;
  }
  */

  initializeGL(main);

  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);

  glutKeyboardFunc(keyboardKeyPressed);
  glutKeyboardUpFunc(keyboardKeyReleased);

  glutMouseFunc(mouseKeyEvent);
  glutPassiveMotionFunc(mouseMovement);

  glutMainLoop();

  debug("glProject closed.", 0);
  return 0;
}
