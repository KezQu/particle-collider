
#include "process.hpp"

namespace mpi
{
Process::Process()
{
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_);
}

void Process::ProcessTasks()
{
  while (!close_requested)
  {
    Task();
    MPI_Bcast(&close_requested, 1, MPI_CXX_BOOL, kMediatorProcess,
              MPI_COMM_WORLD);
  }
}

int32_t Process::GetRank() const
{
  return rank_;
}

void Process::Task() {}

}  // namespace mpi
