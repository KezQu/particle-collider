#ifndef MPI_GUARD_HPP_
#define MPI_GUARD_HPP_

#include "mpi.h"

namespace mpi
{
class MpiGuard
{
 public:
  MpiGuard(int32_t& argc, char**& argv);
  ~MpiGuard();
  int32_t GetSize() const;

 private:
  int32_t size_{};
};

}  // namespace mpi

#endif
