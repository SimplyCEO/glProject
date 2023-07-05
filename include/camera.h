#ifndef CAMERA_HEADER_FILE
#define CAMERA_HEADER_FILE

#include "matrix.h"

struct Camera
{
  struct Matrix3 pos;
  struct Rotation3 rot[2];
};

void configureCamera(void);
void setCameraValue(u8 type, struct Camera camera);
struct Camera getCameraValue(u8 type);
void callCameraMovement(struct Camera camera);

#endif

