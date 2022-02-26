#include "Log.hpp"

#include <fstream>
#include <iostream>

namespace Log {
    // Indent amount (in spaces).
    static short indentAmount = 4;

    // Indent level.
    static short indentLevel = 0;

    // Output file.
    static std::ofstream file;

    // Log level.
    static Level level = Level::Info;

    // Log mode/location.
    static Location mode = Location::Console;

    // Log the given message with the given prefix.
    static void log(const std::string & prefix, const std::string & message) {
        std::string indent = "";
        for (int i = 0; i < indentAmount*indentLevel; i++) {
            indent += " ";
        }

        std::string msg = prefix + " " + indent + message;
        switch (mode) {
            case Location::Console:
                std::cout << msg << std::endl;
                break;

            case Location::File:
                file << msg << std::endl;
                break;

            case Location::ConsoleAndFile:
                std::cout << msg << std::endl;
                file << msg << std::endl;
                break;
        }
    }

    void increaseIndent() {
        indentLevel++;
    }

    void decreaseIndent() {
        indentLevel--;
    }

    void setIndentAmount(const int amt) {
        indentAmount = amt;
    }

    void setLogLevel(const Level lvl) {
        level = lvl;
    }

    void setLogLocation(const Location location, const std::string filePath) {
        mode = location;
        switch (mode) {
            case Location::Console:
                file.close();
                break;

            case Location::ConsoleAndFile:
            case Location::File:
                file = std::ofstream(filePath, std::ofstream::app);
                break;
        }
    }

    void logInfo(const std::string message) {
        if (static_cast<int>(level) <= static_cast<int>(Level::Info)) {
            log("[INFO]", message);
        }
    }

    void logInfo(const QString & message) {
        logInfo(message.toStdString());
    }

    void logWarning(const std::string message) {
        if (static_cast<int>(level) <= static_cast<int>(Level::Info)) {
            log("[WARN]", message);
        }
    }

    void logWarning(const QString & message) {
        logWarning(message.toStdString());
    }

    void logError(const std::string message) {
        if (static_cast<int>(level) <= static_cast<int>(Level::Info)) {
            log("[ERR] ", message);
        }
    }

    void logError(const QString & message) {
        logError(message.toStdString());
    }
};
