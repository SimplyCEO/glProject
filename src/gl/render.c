#include "types.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/structures.h"
#include "gl/draw.h"
#include "gl/input.h"

#include <stdio.h>

struct Camera camera;
float drawColour[3] = {0.2f, 0.2f, 0.8f};

void configureCamera(void)
{
  camera.y = 0.0f;
  camera.x = 0.0f;
  camera.z = -5.0f;
}

void display(void)
{
  handleKeys(&camera, drawColour);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(camera.x, camera.y, camera.z);

  primitiveDraw(drawColour);

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

int initializeGL(struct Render render)
{
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(render.width, render.height);
  glutCreateWindow(render.name);

  return 0;
}
