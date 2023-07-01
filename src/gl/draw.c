#include "types.h"
#include "register.h"

#include "gl/main.h"

struct Object object;

void createObject(u8 type, u8 id)
{
  object = getObjectData(type, id);

  float size = object.size*0.5f;
  float lightShade[3] = {object.colour[0]+0.1f, object.colour[1]+0.1f, object.colour[2]+0.1f };
  float darkShade[3]  = {object.colour[0]-0.1f, object.colour[1]-0.1f, object.colour[2]-0.1f };

  switch(object.type)
  {
    case CUBE:
    {
      /* Front/Back */
      glBegin(GL_QUADS);
      glColor3f(object.colour[0], object.colour[1], object.colour[2]);
      glVertex3f(-(size), -(size),  (size));
      glVertex3f(-(size),  (size),  (size));
      glVertex3f( (size),  (size),  (size));
      glVertex3f( (size), -(size),  (size));
      glEnd();

      /* Top/Bottom */
      glBegin(GL_QUADS);
      glColor3f(lightShade[0], lightShade[1], lightShade[2]);
      glVertex3f(-(size),  (size), -(size));
      glVertex3f(-(size),  (size),  (size));
      glVertex3f( (size),  (size),  (size));
      glVertex3f( (size),  (size), -(size));
      glEnd();

      /* Left/Right */
      glBegin(GL_QUADS);
      glColor3f(darkShade[0], darkShade[1], darkShade[2]);
      glVertex3f(-(size), -(size), -(size));
      glVertex3f(-(size), -(size),  (size));
      glVertex3f(-(size),  (size),  (size));
      glVertex3f(-(size),  (size), -(size));
      glEnd();
    }
  }
}
