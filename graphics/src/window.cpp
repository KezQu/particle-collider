#include "window.hpp"

namespace graphics
{

Window::Window(uint16_t initial_width, uint16_t initial_height,
               std::string_view title)
{
  window_ =
      glfwCreateWindow(initial_width, initial_height, title.data(), NULL, NULL);

  if (!window_)
  {
    logger_.Error("Window creation failed.");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  logger_.Debug("Window created.");
}

Window::~Window()
{
  glfwDestroyWindow(window_);
  logger_.Debug("Window destroyed.");
}

void Window::Refresh() const
{
  glfwSwapBuffers(window_);
}
void Window::FocusContent() const
{
  glfwMakeContextCurrent(window_);
}
bool Window::CloseRequested() const
{
  bool const should_close = glfwWindowShouldClose(window_);
  if (should_close)
  {
    logger_.Debug("Window should be closed.");
  }

  return should_close;
}

}  // namespace graphics
