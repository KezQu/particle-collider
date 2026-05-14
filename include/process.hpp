#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <functional>

#include "logger.hpp"
#include "mpi.h"

namespace mpi
{
class Process
{
 public:
  static constexpr inline int32_t kMediatorProcess{};

  Process();
  virtual ~Process();

  void ProcessTask();
  int32_t GetRank() const;

 protected:
  virtual void Task();

  common::Logger logger_{};
  int32_t rank_{};
  bool close_requested{};
};

}  // namespace mpi

#endif
