#include "frame_guard.hpp"

#include <GLFW/glfw3.h>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

namespace graphics
{

FrameGuard::FrameGuard(IWindow const& window, ImVec4 clear_color)
    : window_{window}, clear_color_{clear_color}
{
  glfwMakeContextCurrent(window_.GetContext());

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
  ImGui::DockSpaceOverViewport(0, nullptr,
                               ImGuiDockNodeFlags_PassthruCentralNode);
  glfwPollEvents();
}

FrameGuard::~FrameGuard()
{
  ImGui::Render();
  glClearColor(clear_color_.x * clear_color_.w, clear_color_.y * clear_color_.w,
               clear_color_.z * clear_color_.w, clear_color_.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  glfwSwapBuffers(glfwGetCurrentContext());
}

}  // namespace graphics
