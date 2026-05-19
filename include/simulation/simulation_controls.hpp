#ifndef SIMULATION_CONTROLS_HPP_
#define SIMULATION_CONTROLS_HPP_

#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{

enum class Action : int8_t
{
  kWait,
  kStart,
  kStop,
  kRebuild
};

class SimulationControls : public graphics::INode
{
 public:
  SimulationControls() noexcept;

  void Generate() override;

  Action GetSimulationAction() const;

 private:
  common::Logger logger_{};
  Action action_;
};

}  // namespace collider

#endif
