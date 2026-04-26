#ifndef SCOPE_GUARD_HPP_
#define SCOPE_GUARD_HPP_

#include <functional>

namespace common
{

class ScopeGuard
{
 public:
  ScopeGuard(std::function<void()> guard);

  ScopeGuard(ScopeGuard&&) = delete;
  ScopeGuard(ScopeGuard const&) = delete;
  ScopeGuard& operator=(ScopeGuard&&) = delete;
  ScopeGuard& operator=(ScopeGuard const&) = delete;
  ~ScopeGuard();

  void Cancel();

 private:
  std::function<void()> guard_;
};
}  // namespace common

#endif
