
#include "base_process.hpp"

namespace mpi
{
BaseProcess::BaseProcess()
{
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_);
}

void BaseProcess::ProcessTask()
{
  while (!close_requested)
  {
    Task();
    MPI_Bcast(&close_requested, 1, MPI_CXX_BOOL, kMediatorProcess,
              MPI_COMM_WORLD);
  }
}

int32_t BaseProcess::GetRank() const
{
  return rank_;
}

void BaseProcess::Task() {}

}  // namespace mpi
