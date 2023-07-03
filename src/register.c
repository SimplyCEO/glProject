#include "types.h"
#include "object.h"

#include "gl/renderer.h"

#include "input/keyboard.h"

void registerEvents(void)
{
  registerObjects(0);
  configureKeys();
  configureCamera();
}
