#include "types.h"
#include "gl/main.h"

void keyCallback(GLFWwindow* window,
                  int key,
                  int scancode,
                  int action,
                  int mods
                  )
{
  switch(key)
  {
    case GLFW_KEY_ESCAPE:
      {
        switch(action)
        {
          case GLFW_PRESS: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
          default: break;
        }
      break;
      }
    default: break;
  }
}
