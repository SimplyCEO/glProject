#include "types.h"
#include "register.h"

#include "gl/main.h"

struct Object object;

void createObject(u8 type, u8 id)
{
  object = getObjectData(type, id);

  float size = object.size*0.5f;
  float posX = object.pos.x;
  float posY = object.pos.y;
  float posZ = object.pos.z;
  float lightShade[3] = {object.colour[0]+0.1f, object.colour[1]+0.1f, object.colour[2]+0.1f };
  float darkShade[3]  = {object.colour[0]-0.1f, object.colour[1]-0.1f, object.colour[2]-0.1f };

  switch(object.type)
  {
    case CUBE:
    {
      /* Front/Back */
      glBegin(GL_QUADS);
      glColor4f(object.colour[0], object.colour[1], object.colour[2], object.alpha);
      glVertex4f(posX-(size), posY-(size), posZ+(size), object.alpha);
      glVertex4f(posX-(size), posY+(size), posZ+(size), object.alpha);
      glVertex4f(posX+(size), posY+(size), posZ+(size), object.alpha);
      glVertex4f(posX+(size), posY-(size), posZ+(size), object.alpha);
      glEnd();

      /* Top/Bottom */
      glBegin(GL_QUADS);
      glColor4f(lightShade[0], lightShade[1], lightShade[2], object.alpha);
      glVertex4f(posX-(size), posY+(size), posZ-(size), object.alpha);
      glVertex4f(posX-(size), posY+(size), posZ+(size), object.alpha);
      glVertex4f(posX+(size), posY+(size), posZ+(size), object.alpha);
      glVertex4f(posX+(size), posY+(size), posZ-(size), object.alpha);
      glEnd();

      /* Left/Right */
      glBegin(GL_QUADS);
      glColor4f(darkShade[0], darkShade[1], darkShade[2], object.alpha);
      glVertex4f(posX-(size), posY-(size), posZ-(size), object.alpha);
      glVertex4f(posX-(size), posY-(size), posZ+(size), object.alpha);
      glVertex4f(posX-(size), posY+(size), posZ+(size), object.alpha);
      glVertex4f(posX-(size), posY+(size), posZ-(size), object.alpha);
      glEnd();
    }
  }
}
