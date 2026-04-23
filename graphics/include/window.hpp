#include <GLFW/glfw3.h>

#include <string>

namespace graphics
{
class Window
{
 public:
  Window(uint16_t initial_width, uint16_t initial_height,
         std::string_view title);

  Window(Window&&) = delete;
  Window(Window const&) = delete;
  Window& operator=(Window&&) = delete;
  Window& operator=(Window const&) = delete;
  ~Window();

  void Refresh() const;
  void FocusContent() const;
  bool CloseRequested() const;

 private:
  GLFWwindow* window_;
};
}  // namespace graphics
