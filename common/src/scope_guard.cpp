
#include "scope_guard.hpp"

namespace common
{

ScopeGuard::ScopeGuard(std::function<void()> guard) : guard_{guard} {}

ScopeGuard::~ScopeGuard()
{
  if (guard_)
  {
    guard_();
  }
}

void ScopeGuard::Cancel()
{
  guard_ = {};
}

}  // namespace common
