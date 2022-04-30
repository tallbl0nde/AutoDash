#ifndef SETTINGS_INTRANGESETTINGENTRY_HPP
#define SETTINGS_INTRANGESETTINGENTRY_HPP

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a integer (within range) setting.
class IntRangeSettingEntry : public SettingEntry {
    private:
        // Current value.
        int value_;

        // Minimum value.
        int min_;

        // Maximum value.
        int max_;

        // Step value.
        int step_;

        // Handler to invoke when value changed.
        IntHandler onChange_;

    public:
        // Creates a new IntRangeSettingEntry.
        IntRangeSettingEntry(const std::string & name, const std::string & description, const int value, const int min, const int max, const int step, const IntHandler & onChange);

        // Returns the current value.
        int value();

        // Returns the minimum allowed value.
        int min();

        // Returns the maximum allowed value.
        int max();

        // Returns the step amount.
        int step();

        // Sets a new value.
        void setValue(const int value);
};

#endif