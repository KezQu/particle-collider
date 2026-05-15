#include "worker_process.hpp"

namespace mpi
{

void WorkerProcess::Task()
{
  if (!compute_block_)
  {
    logger_.Error("Compute block is not set.");
    return;
  }
  compute_block_->Process();
}

}  // namespace mpi
