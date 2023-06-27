#include "types.h"
#include "tools/debug.h"
#include "gl/render.h"
#include "gl/input.h"

int checkGLFW(void)
{
  bool bInitialized = glfwInit();

  switch (bInitialized)
  {
    case GLFW_FALSE:
      {
        debug("GLFW could not be initialized.", 3);
        return 1;
      }
    default:
      break;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);

  debug("GLFW initialized.", 1);
  return 0;
}

int handleRender(struct Render render)
{
  if (!render.window)
  {
    glfwTerminate();
    debug("Could not create window!", 3);
    return 1;
  }

  glfwMakeContextCurrent(render.window);
  glfwSetKeyCallback(render.window, keyCallback);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(render.window))
  {
    i32 width, height;

    glfwGetFramebufferSize(render.window, &width, &height);
    glViewport(0, 0, width, height);

    glfwSwapBuffers(render.window);
    glfwPollEvents();
  }

  return 0;
}
