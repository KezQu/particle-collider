#include "base_compute_block.hpp"
#include "cuda_compute_block.hpp"
#include "opencl_compute_block.hpp"

namespace collider
{
std::unique_ptr<BaseComputeBlock> BaseComputeBlock::ComputeBlockFactory(
    int8_t backend)
{
  switch (backend)
  {
    case 0:
      return std::make_unique<CudaComputeBlock>(DynamicParticlesView{});
    case 1:
      return std::make_unique<OpenCLComputeBlock>(DynamicParticlesView{});
    default:
      throw std::runtime_error("Invalid backend");
  }
}

}  // namespace collider
