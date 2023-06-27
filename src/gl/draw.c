#include "types.h"
#include "tools/debug.h"
#include "gl/render.h"

#include <string.h>

int drawVertex(float object,
               u32 VBO,
               u32 shaderProgram,
               u32 VAO,
               u32 EBO
               )
{
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(object), object, GL_STATIC_DRAW);

  return 0;
}
