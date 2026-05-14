#include "mpi.h"

class MpiGuard
{
 public:
  MpiGuard(int& argc, char**& argv)
  {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_);
  }
  ~MpiGuard()
  {
    MPI_Finalize();
  }

  int32_t GetSize() const
  {
    return size_;
  }

 private:
  int32_t size_{};
};
