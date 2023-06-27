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
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

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

  float object[] =
  {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };
  u32 VBO = 0, shaderProgram = 0, VAO = 0, EBO = 0;

  drawVertex(object, VBO, shaderProgram, VAO, EBO);

  glfwMakeContextCurrent(render.window);
  glfwSetKeyCallback(render.window, keyCallback);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(render.window))
  {
    i32 width, height;

    glEnableVertexAttribArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(VAO);

    glfwGetFramebufferSize(render.window, &width, &height);
    glViewport(0, 0, width, height);

    glfwSwapBuffers(render.window);
    glfwPollEvents();
  }

  return 0;
}
