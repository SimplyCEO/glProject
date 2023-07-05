#ifndef INPUT_KEYBOARD_HEADER_FILE
#define INPUT_KEYBOARD_HEADER_FILE

#include "camera.h"

void configureKeyboardKeys(void);
int returnKeyboardKey(u8 key);
void keyboardKeyPressed(u8 key, i32 x, i32 y);
void keyboardKeyReleased(u8 key, i32 x, i32 y);
void handleKeyboardKeys(struct Camera *camera);

#endif

