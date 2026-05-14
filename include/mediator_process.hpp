#ifndef MEDIATOR_PROCESS_HPP_
#define MEDIATOR_PROCESS_HPP_

#include "engine_factory.hpp"
#include "frame_guard.hpp"
#include "logger_selector.hpp"
#include "pane.hpp"
#include "process.hpp"
#include "window.hpp"

namespace mpi
{
class MediatorProcess final : public Process
{
 public:
  MediatorProcess();

 protected:
  void Task() override;

 private:
  graphics::Window main_window_;
  graphics::Pane main_menu_;
  common::LoggerSelector logger_selector_;
  collider::EngineFactory engine_factory_;
};

}  // namespace mpi

#endif
