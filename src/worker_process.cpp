#include "worker_process.hpp"

namespace mpi
{

void WorkerProcess::Task()
{
  if (previous_frame_.backend != control_frame_.backend)
  {
    logger_.Info("Backend change requested. Changing to {}",
                 control_frame_.backend);
    compute_block_ =
        collider::BaseComputeBlock::ComputeBlockFactory(control_frame_.backend);

    previous_frame_ = control_frame_;
  }

  if (static_cast<State>(control_frame_.state) == State::kIdle)
  {
    return;
  }

  if (GetRank() > control_frame_.number_of_blocks)
  {
    logger_.Debug(
        "Rank ({}) higher than the requested number of computing blocks ({}).",
        GetRank(), control_frame_.number_of_blocks);
    return;
  }

  if (!compute_block_)
  {
    logger_.Error("Compute block is not set.");
    return;
  }
  compute_block_->Process();
}

}  // namespace mpi
