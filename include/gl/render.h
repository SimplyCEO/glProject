#ifndef RENDER_HEADER_FILE
#define RENDER_HEADER_FILE

#include "gl/main.h"

struct Window
{
	GLFWwindow *window;
	i32 width;
	i32 height;
	char name[10];
};

int checkGLFW(void);
int handleWindow(GLFWwindow *window);

#endif

