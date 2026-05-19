#include "block_num_selector.hpp"

#include <string_view>
#include <thread>
#include <vector>

#include "imgui.h"

namespace collider
{
BlockNumSelector::BlockNumSelector() noexcept : INode("##SelectNumOfBlocks") {}

void BlockNumSelector::Generate()
{
  ImGui::SeparatorText("Number of computing blocks");
  if (ImGui::SliderInt("##CompuBlocksNum", &number_of_blocks_, 1,
                       std::thread::hardware_concurrency()))
  {
    if (number_of_blocks_ > 1)
    {
      number_of_blocks_ = (number_of_blocks_ / 2) * 2;
    }
  }
}

int32_t BlockNumSelector::GetNumberOfBlocks() const
{
  return number_of_blocks_;
}

}  // namespace collider
