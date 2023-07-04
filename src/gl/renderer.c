#include "types.h"
#include "object.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/draw.h"
#include "gl/renderer.h"

#include "input/keyboard.h"
#include "input/mouse.h"

struct Camera camera;

void configureCamera(void)
{
  camera.pos.x         =  0.0f;
  camera.pos.y         = -0.7f;
  camera.pos.z         = -5.0f;
  camera.rot[0].face.x =  0.0f;
  camera.rot[0].face.y =  0.0f;
  camera.rot[0].face.z =  0.0f;
  camera.rot[0].deg    =  0.0f;
  camera.rot[1].face.x =  0.0f;
  camera.rot[1].face.y =  0.0f;
  camera.rot[1].face.z =  0.0f;
  camera.rot[1].deg    =  0.0f;
}

void display(void)
{
  enum ObjectType type = 0;
  u16 i;

  handleKeyboardKeys(&camera);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  struct Rotation3 angleX = getCameraAngle(0);
  struct Rotation3 angleY = getCameraAngle(1);

  camera.rot[0].face.x = angleX.face.x;
  camera.rot[0].face.y = angleX.face.y;
  camera.rot[0].face.z = angleX.face.z;
  camera.rot[0].deg = -(angleX.deg)*(camera.rot[0].face.y);
  camera.rot[1].face.x = angleY.face.x;
  camera.rot[1].face.y = angleY.face.y;
  camera.rot[1].face.z = angleY.face.z;
  camera.rot[1].deg = -(angleY.deg)*(camera.rot[1].face.x);

  for(i=0; i<2; i++)
  {
    switch((int)camera.rot[i].deg)
    {
      case -361: camera.rot[i].deg += 360; break;
      case 361: camera.rot[i].deg -= 360; break;
      default: break;
    }
    glRotatef(camera.rot[i].deg, camera.rot[i].face.x, camera.rot[i].face.y, camera.rot[i].face.z);
  }
  glTranslatef(camera.pos.x, camera.pos.y, camera.pos.z);
  
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
