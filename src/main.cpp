#include "context.hpp"
#include "engine_factory.hpp"
#include "frame_guard.hpp"
#include "imgui.h"
#include "logger.hpp"
#include "logger_selector.hpp"
#include "pane.hpp"
#include "window.hpp"

graphics::Context context{};

int main(int argc, char** argv)
{
  // MpiGuard const mpi_guard{argc, argv};
  graphics::Window main_window{1280, 720, "Particle collision"};
  main_window.EnableVSync();

  graphics::Pane main_menu{"MainMenu"};

  common::LoggerSelector logger_selector{};
  main_menu.AddNode(std::ref(logger_selector));

  collider::EngineFactory engine_factory{};
  for (auto const& node : engine_factory.GetUserInterfaceNodes())
  {
    main_menu.AddNode(std::ref(node));
  }

  while (!main_window.CloseRequested())
  {
    auto const& frame = graphics::FrameGuard{main_window};
    // ImGui::ShowDemoWindow();
    main_menu.Generate();
  }
}
