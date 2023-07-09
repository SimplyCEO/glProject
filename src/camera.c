#include "camera.h"

#include "gl/main.h"

#include "input/mouse.h"

#include "tools/math.h"

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
    stCamera[i].vel.fw        =  0.0f;
    stCamera[i].vel.bw        =  0.0f;
    stCamera[i].vel.lt        =  0.0f;
    stCamera[i].vel.rt        =  0.0f;
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

  struct Rotation3f angleX = getCameraAngle(0);
  struct Rotation3f angleY = getCameraAngle(1);

  camera.rot[0].face.x = angleX.face.x;
  camera.rot[0].face.y = angleX.face.y;
  camera.rot[0].face.z = angleX.face.z;
  camera.rot[0].deg    = (angleX.deg)*(camera.rot[0].face.y);

  camera.rot[1].face.x = angleY.face.x;
  camera.rot[1].face.y = angleY.face.y;
  camera.rot[1].face.z = angleY.face.z;
  camera.rot[1].deg    = (angleY.deg)*(camera.rot[1].face.x);

  float posX = camera.pos.x;
  float posY = camera.pos.y;
  float posZ = camera.pos.z;
  float accelFw[2] = {camera.vel.fw, camera.vel.fw};

  for(i=0; i<1; i++)
  {
    float rot = camera.rot[i].deg;
    switch((int)rot)
    {
      case -361: camera.rot[i].deg += 360; break;
      case 361:  camera.rot[i].deg -= 360; break;
      default: break;
    }

    u8 quadrant = 1;
    switch((int)rot)
    {
      case -360 ... -271: rot += 540; break;
      case -270 ... -181: quadrant = 2; rot += 360; break;
      case -180 ... -91 : quadrant = 3; rot += 180; break;
      case -90  ... -1  : quadrant = 4; rot += 90; break;
      case  0   ...  90 : break;
      case  91  ...  180: quadrant = 2; rot -= 90; break;
      case  181 ...  270: quadrant = 3; rot -= 180; break;
      case  271 ...  360: quadrant = 4; rot -= 270; break;
      default: break;
    }

    float range = findRangef(rot, 90);
    accelFw[0] *= range/100000;
    accelFw[1] *= range/100000;

    switch(quadrant)
    {
      case 1: accelFw[0] *= -1; break;
      case 2: accelFw[0] *= -1; accelFw[1] *= -1; break;
      case 3: accelFw[1] *= -1; break;
      default: break;
    }

    glRotatef(camera.rot[i].deg, camera.rot[i].face.x,
                                 camera.rot[i].face.y,
                                 camera.rot[i].face.z);
  }

  posX += accelFw[0];
  posZ += accelFw[1];
  glTranslatef(posX, posY, posZ);

  camera.pos.x = posX;
  camera.pos.y = posY;
  camera.pos.z = posZ;

  setCameraValue(0, camera);
}
