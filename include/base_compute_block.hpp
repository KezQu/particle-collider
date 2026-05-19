#ifndef BASE_COMPUTE_BLOCK_HPP_
#define BASE_COMPUTE_BLOCK_HPP_

#include <memory>
#include <vector>

#include "i_particle.hpp"
#include "logger.hpp"

namespace collider
{

using DynamicParticlesView =
    std::vector<std::reference_wrapper<collider::IParticle>>;

class BaseComputeBlock
{
 public:
  BaseComputeBlock(DynamicParticlesView const& particles) noexcept
      : particles_{particles}
  {
  }

  virtual void Process() const = 0;

  static std::unique_ptr<BaseComputeBlock> ComputeBlockFactory(int8_t backend);

 protected:
  common::Logger logger_{};
  DynamicParticlesView const& particles_{};
};
}  // namespace collider

#endif
