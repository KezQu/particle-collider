#include "context.hpp"

#include <stdlib.h>

namespace graphics
{

Context::Context()
{
  if (!glfwInit())
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Context::~Context()
{
  glfwTerminate();
}
}  // namespace graphics
