#ifndef CAMERA_HEADER_FILE
#define CAMERA_HEADER_FILE

#include "matrix.h"

/* Same as Vector3f, but with pitch/yaw rotation */
struct Camera
{
  struct Matrix3f pos;
  struct Rotation3f rot[2];
  struct Acceleration3f vel;
};

void configureCamera(void);
void setCameraValue(u8 type, struct Camera camera);
struct Camera getCameraValue(u8 type);
void callCameraMovement(struct Camera camera);

#endif

