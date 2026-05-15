#ifndef I_PARTICLE_HPP_
#define I_PARTICLE_HPP_

#include <cstdlib>

#include "vec_2d.hpp"

namespace collider
{

class IParticle
{
 public:
  virtual ~IParticle() = default;

  virtual size_t GetId() const = 0;
  virtual Vec2D GetPosition() const = 0;

  virtual void Update(Vec2D velocity, size_t delta_time) = 0;
};
}  // namespace collider

#endif
