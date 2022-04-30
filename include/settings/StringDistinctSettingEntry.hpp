#ifndef SETTINGS_STRINGDISTINCTSETTINGENTRY_HPP
#define SETTINGS_STRINGDISTINCTSETTINGENTRY_HPP

#include <vector>

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a string (select from distinct values) setting.
class StringDistinctSettingEntry : public SettingEntry {
    private:
        // Current value.
        std::string value_;

        // Permitted values.
        std::vector<std::string> permittedValues_;

        // Handler to invoke when value changed.
        StringHandler onChange_;

    public:
        // Creates a new StringDistinctSettingEntry.
        StringDistinctSettingEntry(const std::string & name, const std::string & description, const std::string & value, const std::vector<std::string> & permittedValues, const StringHandler & onChange);

        // Returns the current value.
        std::string value();

        // Returns the permitted values.
        std::vector<std::string> permittedValues();

        // Sets a new value. No effect if not a permitted value.
        void setValue(const std::string value);
};

#endif