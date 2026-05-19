#ifndef MEDIATOR_PROCESS_HPP_
#define MEDIATOR_PROCESS_HPP_

#include "base_process.hpp"
#include "frame_guard.hpp"
#include "logger_selector.hpp"
#include "pane.hpp"
#include "simulation.hpp"
#include "window.hpp"

namespace mpi
{

class MediatorProcess final : public BaseProcess
{
 public:
  MediatorProcess();

 protected:
  void Task() override;

 private:
  graphics::Window main_window_;
  graphics::Pane main_menu_;
  common::LoggerSelector logger_selector_;
  collider::Simulation simulation_;
};

}  // namespace mpi

#endif
