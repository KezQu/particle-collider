#include "simulation.hpp"

namespace collider
{

Simulation::Simulation() noexcept {}

Simulation::UINodes Simulation::GetUserInterfaceNodes()
{
  return {std::ref(backend_selector_), std::ref(block_num_selector_),
          std::ref(particles_selector_), std::ref(simulation_controls_)};
}

UserInputs Simulation::GetUserInputs() const
{
  UserInputs inputs{};
  inputs.number_of_blocks = block_num_selector_.GetNumberOfBlocks();
  inputs.number_of_particles = particles_selector_.GetNumberOfParticles();
  inputs.backend = backend_selector_.GetSelectedBackend();
  inputs.action = simulation_controls_.GetSimulationAction();
  return inputs;
}

}  // namespace collider
