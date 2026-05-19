#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <memory>
#include <string_view>
#include <vector>

#include "backend_selector.hpp"
#include "block_num_selector.hpp"
#include "i_node.hpp"
#include "logger.hpp"
#include "particles_selector.hpp"
#include "simulation_controls.hpp"

namespace collider
{

struct UserInputs
{
  int32_t number_of_blocks{};
  int32_t number_of_particles{};
  int8_t backend{};
  Action action{};
};

class Simulation
{
 public:
  using UINodes = std::vector<std::reference_wrapper<graphics::INode>>;

  Simulation() noexcept;

  UINodes GetUserInterfaceNodes();

  UserInputs GetUserInputs() const;

 private:
  common::Logger logger_{};

  BackendSelector backend_selector_{};
  BlockNumSelector block_num_selector_{};
  ParticlesSelector particles_selector_{};
  SimulationControls simulation_controls_{};
};

}  // namespace collider

#endif
