#ifndef SETTINGS_STRINGSETTINGENTRY_HPP
#define SETTINGS_STRINGSETTINGENTRY_HPP

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a custom string setting.
class StringSettingEntry : public SettingEntry {
    private:
        // Current value.
        std::string value_;

        // Handler to invoke when value changed.
        StringHandler onChange_;

    public:
        // Creates a new StringSettingEntry.
        StringSettingEntry(const std::string & name, const std::string & description, const std::string & value, const StringHandler & onChange);

        // Returns the current value.
        std::string  value();

        // Sets a new value.
        void setValue(const std::string & value);
};

#endif