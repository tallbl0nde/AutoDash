#ifndef SETTINGS_SETTINGENTRY_HPP
#define SETTINGS_SETTINGENTRY_HPP

#include "interface/ISettingEntry.hpp"

// Base SettingEntry object. Contains common values.
class SettingEntry : public ISettingEntry {
    private:
        // Name of setting.
        std::string name_;

        // Description for setting.
        std::string description_;

    public:
        // Creates a new SettingEntry object.
        SettingEntry(const std::string & name, const std::string & description);

        // Implement ISettingEntry.
        std::string name();
        std::string description();
};

#endif