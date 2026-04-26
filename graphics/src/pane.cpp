
#include "pane.hpp"

#include "imgui.h"
#include "scope_guard.hpp"

namespace graphics
{

Pane::Pane(std::string_view name, ImGuiWindowFlags settings)
    : name_{name}, settings_{settings}
{
}

void Pane::AddNode(std::reference_wrapper<INode> node)
{
  children_.push_back(node);
}

void Pane::Generate()
{
  auto pane_guard = common::ScopeGuard{&ImGui::End};

  if (!ImGui::Begin(name_.data(), nullptr, settings_))
  {
    logger_.Warn("Failed to initialize generation of {}.", name_);
    return;
  }
  for (auto const& child : children_)
  {
    child.get().Generate();
  }
}

}  // namespace graphics
