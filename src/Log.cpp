#include "CyberBase/Log.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace cb
{
Logger info;
Logger warning;
Logger error;

void Logger::add(std::ostream *p_outStream) {
    m_streams.push_back(p_outStream);
}

LogLine::LogLine(Logger *p_logger) : m_logger(p_logger) {}

LogLine::~LogLine() { end(); }

void LogLine::end() {
    for (std::ostream *stream : m_logger->m_streams) {
        (*stream) << std::endl;
    }
}

void LogLine::print(const std::string &message) const {
    for (std::ostream *stream : m_logger->m_streams) {
        (*stream) << message;
    }
}

LogLineError::~LogLineError() {
    end();
    exit(1);
}

const LogLine &operator<<(const LogLine &ll, const std::string &str) {
    ll.print(str);
    return ll;
}

const LogLine &operator<<(const LogLine &ll, const char *str) {
    ll.print(std::string(str));
    return ll;
}

const LogLine &operator<<(const LogLine &ll, const unsigned char *str) {
    ll.print(std::string(reinterpret_cast<const char *>(str)));
    return ll;
}

const LogLine &operator<<(const LogLine &ll, double val) {
    std::stringstream str;
    // str.precision(5);
    str << val;
    ll.print(str.str());
    return ll;
}

const LogLine &operator<<(const LogLine &ll, unsigned int val) {
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

LogLineError logError(const char *file, int line) {
    LogLineError myLine(&error);
    myLine << file << "(" << line << ") error : ";
    return myLine;
}

Logger &getLoggerInfo() { return info; }

Logger &getLoggerWarning() { return warning; }

Logger &getLoggerError() { return error; }

void addDefaultLogOutput() {
    static std::ofstream logFile("log.txt");

    cb::getLoggerInfo().add(&std::cout);
    cb::getLoggerWarning().add(&std::cerr);
    cb::getLoggerError().add(&std::cerr);

    cb::getLoggerInfo().add(&logFile);
    cb::getLoggerWarning().add(&logFile);
    cb::getLoggerError().add(&logFile);
}

} // namespace cb