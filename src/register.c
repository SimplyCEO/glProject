#include "types.h"
#include "object.h"

#include "gl/structures.h"
#include "gl/input.h"
#include "gl/render.h"

void registerEvents(void)
{
  registerObjects(0);
  configureKeys();
  configureCamera();
}
