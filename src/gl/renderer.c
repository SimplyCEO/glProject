#include "types.h"
#include "object.h"
#include "camera.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/draw.h"
#include "gl/renderer.h"

#include "input/keyboard.h"
#include "input/mouse.h"

void display(void)
{
  enum ObjectType type = 0;
  struct Camera camera = getCameraValue(0);
  u16 i;

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glEnable(GL_BLEND);
  glEnable(GL_TEXTURE_2D);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  handleKeyboardKeys(&camera);
  callCameraMovement(camera);

  for(type=0; type<4; type++)
  {
    for(i=0; i<MAX_OBJECTS; i++)
    {
      bool bDoObjectExists = returnObject(type, i);

      switch(bDoObjectExists)
      {
        case 1:
        {
          createObject(type, i);
          break;
        }
        default: break;
      }
    }
  }

  glutSwapBuffers();
}

void reshape(i32 width, i32 height)
{
  u8 FOV = 60;
  double minRender = 1.0, maxRender = 100.0;
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOV, (GLfloat)width / (GLfloat)height, minRender, maxRender);
  glMatrixMode(GL_MODELVIEW);
}

int initializeGL(struct Renderer window)
{
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(window.width, window.height);
  glutCreateWindow(window.name);

  return 0;
}
