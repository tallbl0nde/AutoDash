#ifndef SETTINGS_FLOATDISTINCTSETTINGENTRY_HPP
#define SETTINGS_FLOATDISTINCTSETTINGENTRY_HPP

#include <vector>

#include "settings/SettingEntry.hpp"
#include "Typedefs.hpp"

// Represents a float (select from distinct values) setting.
class FloatDistinctSettingEntry : public SettingEntry {
    private:
        // Current value.
        float value_;

        // Permitted values.
        std::vector<float> permittedValues_;

        // Handler to invoke when value changed.
        FloatHandler onChange_;

    public:
        // Creates a new FloatDistinctSettingEntry.
        FloatDistinctSettingEntry(const std::string & name, const std::string & description, const float value, const std::vector<float> & permittedValues, const FloatHandler & onChange);

        // Returns the current value.
        float value();

        // Returns the permitted values.
        std::vector<float> permittedValues();

        // Sets a new value. No effect if not a permitted value.
        void setValue(const float value);
};

#endif