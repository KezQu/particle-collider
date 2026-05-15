#include "mediator_process.hpp"

namespace mpi
{

MediatorProcess::MediatorProcess()
    : BaseProcess(),
      main_window_{1280, 720, "Particle collision"},
      main_menu_{"MainMenu"},
      logger_selector_{},
      engine_factory_{}
{
  main_window_.EnableVSync();

  main_menu_.AddNode(std::ref(logger_selector_));
  for (auto& node : engine_factory_.GetUserInterfaceNodes())
  {
    main_menu_.AddNode(node);
  }
}

void MediatorProcess::Task()
{
  auto const& frame = graphics::FrameGuard{main_window_};
  ImGui::ShowDemoWindow();
  main_menu_.Generate();
  close_requested = main_window_.CloseRequested();
}

}  // namespace mpi
