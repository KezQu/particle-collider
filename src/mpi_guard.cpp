#include "mpi_guard.hpp"

namespace mpi
{
MpiGuard::MpiGuard(int32_t& argc, char**& argv)
{
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_);
}
MpiGuard::~MpiGuard()
{
  MPI_Finalize();
}

int32_t MpiGuard::GetSize() const
{
  return size_;
}

}  // namespace mpi
