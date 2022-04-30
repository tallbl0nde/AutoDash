#ifndef SETTINGS_FLOATRANGESETTINGENTRY_HPP
#define SETTINGS_FLOATRANGESETTINGENTRY_HPP

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a float (within range) setting.
class FloatRangeSettingEntry : public SettingEntry {
    private:
        // Current value.
        float value_;

        // Minimum value.
        float min_;

        // Maximum value.
        float max_;

        // Step value.
        float step_;

        // Handler to invoke when value changed.
        FloatHandler onChange_;

    public:
        // Creates a new FloatRangeSettingEntry.
        FloatRangeSettingEntry(const std::string & name, const std::string & description, const float value, const float min, const float max, const float step, const FloatHandler & onChange);

        // Returns the current value.
        float value();

        // Returns the minimum allowed value.
        float min();

        // Returns the maximum allowed value.
        float max();

        // Returns the step amount.
        float step();

        // Sets a new value.
        void setValue(const float value);
};

#endif