#include "particle.hpp"

#include "utils.hpp"

namespace collider
{

Particle::Particle(Vec2D initial_position) noexcept
    : position_{initial_position}, id_{common::GetRandomValue<size_t>()}
{
}

size_t Particle::GetId() const
{
  return id_;
}

Vec2D Particle::GetPosition() const
{
  return position_;
}

void Particle::Update(Vec2D velocity, size_t delta_time)
{
  position_ += velocity * delta_time;
}

}  // namespace collider
