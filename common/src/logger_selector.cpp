#include "logger_selector.hpp"

#include <string_view>
#include <vector>

#include "imgui.h"

namespace common
{

LoggerSelector::LoggerSelector() noexcept : INode("##LoggerSelector") {}

void LoggerSelector::Generate()
{
  std::vector<std::string_view> const available_log_levels{"Error", "Warn",
                                                           "Info", "Debug"};

  if (!ImGui::BeginCombo(name_.data(),
                         available_log_levels.at(selected_log_level_).data()))
  {
    return;
  }

  for (size_t idx{}; idx < available_log_levels.size(); ++idx)
  {
    bool const is_selected = (selected_log_level_ == idx);
    if (ImGui::Selectable(available_log_levels.at(idx).data(), is_selected))
    {
      selected_log_level_ = idx;

      auto const log_level = static_cast<common::LogLevel>(selected_log_level_);
      logger_.Info("Selected log level: {}", LogLevelToStringView(log_level));

      common::Logger::SetLogLevel(log_level);
    }
    if (is_selected) ImGui::SetItemDefaultFocus();
  }
  ImGui::EndCombo();
}

}  // namespace common
