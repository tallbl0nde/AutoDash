#ifndef INTERFACE_ISETTINGENTRY_HPP
#define INTERFACE_ISETTINGENTRY_HPP

#include <string>
// Represents a single setting.
class ISettingEntry {
    public:
        // Returns the name of the setting.
        virtual std::string name() = 0;

        // Returns the description for the setting.
        virtual std::string description() = 0;

        virtual ~ISettingEntry() {};
};

#endif