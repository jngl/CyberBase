#include "CyberBase/Log.hpp"

#include <iostream>

namespace cb
{
Logger info;
Logger warning;
Logger error;

void Logger::add(std::ostream *p_outStream) {
    m_streams.push_back(p_outStream);
}

LogLine::LogLine(Logger *p_logger) : m_logger(p_logger) {}

LogLine::~LogLine() {
    for (std::ostream *stream : m_logger->m_streams) {
        (*stream) << std::endl;
    }
}

void LogLine::print(const std::string &message) const {
    for (std::ostream *stream : m_logger->m_streams) {
        (*stream) << message;
    }
}
/*
LogLine operator<<(LogLine &&ll, const std::string &str) {
    LogLine myLine(std::move(ll));
    myLine.print(str);
    return myLine;
}

LogLine operator<<(LogLine &&ll, const char *str) {
    LogLine myLine(std::move(ll));
    myLine.print(std::string(str));
    return myLine;
}

LogLine operator<<(LogLine &&ll, double val) {
    LogLine myLine(std::move(ll));
    myLine.print(std::to_string(val));
    return myLine;
}

LogLine operator<<(LogLine &&ll, int val) {
    LogLine myLine(std::move(ll));
    myLine.print(std::to_string(val));
    return myLine;
}
*/
const LogLine &operator<<(const LogLine &ll, const std::string &str) {
    ll.print(str);
    return ll;
}

const LogLine &operator<<(const LogLine &ll, const char *str) {
    ll.print(std::string(str));
    return ll;
}

const LogLine &operator<<(const LogLine &ll, double val) {
    ll.print(std::to_string(val));
    return ll;
}

const LogLine &operator<<(const LogLine &ll, int val) {
    ll.print(std::to_string(val));
    return ll;
}

LogLine logInfo(const char *file, int line) {
    LogLine myLine(&info);
    myLine << file << "(" << line << ") info : ";
    return myLine;
}

LogLine logWarn(const char *file, int line) {
    LogLine myLine(&warning);
    myLine << file << "(" << line << ") warning : ";
    return myLine;
}

LogLine logError(const char *file, int line) {
    LogLine myLine(&error);
    myLine << file << "(" << line << ") error : ";
    return myLine;
}

Logger &getLoggerInfo() { return info; }

Logger &getLoggerWarning() { return warning; }

Logger &getLoggerError() { return error; }

} // namespace cb