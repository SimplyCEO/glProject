#include "types.h"
#include "object.h"

#include <string.h>

struct Object3 stObject[4][MAX_OBJECTS];
bool bObjectRegistration[4][MAX_OBJECTS];

void registerObjects(u8 type)
{
  stObject[type][0].type = 0;
  stObject[type][0].id = 0;
  /* Face */
  stObject[type][0].mesh.vertex[0].pos[0]  = (struct Matrix3){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[0].pos[1]  = (struct Matrix3){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[0].pos[2]  = (struct Matrix3){ 0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[1].pos[0]  = (struct Matrix3){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[1].pos[1]  = (struct Matrix3){ 0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[1].pos[2]  = (struct Matrix3){ 0.5f, -0.5f,  0.5f};
  /* Back */
  stObject[type][0].mesh.vertex[2].pos[0]  = (struct Matrix3){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[2].pos[1]  = (struct Matrix3){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[2].pos[2]  = (struct Matrix3){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[3].pos[0]  = (struct Matrix3){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[3].pos[1]  = (struct Matrix3){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[3].pos[2]  = (struct Matrix3){-0.5f, -0.5f, -0.5f};
  /* Right */
  stObject[type][0].mesh.vertex[4].pos[0]  = (struct Matrix3){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[4].pos[1]  = (struct Matrix3){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[4].pos[2]  = (struct Matrix3){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[5].pos[0]  = (struct Matrix3){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[5].pos[1]  = (struct Matrix3){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[5].pos[2]  = (struct Matrix3){ 0.5f,  0.5f,  0.5f};
  /* Left */
  stObject[type][0].mesh.vertex[5].pos[0]  = (struct Matrix3){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[5].pos[1]  = (struct Matrix3){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[5].pos[2]  = (struct Matrix3){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[6].pos[0]  = (struct Matrix3){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[6].pos[1]  = (struct Matrix3){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[6].pos[2]  = (struct Matrix3){-0.5f, -0.5f,  0.5f};
  /* Top */
  stObject[type][0].mesh.vertex[7].pos[0]  = (struct Matrix3){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[7].pos[1]  = (struct Matrix3){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[7].pos[2]  = (struct Matrix3){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[8].pos[0]  = (struct Matrix3){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.vertex[8].pos[1]  = (struct Matrix3){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.vertex[8].pos[2]  = (struct Matrix3){ 0.5f,  0.5f,  0.5f};
  /* Bottom */
  stObject[type][0].mesh.vertex[9].pos[0]  = (struct Matrix3){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[9].pos[1]  = (struct Matrix3){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[9].pos[2]  = (struct Matrix3){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[10].pos[0] = (struct Matrix3){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.vertex[10].pos[1] = (struct Matrix3){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.vertex[10].pos[2] = (struct Matrix3){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].vec.pos = (struct Matrix3){0.0f, 0.0f, -1.0f};
  stObject[type][0].vec.rot = (struct Rotation3){0.0f, {0.0f, 1.0f, 0.0f}};
  memcpy(stObject[type][0].colour, (float[3]){1.0f, 1.0f, 1.0f}, sizeof stObject[type][0].colour);
  stObject[type][0].alpha = 1.0f;
  strcpy(stObject[type][0].texture.name, "assets/buffer.bmp");
  stObject[type][0].texture.sizeX = 256;
  stObject[type][0].texture.sizeY = 256;
  bObjectRegistration[type][0] = true;

  /* Simple terrain */
  stObject[type][1].type = 0;
  stObject[type][1].id = 1;
  /* Bottom */
  stObject[type][1].mesh.vertex[0].pos[0] = (struct Matrix3){-15.0f,  0.0f, -15.0f};
  stObject[type][1].mesh.vertex[0].pos[1] = (struct Matrix3){-15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.vertex[0].pos[2] = (struct Matrix3){ 15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.vertex[1].pos[0] = (struct Matrix3){-15.0f,  0.0f, -15.0f};
  stObject[type][1].mesh.vertex[1].pos[1] = (struct Matrix3){ 15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.vertex[1].pos[2] = (struct Matrix3){ 15.0f,  0.0f, -15.0f};
  stObject[type][1].vec.pos = (struct Matrix3){0.0f, 0.0f, 0.0f};
  stObject[type][1].vec.rot = (struct Rotation3){0.0f, {0.0f, 0.0f, 0.0f}};
  memcpy(stObject[type][1].colour, (float[3]){1.0f, 1.0f, 1.0f}, sizeof stObject[type][0].colour);
  stObject[type][1].alpha = 1.0f;
  strcpy(stObject[type][1].texture.name, "assets/terrain.bmp");
  stObject[type][1].texture.sizeX = 256;
  stObject[type][1].texture.sizeY = 256;
  bObjectRegistration[type][1] = true;
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
  switch(bObjectRegistration[type][id])
  {
    case 1:  return stObject[type][id];
    default: break;
  }

  return stObject[0][0];
}

void setObjectData(struct Object3 object)
{
  stObject[object.type][object.id] = object;
}

