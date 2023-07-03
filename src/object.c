#include "types.h"
#include "object.h"

#include <string.h>

struct Object3 stObject[MAX_OBJECTS];
bool bObjectRegistration[4][MAX_OBJECTS];

void registerObjects(u8 type)
{
  switch(type)
  {
    case 0:
    {
      stObject[0].type = 1;
      stObject[0].id = 0;
      /* Face */
      stObject[0].mesh.vertex[0].pos[0] = (struct Matrix3){-0.5f, -0.5f, 0.5f};
      stObject[0].mesh.vertex[0].pos[1] = (struct Matrix3){-0.5f,  0.5f, 0.5f};
      stObject[0].mesh.vertex[0].pos[2] = (struct Matrix3){ 0.5f,  0.5f, 0.5f};
      stObject[0].mesh.vertex[1].pos[0] = (struct Matrix3){-0.5f, -0.5f, 0.5f};
      stObject[0].mesh.vertex[1].pos[1] = (struct Matrix3){ 0.5f,  0.5f, 0.5f};
      stObject[0].mesh.vertex[1].pos[2] = (struct Matrix3){ 0.5f, -0.5f, 0.5f};
      stObject[0].vec.pos = (struct Matrix3){0.0f, 0.0f, -5.0f};
      memcpy(stObject[0].colour, (float[]){0.3f, 0.3f, 0.6f}, sizeof stObject[0].colour);
      stObject[0].alpha = 1.0f;
      bObjectRegistration[0][0] = true;
    }
  }
}

int returnObject(u8 type, u8 id)
{
  return bObjectRegistration[type][id];
}

u8 addObjectData(struct Object3 object)
{
  enum ObjectType type = object.type;
  u16 i = 0;

  switch(type)
  {
    case CUBE:
    {
      for(i=0; i<MAX_OBJECTS; i++)
      {
        switch(bObjectRegistration[type][i])
        {
          case 1: break;
          default:
          {
            u16 id = object.id;
            if(id != i)
            {
              id = i;
            }
            return 0;
          }
        }
      }
      break;
    }
    default: break;
  }

  return 1;
}

struct Object3 getObjectData(u8 type, u8 id)
{
  switch(type)
  {
    case 0:
    {
      switch(bObjectRegistration[type][id])
      {
        case 1: return stObject[id];
        default: break;
      }
      break;
    }
    default: break;
  }

  return stObject[0];
}

