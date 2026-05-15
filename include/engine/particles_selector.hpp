#ifndef PARTICLES_SELECTOR_HPP_
#define PARTICLES_SELECTOR_HPP_

#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{
class ParticlesSelector : public graphics::INode
{
 public:
  ParticlesSelector() noexcept;

  void Generate() override;

  int32_t GetNumberOfParticles() const;

 private:
  int32_t number_of_particles{10};
};
}  // namespace collider

#endif
