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
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}

Window::~Window()
{
  glfwDestroyWindow(window_);
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
  return glfwWindowShouldClose(window_);
}

} // namespace graphics
