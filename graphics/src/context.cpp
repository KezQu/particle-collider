#include "context.hpp"

#include <stdlib.h>

#include "logger.hpp"

namespace graphics
{

void ErrorCallback(int32_t error, char const* desc)
{
  common::Logger logger{};
  logger.Error("GLFW error occurred: {} ({})", desc, error);
}

Context::Context()
{
  glfwSetErrorCallback(ErrorCallback);

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
