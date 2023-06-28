#include "types.h"
#include "gl/main.h"

void primitiveDraw(float colour[])
{
  glColor3f(colour[0], colour[1], colour[2]);

  glBegin(GL_QUADS);
  glVertex3f(-0.5f, -0.5f, 0.0f);
  glVertex3f(-0.5f, 0.5f, 0.0f);
  glVertex3f(0.5f, 0.5f, 0.0f);
  glVertex3f(0.5f, -0.5f, 0.0f);

  glEnd();
}
