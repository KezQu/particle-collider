#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <GLFW/glfw3.h>

#include <string>

#include "logger.hpp"

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
  void EnableVSync() const;
  void FocusContext() const;
  bool CloseRequested() const;

 private:
  void InitImGui();

  common::Logger logger_;
  GLFWwindow* window_;
};
}  // namespace graphics

#endif
