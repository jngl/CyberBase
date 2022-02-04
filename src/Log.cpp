#include "CyberBase/Log.hpp"

#include <filesystem>
#include <chrono>
#include <fmt/chrono.h>

namespace cb
{

void ConsoleLogger::log(const LogLine& line)
{
    std::string fileName = std::filesystem::path(line.file).filename().string();

    const std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();

    fmt::print(fg(logTypeColor(line.type)),
               "{:^15}|{:^9}| {} |{:^25}|{:^5}| {}\n",
               line.module,
               logTypeName(line.type),
               now,
               fileName,
               line.line,
               line.message);
}

void MultiLogger::addOutput(std::unique_ptr<Logger> output)
{
    m_outputs.emplace_back(std::move(output));
}

void MultiLogger::log(const LogLine &line) {
    for(auto& output: m_outputs)
    {
        output->log(line);
    }
}
FileLogger::FileLogger(std::string_view filename):
m_file(std::string(filename).c_str(), std::ios::app | std::ios::out)
{
}

void FileLogger::log(const LogLine &line)
{
    std::string fileName = std::filesystem::path(line.file).filename().string();

    const std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();

    std::string lineStr = fmt::format("{};{};{};{};{};{}\n",
                                   line.module,
                                   logTypeName(line.type),
                                   now,
                                   fileName,
                                   line.line,
                                   line.message);
    m_file << lineStr;
}
}

