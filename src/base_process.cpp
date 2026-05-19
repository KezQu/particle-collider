#include "base_process.hpp"

namespace mpi
{
BaseProcess::BaseProcess()
{
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_);
}

void BaseProcess::ProcessTask()
{
  while (!control_frame_.close_requested)
  {
    Task();
    MPI_Bcast(&control_frame_, sizeof(ControlFrame), MPI_BYTE, kMediatorProcess,
              MPI_COMM_WORLD);

    common::Logger::SetLogLevel(
        static_cast<common::LogLevel>(control_frame_.log_level));
  }
}

int32_t BaseProcess::GetRank() const
{
  return rank_;
}

void BaseProcess::Task() {}

}  // namespace mpi
