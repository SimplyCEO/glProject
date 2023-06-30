#include "types.h"

#include "gl/main.h"

void createBlock(float colour[])
{
  float lightShade[3] = {colour[0]+0.1f, colour[1]+0.1f, colour[2]+0.1f };
  float darkShade[3]  = {colour[0]-0.1f, colour[1]-0.1f, colour[2]-0.1f };

  /* Front/Back */
  glBegin(GL_QUADS);
  glColor3f(colour[0], colour[1], colour[2]);
  glVertex3f(-0.5f, -0.5f,  0.5f);
  glVertex3f(-0.5f,  0.5f,  0.5f);
  glVertex3f( 0.5f,  0.5f,  0.5f);
  glVertex3f( 0.5f, -0.5f,  0.5f);
  glEnd();

  /* Top/Bottom */
  glBegin(GL_QUADS);
  glColor3f(lightShade[0], lightShade[1], lightShade[2]);
  glVertex3f(-0.5f,  0.5f, -0.5f);
  glVertex3f(-0.5f,  0.5f,  0.5f);
  glVertex3f( 0.5f,  0.5f,  0.5f);
  glVertex3f( 0.5f,  0.5f, -0.5f);
  glEnd();

  /* Left/Right */
  glBegin(GL_QUADS);
  glColor3f(darkShade[0], darkShade[1], darkShade[2]);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f,  0.5f);
  glVertex3f(-0.5f,  0.5f,  0.5f);
  glVertex3f(-0.5f,  0.5f, -0.5f);
  glEnd();
}
