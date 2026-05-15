#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <functional>

#include "i_process.hpp"
#include "logger.hpp"
#include "mpi.h"

namespace mpi
{
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
  bool close_requested{};
};

}  // namespace mpi

#endif
