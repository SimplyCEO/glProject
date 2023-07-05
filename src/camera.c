#include "types.h"
#include "camera.h"

#include "gl/main.h"

#include "input/mouse.h"

struct Camera stCamera[3];

void configureCamera(void)
{
  u8 i;

  for(i=0; i<4; i++)
  {
    stCamera[i].pos.x         =  0.0f;
    stCamera[i].pos.y         = -0.7f;
    stCamera[i].pos.z         = -5.0f;
    stCamera[i].rot[0].face.x =  0.0f;
    stCamera[i].rot[0].face.y =  0.0f;
    stCamera[i].rot[0].face.z =  0.0f;
    stCamera[i].rot[0].deg    =  0.0f;
    stCamera[i].rot[1].face.x =  0.0f;
    stCamera[i].rot[1].face.y =  0.0f;
    stCamera[i].rot[1].face.z =  0.0f;
    stCamera[i].rot[1].deg    =  0.0f;
  }
}

void setCameraValue(u8 type, struct Camera camera)
{
  stCamera[type] = camera;
}

struct Camera getCameraValue(u8 type)
{
  switch(type)
  {
    case 0 ... 3: break;
    default: /* TODO: Throw exception */ break;
  }

  return stCamera[type];
}

void callCameraMovement(struct Camera camera)
{
  u8 i;

  struct Rotation3 angleX = getCameraAngle(0);
  struct Rotation3 angleY = getCameraAngle(1);

  camera.rot[0].face.x = angleX.face.x;
  camera.rot[0].face.y = angleX.face.y;
  camera.rot[0].face.z = angleX.face.z;
  camera.rot[0].deg    = (angleX.deg)*(camera.rot[0].face.y);
  /*
  camera.rot[1].face.x = angleY.face.x;
  camera.rot[1].face.y = angleY.face.y;
  camera.rot[1].face.z = angleY.face.z;
  camera.rot[1].deg    = (angleY.deg)*(camera.rot[1].face.x);
  */

  for(i=0; i<2; i++)
  {
    switch((int)camera.rot[i].deg)
    {
      case -361: camera.rot[i].deg += 360; break;
      case 361:  camera.rot[i].deg -= 360; break;
      default: break;
    }
    glRotatef(camera.rot[i].deg, camera.rot[i].face.x,
                                 camera.rot[i].face.y,
                                 camera.rot[i].face.z);
  }
  glTranslatef(camera.pos.x, camera.pos.y, camera.pos.z);

  setCameraValue(0, camera);
}
