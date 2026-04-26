#ifndef I_WINDOW_HPP_
#define I_WINDOW_HPP_

struct GLFWwindow;

namespace graphics
{
class IWindow
{
 public:
  virtual ~IWindow() = default;

  virtual GLFWwindow* const GetContext() const = 0;
};
}  // namespace graphics

#endif
