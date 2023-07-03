#include "types.h"
#include "object.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/draw.h"
#include "gl/renderer.h"

#include "input/keyboard.h"

struct Camera camera;

void configureCamera(void)
{
  camera.y      = 0.0f;
  camera.x      = 0.0f;
  camera.z      = -5.0f;
  camera.faceX  = 0.0f;
  camera.faceY  = 0.0f;
  camera.faceZ  = 0.0f;
  camera.angle  = 0.0f;
}

void display(void)
{
  enum ObjectType type = 0;
  u16 i;

  handleKeys(&camera);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(camera.x, camera.y, camera.z);
  
  switch((int)camera.angle)
  {
    case -361:
    {
      camera.angle += 360;
      break;
    }
    case 361:
    {
      camera.angle -= 360;
      break;
    }
    default: break;
  }
  glRotatef(camera.angle, camera.faceX, camera.faceY, camera.faceZ);
  
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
