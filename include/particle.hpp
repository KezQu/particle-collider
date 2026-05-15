#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include "i_particle.hpp"

namespace collider
{

class Particle final : public IParticle
{
 public:
  Particle(Vec2D initial_position) noexcept;

  size_t GetId() const override;
  Vec2D GetPosition() const override;

  void Update(Vec2D velocity, size_t delta_time) override;

 private:
  Vec2D position_;
  size_t id_;
};
}  // namespace collider

#endif
