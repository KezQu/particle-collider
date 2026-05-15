#include "backend_selector.hpp"

#include <string_view>
#include <vector>

#include "imgui.h"

namespace collider
{
BackendSelector::BackendSelector() noexcept : INode("##SelectBackend") {}

void BackendSelector::Generate()
{
  std::vector<std::string_view> const available_backends{"CUDA", "OpenCL"};

  ImGui::SeparatorText("Choose backend");
  if (!ImGui::BeginCombo(name_.data(),
                         available_backends.at(selected_backend_).data()))
  {
    return;
  }

  for (size_t idx{}; idx < available_backends.size(); ++idx)
  {
    bool const is_selected = (selected_backend_ == idx);
    if (ImGui::Selectable(available_backends.at(idx).data(), is_selected))
    {
      selected_backend_ = idx;
      logger_.Debug("Selected backend: {}",
                    available_backends.at(selected_backend_));
    }
    if (is_selected) ImGui::SetItemDefaultFocus();
  }
  ImGui::EndCombo();
}
}  // namespace collider
