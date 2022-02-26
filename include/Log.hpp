#ifndef LOG_HPP
#define LOG_HPP

#include <QString>
#include <string>

// methods used to log data to either the console, file, or both.
namespace Log {
    // Enum of locations to log to
    enum class Location {
        Console,            // Log to console
        File,               // Log to file
        ConsoleAndFile      // Log to console and file
    };

    // Enum of log levels
    enum class Level {
        Info = 0,           // Information
        Warn = 1,           // Warning
        Error = 2           // Error
    };

    // Increase indent level by one.
    void increaseIndent();

    // Decrease indent level by one.
    void decreaseIndent();

    // Set indent amount (defaults to 4).
    void setIndentAmount(const int amt);

    // Set log level.
    void setLogLevel(const Level lvl);

    // Set where to log to.
    void setLogLocation(const Location location, const std::string filePath = "");

    // Log an info message.
    void logInfo(const std::string message);

    void logInfo(const QString & message);

    // Log a warning message.
    void logWarning(const std::string message);

    void logWarning(const QString & message);

    // Log an error message.
    void logError(const std::string message);

    void logError(const QString & message);
};

#endif
