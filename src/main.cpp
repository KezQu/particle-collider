#include "context.hpp"
#include "engine_factory.hpp"
#include "frame_guard.hpp"
#include "imgui.h"
#include "logger.hpp"
#include "pane.hpp"
#include "window.hpp"

graphics::Context context{};

int main(int argc, char** argv)
{
  graphics::Window main_window{1280, 720, "Particle collision"};

  main_window.EnableVSync();

  collider::EngineFactory engine_factory{};

  graphics::Pane main_menu{"MainMenu"};

  main_menu.AddNode(std::ref(engine_factory));

  while (!main_window.CloseRequested())
  {
    auto const& frame = graphics::FrameGuard{main_window};
    // ImGui::ShowDemoWindow();
    main_menu.Generate();
  }
}
