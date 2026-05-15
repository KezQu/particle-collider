#include "vec_2d.hpp"

namespace collider
{

Vec2D::Vec2D() : Vec2D({}, {}) {}
Vec2D::Vec2D(float x, float y) : x{x}, y{y} {}

Vec2D Vec2D::operator-() noexcept
{
  return {-x, -y};
}

Vec2D Vec2D::operator+(Vec2D const& rhs) noexcept
{
  return {x + rhs.x, y + rhs.y};
}
Vec2D Vec2D::operator-(Vec2D const& rhs) noexcept
{
  return {x - rhs.x, y - rhs.y};
}

Vec2D& Vec2D::operator+=(Vec2D const& rhs) noexcept
{
  *this = *this + rhs;
  return *this;
}
Vec2D& Vec2D::operator-=(Vec2D const& rhs) noexcept
{
  *this = *this - rhs;
  return *this;
}

}  // namespace collider
