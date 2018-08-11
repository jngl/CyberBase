#ifndef CYBERBASE_LOG_HPP
#define CYBERBASE_LOG_HPP

#include <ostream>
#include <string>
#include <vector>

namespace cb
{
class Logger
{
  public:
    friend class LogLine;

    Logger() = default;

    void add(std::ostream *p_outStream);

  private:
    std::vector<std::ostream *> m_streams;
};

class LogLine
{
  public:
    explicit LogLine(Logger *p_logger);
    LogLine(const LogLine &) = default;
    LogLine(LogLine &&) = default;
    ~LogLine();

    LogLine &operator=(const LogLine &) = default;
    LogLine &operator=(LogLine &&) = default;

    void print(const std::string &message) const;

  private:
    Logger *m_logger;
};
/*
LogLine operator<<(LogLine &&ll, const std::string &str);
LogLine operator<<(LogLine &&ll, const char *str);
LogLine operator<<(LogLine &&ll, double val);
LogLine operator<<(LogLine &&ll, int val);
*/
const LogLine &operator<<(const LogLine &ll, const std::string &str);
const LogLine &operator<<(const LogLine &ll, const char *str);
const LogLine &operator<<(const LogLine &ll, double val);
const LogLine &operator<<(const LogLine &ll, int val);

LogLine logInfo(const char *file, int line);
LogLine logWarn(const char *file, int line);
LogLine logError(const char *file, int line);

Logger &getLoggerInfo();
Logger &getLoggerWarning();
Logger &getLoggerError();

void addDefaultLogOutput();
} // namespace cb

#define CB_LOG_INFO cb::logInfo(__FILE__, __LINE__)
#define CB_LOG_WARN cb::logWarn(__FILE__, __LINE__)
#define CB_LOG_ERROR cb::logError(__FILE__, __LINE__)

#endif // CYBERBASE_LOG_HPP