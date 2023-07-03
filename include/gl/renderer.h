#ifndef GL_RENDERER_HEADER_FILE
#define GL_RENDERER_HEADER_FILE

struct Renderer
{
  i16  width;
  i16  height;
  char name[10];
};

struct Camera
{
  float x;
  float y;
  float z;
  float faceX;
  float faceY;
  float faceZ;
  float angle;
};

void configureCamera(void);
void display(void);
void reshape(i32 width, i32 height);
int initializeGL(struct Renderer window);

#endif

