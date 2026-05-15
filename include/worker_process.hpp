#ifndef WORKER_PROCESS_HPP_
#define WORKER_PROCESS_HPP_

#include <concepts>
#include <memory>
#include <vector>

#include "base_compute_block.hpp"
#include "base_process.hpp"
#include "i_particle.hpp"
#include "logger.hpp"

namespace mpi
{
class WorkerProcess final : public BaseProcess
{
 public:
  using BaseProcess::BaseProcess;

  template <typename T>
    requires std::is_base_of_v<T, collider::BaseComputeBlock>
  void SetComputeBlock()
  {
    compute_block_ = std::make_unique<T>(particles_);
  }

 protected:
  void Task() override;

 private:
  common::Logger logger_{};
  collider::DynamicParticlesView particles_{};
  std::unique_ptr<collider::BaseComputeBlock> compute_block_{};
};

}  // namespace mpi

#endif
