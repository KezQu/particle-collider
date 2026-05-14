#include "block_num_selector.hpp"

#include <string_view>
#include <vector>

#include "imgui.h"

namespace collider
{
BlockNumSelector::BlockNumSelector() noexcept : INode("##SelectNumOfBlocks") {}

void BlockNumSelector::Generate()
{
  std::vector<std::string_view> const available_num_of_blocks{
      "1", "2", "4", "6", "8", "10", "12", "14", "16"};

  if (!ImGui::BeginCombo(
          name_.data(),
          available_num_of_blocks.at(selected_num_of_blocks_).data()))
  {
    return;
  }

  for (size_t idx{}; idx < available_num_of_blocks.size(); ++idx)
  {
    bool const is_selected = (selected_num_of_blocks_ == idx);
    if (ImGui::Selectable(available_num_of_blocks.at(idx).data(), is_selected))
    {
      selected_num_of_blocks_ = idx;
      logger_.Debug("Selected {} number of blocks.",
                    available_num_of_blocks.at(selected_num_of_blocks_));
    }
    if (is_selected) ImGui::SetItemDefaultFocus();
  }
  ImGui::EndCombo();
}
}  // namespace collider
