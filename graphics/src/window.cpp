#include "window.hpp"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

namespace graphics
{

bool constexpr kInstallCallbacks{true};

Window::Window(uint16_t initial_width, uint16_t initial_height,
               std::string_view title)
{
  window_ =
      glfwCreateWindow(initial_width, initial_height, title.data(), NULL, NULL);

  if (!window_)
  {
    logger_.Error("Window creation failed.");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  logger_.Debug("Window created.");

  InitImGui();
}

void Window::InitImGui()
{
  FocusContext();

  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window_, kInstallCallbacks);
  if (!ImGui_ImplOpenGL3_Init())
  {
    logger_.Error("Failed to init ImGui.");
    exit(EXIT_FAILURE);
  }
  logger_.Debug("ImGui initialized.");
}

Window::~Window()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window_);
  logger_.Debug("Window destroyed.");
}

void Window::Refresh() const
{
  glfwSwapBuffers(window_);
}

void Window::EnableVSync() const
{
  FocusContext();
  glfwSwapInterval(1);
}

void Window::FocusContext() const
{
  glfwMakeContextCurrent(window_);
}

bool Window::CloseRequested() const
{
  bool const should_close = glfwWindowShouldClose(window_);
  if (should_close)
  {
    logger_.Debug("Window should be closed.");
  }

  return should_close;
}

}  // namespace graphics
