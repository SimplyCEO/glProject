#ifndef INPUT_MOUSE_HEADER_FILE
#define INPUT_MOUSE_HEADER_FILE

void configureMouseKeys(void);
bool returnMouseKeyState(u8 key);
struct Rotation3f getCameraAngle(u8 axis);
void mouseMovement(i32 x, i32 y);
void mouseKeyEvent(i32 key, i32 state, i32 x, i32 y);

#endif

