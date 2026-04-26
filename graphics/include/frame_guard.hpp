#ifndef FRAME_GUARD_HPP_
#define FRAME_GUARD_HPP_

#include "i_window.hpp"
#include "imgui.h"

namespace graphics
{
class FrameGuard
{
 public:
  FrameGuard(IWindow const& window,
             ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 1.00f));
  ~FrameGuard();

 private:
  IWindow const& window_;
  ImVec4 clear_color_;
};

}  // namespace graphics

#endif
