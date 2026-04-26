#include "context.hpp"
#include "imgui.h"
#include "logger.hpp"
#include "window.hpp"

graphics::Context context{};

int main(int argc, char** argv)
{
  graphics::Window main_window{1280, 720, "Particle collision"};
  common::Logger logger_{};

  main_window.EnableVSync();

  while (!main_window.CloseRequested())
  {
    if (!ImGui::GetCurrentContext())
    {
      logger_.Error("ImGui has no context.");
      exit(EXIT_FAILURE);
    }

    glfwPollEvents();
    main_window.Refresh();
  }
}
