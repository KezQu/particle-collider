
#include "engine_factory.hpp"

#include "engine_factory_node_impl.hpp"
#include "imgui.h"

namespace collider
{

EngineFactory::EngineFactory()
    : node_impl_{std::make_unique<EngineFactoryNodeImpl>()}
{
}

void EngineFactory::Generate()
{
  node_impl_->Generate();
}

void EngineFactoryNodeImpl::Generate()
{
  std::vector<std::string_view> available_backends{"CUDA", "OpenCL"};

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
    }
    if (is_selected) ImGui::SetItemDefaultFocus();
  }
  ImGui::EndCombo();
}

}  // namespace collider
