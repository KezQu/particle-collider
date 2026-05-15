#ifndef CUDA_COMPUTE_BLOCK_HPP_
#define CUDA_COMPUTE_BLOCK_HPP_

#include "base_compute_block.hpp"

namespace collider
{

class CudaComputeBlock final : public BaseComputeBlock
{
 public:
  using BaseComputeBlock::BaseComputeBlock;

  void Process() const override;
};
}  // namespace collider

#endif
