#ifndef I_PROCESS_HPP_
#define I_PROCESS_HPP_

#include <cstdlib>

namespace mpi
{
class IProcess
{
 public:
  IProcess() = default;
  virtual ~IProcess() = default;

  virtual void ProcessTask() = 0;
  virtual int32_t GetRank() const = 0;

 protected:
  virtual void Task() = 0;
};

}  // namespace mpi

#endif
