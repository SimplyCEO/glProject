#include "types.h"
#include "gl/main.h"

void primitiveDraw(void)
{
  glColor3f(0.0f, 0.0f, 1.0f);

  glBegin(GL_QUADS);
  glVertex3f(-0.5f, -0.5f, 0.0f);
  glVertex3f(-0.5f, 0.5f, 0.0f);
  glVertex3f(0.5f, 0.5f, 0.0f);
  glVertex3f(0.5f, -0.5f, 0.0f);

  glEnd();
}
