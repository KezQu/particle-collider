#include "logger.hpp"

#include <chrono>

namespace common
{

void Logger::SetOutStream(std::ostream const& out)
{
  out_.rdbuf(out.rdbuf());
}
void Logger::SetLogLevel(LogLevel level)
{
  level_ = level;
}

LogLevel Logger::level_{LogLevel::kInfo};
std::ostream Logger::out_{std::clog.rdbuf()};

void Logger::Log(LogLevel log_level, std::string formatted_message) const
{
  if (log_level > level_)
  {
    return;
  }
  out_ << std::format("|{:%T}| |{:7}| |{}", std::chrono::system_clock::now(),
                      LogLevelToStringView(log_level), formatted_message)
       << std::endl;
}

}  // namespace common
