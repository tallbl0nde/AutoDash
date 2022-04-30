#ifndef SETTINGS_INTDISTINCTSETTINGENTRY_HPP
#define SETTINGS_INTDISTINCTSETTINGENTRY_HPP

#include <vector>

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a integer (select from distinct values) setting.
class IntDistinctSettingEntry : public SettingEntry {
    private:
        // Current value.
        int value_;

        // Permitted values.
        std::vector<int> permittedValues_;

        // Handler to invoke when value changed.
        IntHandler onChange_;

    public:
        // Creates a new IntDistinctSettingEntry.
        IntDistinctSettingEntry(const std::string & name, const std::string & description, const int value, const std::vector<int> & permittedValues, const IntHandler & onChange);

        // Returns the current value.
        int value();

        // Returns the permitted values.
        std::vector<int> permittedValues();

        // Sets a new value. No effect if not a permitted value.
        void setValue(const int value);
};

#endif