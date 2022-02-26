#ifndef CONFIG_MEMORYCONFIG_HPP
#define CONFIG_MEMORYCONFIG_HPP

#include "interface/IConfig.hpp"

// In-memory configuration. Resets to default values
// each launch (obviously).
class BaseConfig : public IConfig {
    private:
        std::string backgroundImageFilePath_;
        std::string modulesFolderPath_;
        std::string resourcesFolderPath_;
        std::string fontFamily_;
        int fontSize_;
        IConfig::Colour backgroundColour_;
        IConfig::Colour mainTextColour_;

    public:
        BaseConfig();

        std::string backgroundImageFilePath();
        bool setBackgroundImageFilePath(const std::string);

        std::string modulesFolderPath();
        bool setModulesFolderPath(const std::string);

        std::string resourcesFolderPath();
        bool setResourcesFolderPath(const std::string);

        std::string fontFamily();
        bool setFontFamily(const std::string);

        int fontSize();
        bool setFontSize(const int);

        IConfig::Colour backgroundColour();
        bool setBackgroundColour(const IConfig::Colour);

        IConfig::Colour mainTextColour();
        bool setMainTextColour(const IConfig::Colour);

        ~BaseConfig();
};

#endif
