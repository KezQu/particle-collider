#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <format>
#include <iostream>

namespace common
{

enum class LogLevel
{
  kError,
  kWarn,
  kInfo,
  kDebug,
};

constexpr std::string_view LogLevelToStringView(LogLevel level)
{
  switch (level)
  {
    case LogLevel::kError:
      return "Error";
    case LogLevel::kWarn:
      return "Warn";
    case LogLevel::kInfo:
      return "Info";
    case LogLevel::kDebug:
      return "Debug";
  }
  return "Unknown";
}

class Logger
{
 public:
  static void SetOutStream(std::ostream const& out);
  static void SetLogLevel(LogLevel level);

  template <typename... Args>
  void Error(std::string_view format, Args const&... args) const
  {
    Log(LogLevel::kError, std::vformat(format, std::make_format_args(args...)));
  }

  template <typename... Args>
  void Warn(std::string_view format, Args const&... args) const
  {
    Log(LogLevel::kWarn, std::vformat(format, std::make_format_args(args...)));
  }

  template <typename... Args>
  void Info(std::string_view format, Args const&... args) const
  {
    Log(LogLevel::kInfo, std::vformat(format, std::make_format_args(args...)));
  }

  template <typename... Args>
  void Debug(std::string_view format, Args const&... args) const
  {
    Log(LogLevel::kDebug, std::vformat(format, std::make_format_args(args...)));
  }

 private:
  void Log(LogLevel log_level, std::string formatted_message) const;

  static LogLevel level_;
  static std::ostream out_;
};

}  // namespace common

#endif
