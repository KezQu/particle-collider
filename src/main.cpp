#include "context.hpp"
#include "logger.hpp"
#include "window.hpp"

graphics::Context context{};

int main(int argc, char** argv)
{
  graphics::Window main_window{1280, 720, "Particle collision"};

  main_window.FocusContent();

  glfwSwapInterval(1);

  while (!main_window.CloseRequested())
  {
    glfwPollEvents();
    main_window.Refresh();
  }
}
