#ifndef VEC2D_HPP_
#define VEC2D_HPP_

#include <concepts>
#include <type_traits>

namespace collider
{
template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

struct Vec2D
{
  float x;
  float y;
  Vec2D();
  Vec2D(float x, float y);

  Vec2D(Vec2D&&) = default;
  Vec2D(Vec2D const&) = default;
  Vec2D& operator=(Vec2D&&) = default;
  Vec2D& operator=(Vec2D const&) = default;

  Vec2D operator-() noexcept;
  Vec2D operator+(Vec2D const& rhs) noexcept;
  Vec2D operator-(Vec2D const& rhs) noexcept;

  Vec2D& operator+=(Vec2D const& rhs) noexcept;
  Vec2D& operator-=(Vec2D const& rhs) noexcept;

  template <arithmetic T>
  Vec2D operator*(T factor) noexcept
  {
    return {x * factor, y * factor};
  }
};
}  // namespace collider

#endif
