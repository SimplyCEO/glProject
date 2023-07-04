#include "types.h"
#include "object.h"

#include "gl/renderer.h"

#include "input/keyboard.h"
#include "input/mouse.h"

void registerEvents(void)
{
  registerObjects(0);
  configureKeyboardKeys();
  configureMouseKeys();
  configureCamera();
}
