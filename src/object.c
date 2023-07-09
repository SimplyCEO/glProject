#include "object.h"

#include <string.h>

struct Object3f stObject[4][MAX_OBJECTS];
bool bObjectRegistration[4][MAX_OBJECTS];

void registerObjects(enum ObjectType type)
{
  stObject[type][0].type = 0;
  stObject[type][0].id = 0;
  /* Face */
  stObject[type][0].mesh.node[0].pos[0]  = (struct Matrix3f){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[0].pos[1]  = (struct Matrix3f){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[0].pos[2]  = (struct Matrix3f){ 0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[1].pos[0]  = (struct Matrix3f){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[1].pos[1]  = (struct Matrix3f){ 0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[1].pos[2]  = (struct Matrix3f){ 0.5f, -0.5f,  0.5f};
  /* Back */
  stObject[type][0].mesh.node[2].pos[0]  = (struct Matrix3f){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[2].pos[1]  = (struct Matrix3f){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[2].pos[2]  = (struct Matrix3f){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[3].pos[0]  = (struct Matrix3f){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[3].pos[1]  = (struct Matrix3f){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[3].pos[2]  = (struct Matrix3f){-0.5f, -0.5f, -0.5f};
  /* Right */
  stObject[type][0].mesh.node[4].pos[0]  = (struct Matrix3f){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[4].pos[1]  = (struct Matrix3f){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[4].pos[2]  = (struct Matrix3f){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[5].pos[0]  = (struct Matrix3f){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[5].pos[1]  = (struct Matrix3f){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[5].pos[2]  = (struct Matrix3f){ 0.5f,  0.5f,  0.5f};
  /* Left */
  stObject[type][0].mesh.node[5].pos[0]  = (struct Matrix3f){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[5].pos[1]  = (struct Matrix3f){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[5].pos[2]  = (struct Matrix3f){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[6].pos[0]  = (struct Matrix3f){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[6].pos[1]  = (struct Matrix3f){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[6].pos[2]  = (struct Matrix3f){-0.5f, -0.5f,  0.5f};
  /* Top */
  stObject[type][0].mesh.node[7].pos[0]  = (struct Matrix3f){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[7].pos[1]  = (struct Matrix3f){-0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[7].pos[2]  = (struct Matrix3f){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[8].pos[0]  = (struct Matrix3f){-0.5f,  0.5f,  0.5f};
  stObject[type][0].mesh.node[8].pos[1]  = (struct Matrix3f){ 0.5f,  0.5f, -0.5f};
  stObject[type][0].mesh.node[8].pos[2]  = (struct Matrix3f){ 0.5f,  0.5f,  0.5f};
  /* Bottom */
  stObject[type][0].mesh.node[9].pos[0]  = (struct Matrix3f){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[9].pos[1]  = (struct Matrix3f){-0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[9].pos[2]  = (struct Matrix3f){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[10].pos[0] = (struct Matrix3f){-0.5f, -0.5f, -0.5f};
  stObject[type][0].mesh.node[10].pos[1] = (struct Matrix3f){ 0.5f, -0.5f,  0.5f};
  stObject[type][0].mesh.node[10].pos[2] = (struct Matrix3f){ 0.5f, -0.5f, -0.5f};
  stObject[type][0].vec.pos = (struct Matrix3f){0.0f, 0.0f, -1.0f};
  stObject[type][0].vec.rot = (struct Rotation3f){0.0f, {0.0f, 1.0f, 0.0f}};
  memcpy(stObject[type][0].colour, (float[3]){1.0f, 1.0f, 1.0f}, sizeof stObject[type][0].colour);
  stObject[type][0].alpha = 1.0f;
  strcpy(stObject[type][0].texture.name, "assets/buffer.bmp");
  stObject[type][0].texture.size.x = 256.0f;
  stObject[type][0].texture.size.y = 256.0f;
  bObjectRegistration[type][0] = true;

  /* Simple terrain */
  stObject[type][1].type = 0;
  stObject[type][1].id = 1;
  /* Bottom */
  stObject[type][1].mesh.node[0].pos[0] = (struct Matrix3f){-15.0f,  0.0f, -15.0f};
  stObject[type][1].mesh.node[0].pos[1] = (struct Matrix3f){-15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.node[0].pos[2] = (struct Matrix3f){ 15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.node[1].pos[0] = (struct Matrix3f){-15.0f,  0.0f, -15.0f};
  stObject[type][1].mesh.node[1].pos[1] = (struct Matrix3f){ 15.0f,  0.0f,  15.0f};
  stObject[type][1].mesh.node[1].pos[2] = (struct Matrix3f){ 15.0f,  0.0f, -15.0f};
  stObject[type][1].vec.pos = (struct Matrix3f){0.0f, 0.0f, 0.0f};
  stObject[type][1].vec.rot = (struct Rotation3f){0.0f, {0.0f, 0.0f, 0.0f}};
  memcpy(stObject[type][1].colour, (float[3]){1.0f, 1.0f, 1.0f}, sizeof stObject[type][0].colour);
  stObject[type][1].alpha = 1.0f;
  strcpy(stObject[type][1].texture.name, "assets/terrain.bmp");
  stObject[type][1].texture.size.x = 256.0f;
  stObject[type][1].texture.size.y = 256.0f;
  bObjectRegistration[type][1] = true;
}

int returnObject(enum ObjectType type, u32 id)
{
  return bObjectRegistration[type][id];
}

u8 addObjectData(struct Object3f object)
{
  u32 i = 0;

  switch(object.type)
  {
    case CUBE:
    {
      for(i=0; i<MAX_OBJECTS; i++)
      {
        switch(bObjectRegistration[object.type][i])
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

struct Object3f getObjectData(enum ObjectType type, u32 id)
{
  switch(bObjectRegistration[type][id])
  {
    case 1:  return stObject[type][id];
    default: break;
  }

  return stObject[0][0];
}

void setObjectData(struct Object3f object)
{
  stObject[object.type][object.id] = object;
}

