#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <functional>

#include "i_process.hpp"
#include "logger.hpp"
#include "mpi.h"

namespace mpi
{

enum class State : int8_t
{
  kIdle,
  kRunning
};

struct ControlFrame
{
  int32_t number_of_particles{};
  int32_t number_of_blocks{1};
  int8_t backend{-1};
  int8_t state{};
  uint8_t log_level{};
  bool close_requested{};
};

class BaseProcess : public IProcess
{
 public:
  static constexpr inline int32_t kMediatorProcess{};

  BaseProcess();

  void ProcessTask() override;
  int32_t GetRank() const override;

 protected:
  void Task() override;

  common::Logger logger_{};
  int32_t rank_{};
  ControlFrame control_frame_{};
};

}  // namespace mpi

#endif
