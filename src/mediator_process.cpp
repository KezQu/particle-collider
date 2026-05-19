#include "mediator_process.hpp"

namespace mpi
{

MediatorProcess::MediatorProcess()
    : BaseProcess(),
      main_window_{1280, 720, "Particle collision"},
      main_menu_{"MainMenu"},
      logger_selector_{},
      simulation_{}
{
  main_window_.EnableVSync();

  main_menu_.AddNode(std::ref(logger_selector_));
  for (auto& node : simulation_.GetUserInterfaceNodes())
  {
    main_menu_.AddNode(node);
  }
}

void MediatorProcess::Task()
{
  auto const& frame = graphics::FrameGuard{main_window_};
  ImGui::ShowDemoWindow();
  main_menu_.Generate();

  auto const user_inputs = simulation_.GetUserInputs();
  control_frame_.close_requested = main_window_.CloseRequested();
  control_frame_.log_level = logger_selector_.GetSelectedLogLevel();

  using Action = decltype(user_inputs.action);

  switch (user_inputs.action)
  {
    case Action::kWait:
      break;
    case Action::kStart:
      control_frame_.state = static_cast<int8_t>(State::kRunning);
      break;
    case Action::kStop:
      control_frame_.state = static_cast<int8_t>(State::kIdle);
      break;
    case Action::kRebuild:
      control_frame_.number_of_particles = user_inputs.number_of_particles;
      control_frame_.number_of_blocks = user_inputs.number_of_blocks;
      control_frame_.backend = user_inputs.backend;
      control_frame_.state = static_cast<int8_t>(State::kIdle);
      break;
    default:
      logger_.Warn("Unknown action requested.");
      break;
  }
}

}  // namespace mpi
