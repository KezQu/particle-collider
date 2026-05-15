#ifndef OPENCL_COMPUTE_BLOCK_HPP_
#define OPENCL_COMPUTE_BLOCK_HPP_

#include "base_compute_block.hpp"

namespace collider
{

class OpenCLComputeBlock final : public BaseComputeBlock
{
 public:
  using BaseComputeBlock::BaseComputeBlock;

  void Process() const override;
};
}  // namespace collider

#endif
