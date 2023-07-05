#include "types.h"
#include "object.h"
#include "camera.h"

#include "input/keyboard.h"
#include "input/mouse.h"

void registerEvents(void)
{
  registerObjects(0);
  configureKeyboardKeys();
  configureMouseKeys();
  configureCamera();
}
