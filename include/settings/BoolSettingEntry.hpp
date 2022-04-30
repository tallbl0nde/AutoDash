#ifndef SETTINGS_BOOLSETTINGENTRY_HPP
#define SETTINGS_BOOLSETTINGENTRY_HPP

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a boolean setting.
class BoolSettingEntry : public SettingEntry {
    private:
        // Current value.
        bool value_;

        // Handler to invoke when value changed.
        BoolHandler onChange_;

    public:
        // Creates a new BoolSettingEntry.
        BoolSettingEntry(const std::string & name, const std::string & description, const bool value, const BoolHandler & onChange);

        // Returns the current value.
        bool value();

        // Sets a new value.
        void setValue(const bool value);
};

#endif