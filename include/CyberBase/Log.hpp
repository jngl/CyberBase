#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <fmt/format.h>
#include <fmt/color.h>

namespace cb
{
enum class LogType
{
    Info,
    Warning,
    Error
};

constexpr std::string_view logTypeName(LogType type)
{
    switch (type) {
    case LogType::Error:
        return "Error";
    case LogType::Warning:
        return "Warning";
    case LogType::Info:
        return "Info";
    default:
        return "?";
    }
}

constexpr fmt::color logTypeColor(LogType type)
{
    switch (type) {
    case LogType::Error:
        return fmt::color::red;
    case LogType::Warning:
        return fmt::color::orange;
    case LogType::Info:
        return fmt::color::green;
    default:
        return fmt::color::red;
    }
}

struct LogLine
{
    LogLine(std::string_view p_file,
            int p_line,
            std::string_view p_module,
            LogType p_type,
            fmt::string_view format,
            fmt::format_args args):
        file(p_file),
        line(p_line),
        module(p_module),
        type(p_type),
        message(fmt::vformat(format,args))
    {
    }

    std::string file;
    int line = -1;
    std::string module;
    LogType type = LogType::Info;
    std::string message;
};

class Logger
{
  public:
    virtual ~Logger() = default;

    virtual void log(const LogLine& line) = 0;
};

class ConsoleLogger : public Logger
{
  public:
    void log(const LogLine& line) override;
};

class FileLogger : public Logger
{
  public:
    explicit FileLogger(std::string_view filename);

    void log(const LogLine& line) override;

  private:
    std::ofstream m_file;
};

class MultiLogger : public Logger
{
  public:
    void addOutput(std::unique_ptr<Logger>);

    void log(const LogLine& line) override;

  private:
    std::vector<std::unique_ptr<Logger>> m_outputs;
};
}

template<typename... Args>
void private_cb_log(cb::Logger& logger,
                    std::string_view file,
                    int line,
                    std::string_view module,
                    cb::LogType type,
                    fmt::format_string<Args...> format,
                    Args&& ... args)
{
    logger.log(cb::LogLine(file, line, module, type, format, fmt::make_format_args(args...)));
}

template<typename... Args>
void private_cb_log(const std::shared_ptr<cb::Logger>& logger,
                    std::string_view file,
                    int line,
                    std::string_view module,
                    cb::LogType type,
                    fmt::format_string<Args...> format,
                    Args&& ... args)
{
    logger->log({file, line, module, type, format, fmt::make_format_args(args...)});
}

#define CB_INFO(logger, module, ...) private_cb_log(logger, __FILE__, __LINE__, module, cb::LogType::Info, ##__VA_ARGS__)
#define CB_WARNING(logger, module, ...) private_cb_log(logger, __FILE__, __LINE__, module, cb::LogType::Warning, ##__VA_ARGS__)
#define CB_ERROR(logger, module, ...) private_cb_log(logger, __FILE__, __LINE__, module, cb::LogType::Error, ##__VA_ARGS__)
