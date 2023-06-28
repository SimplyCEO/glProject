#include "types.h"

#include "tools/debug.h"

#include "gl/main.h"
#include "gl/structures.h"
#include "gl/draw.h"
#include "gl/input.h"

void display(void)
{
  handleKeys();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -5.0f);

  primitiveDraw();

  glFlush();
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
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(render.width, render.height);
  glutCreateWindow(render.name);

  return 0;
}
