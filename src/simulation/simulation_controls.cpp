#include "simulation_controls.hpp"

#include "imgui.h"

namespace collider
{

SimulationControls::SimulationControls() noexcept
    : INode("##SimulationControls")
{
}

void SimulationControls::Generate()
{
  action_ = Action::kWait;

  ImGui::SeparatorText("Simulation Controls");
  if (ImGui::Button("Start"))
  {
    action_ = Action::kStart;
    logger_.Info("Requesting simulation to start.");
  }
  ImGui::SameLine();
  if (ImGui::Button("Stop"))
  {
    action_ = Action::kStop;
    logger_.Info("Requesting simulation to stop.");
  }
  ImGui::SameLine();
  if (ImGui::Button("Rebuild"))
  {
    action_ = Action::kRebuild;
    logger_.Info("Requesting simulation to rebuild and reset.");
  }
}

Action SimulationControls::GetSimulationAction() const
{
  return action_;
}

}  // namespace collider
