#ifndef LOGGER_SELECTOR_HPP_
#define LOGGER_SELECTOR_HPP_

#include <string_view>

#include "i_node.hpp"
#include "logger.hpp"

namespace common
{

class LoggerSelector : public graphics::INode
{
 public:
  LoggerSelector() noexcept;

  void Generate() override;

 private:
  common::Logger logger_{};
  size_t selected_log_level_{static_cast<size_t>(common::LogLevel::kInfo)};
};

}  // namespace common

#endif
