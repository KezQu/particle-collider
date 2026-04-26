#include "context.hpp"
#include "frame_guard.hpp"
#include "imgui.h"
#include "logger.hpp"
#include "window.hpp"

graphics::Context context{};

int main(int argc, char** argv)
{
  graphics::Window main_window{1280, 720, "Particle collision"};

  main_window.EnableVSync();

  while (!main_window.CloseRequested())
  {
    auto const& frame = graphics::FrameGuard{main_window};
  }
}
