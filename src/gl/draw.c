#include "types.h"
#include "object.h"

#include "gl/main.h"

bool bDrawWireframe = false;

void drawWireframe(void)
{
  bDrawWireframe = !bDrawWireframe;
}

void createMeshPlane(struct Object3 object)
{
  u16 i, ii;
  float *colour = object.colour;
  float alpha = object.alpha;

  for(i=0; i<MAX_VERTEX3_SIZE; i++)
  {
    switch(bDrawWireframe)
    {
      case 0:
      {
        glBegin(GL_TRIANGLES);
        glColor4f(colour[0], colour[1], colour[2], alpha);
        break;
      }
      default:
      {
        glBegin(GL_LINE_LOOP);
        glColor4f(0.1f, 0.8f, 0.1f, 1.0f);
        break;
      }
    }

    for(ii=0; ii<3; ii++)
    {
      float posX = object.mesh.vertex[i].pos[ii].x;
      float posY = object.mesh.vertex[i].pos[ii].y;
      float posZ = object.mesh.vertex[i].pos[ii].z;
      glVertex4f(posX, posY, posZ, alpha);
    }

    glEnd();
  }
}

void createObject(u8 type, u16 id)
{
  glPushMatrix();

  struct Object3 object = getObjectData(type, id);

  object.vec.rot.deg += 1.0f;
  glTranslatef(object.vec.pos.x, object.vec.pos.y, object.vec.pos.z);
  glRotatef(object.vec.rot.deg, object.vec.rot.face.x,
                                object.vec.rot.face.y,
                                object.vec.rot.face.z);

  switch((int)object.vec.rot.deg)
  {
    case -361: object.vec.rot.deg += 360; break;
    case 361:  object.vec.rot.deg -= 360; break;
    default: break;
  }

  createMeshPlane(object);
  setObjectData(object);

  glPopMatrix();
}
