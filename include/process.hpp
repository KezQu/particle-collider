#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <functional>

#include "mpi.h"

namespace mpi
{
class Process
{
 public:
  static constexpr inline int32_t kMediatorProcess{};

  Process();
  virtual ~Process() = default;

  void ProcessTasks();
  int32_t GetRank() const;

 protected:
  static inline bool close_requested{};

  virtual void Task();

  int32_t rank_{};
};

}  // namespace mpi

#endif
