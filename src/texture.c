#include "texture.h"

#include <stdio.h>

GLuint loadTexture(const char *filename, i32 width, i32 height)
{
  GLuint texture;
  i32 size = width*height*3;
  u8 *data;
  char buffer[2];
  FILE *file;

  file = fopen(filename, "rb");
  fgets(buffer, 2, file);
  switch(buffer[0])
  {
    case 0 ... 127: break;
    default: return 1;
  }

  data = (u8 *)malloc(size);

  fread(data, size, 1, file);
  fclose(file);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  free(data);
  return texture;
}

void freeTexture(GLuint texture)
{
  glDeleteTextures(1, &texture);
}

