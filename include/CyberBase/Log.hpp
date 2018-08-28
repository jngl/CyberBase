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
    virtual ~LogLine();

    LogLine &operator=(const LogLine &) = default;
    LogLine &operator=(LogLine &&) = default;

    void print(const std::string &message) const;

  protected:
    void end();

  private:
    Logger *m_logger;
};

class LogLineError : public cb::LogLine
{
  public:
    using cb::LogLine::LogLine;
    ~LogLineError();
};

const LogLine &operator<<(const LogLine &ll, const std::string &str);
const LogLine &operator<<(const LogLine &ll, const char *str);
const LogLine &operator<<(const LogLine &ll, double val);
const LogLine &operator<<(const LogLine &ll, unsigned int val);
const LogLine &operator<<(const LogLine &ll, int val);

LogLine logInfo(const char *file, int line);
LogLine logWarn(const char *file, int line);
LogLineError logError(const char *file, int line);

Logger &getLoggerInfo();
Logger &getLoggerWarning();
Logger &getLoggerError();

void addDefaultLogOutput();
} // namespace cb

#define CB_LOG_INFO cb::logInfo(__FILE__, __LINE__)
#define CB_LOG_WARN cb::logWarn(__FILE__, __LINE__)
#define CB_ERROR cb::logError(__FILE__, __LINE__)

#endif // CYBERBASE_LOG_HPP