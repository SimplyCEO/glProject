#ifndef TEXTURE_HEADER_FILE
#define TEXTURE_HEADER_FILE

#include "types.h"
#include "gl/main.h"

GLuint loadTexture(const char *filename, i32 width, i32 height);
void freeTexture(GLuint texture);

#endif

