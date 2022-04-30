#ifndef INTERFACE_FACTORY_ISETTINGENTRYFACTORY_HPP
#define INTERFACE_FACTORY_ISETTINGENTRYFACTORY_HPP

#include <string>
#include <vector>

#include "interface/ISettingEntry.hpp"
#include "Typedefs.hpp"

// Factory for creating IEntry objects.
class ISettingEntryFactory {
    public:
        // Creates a new BoolEntry.
        virtual ISettingEntry * createBoolEntry(const std::string & name, const std::string & description, const bool value, const BoolHandler & onChange) = 0;

        // Creates a new IntDistinctEntry.
        virtual ISettingEntry * createIntDistinctEntry(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) = 0;

        // Creates a new IntDistinctEntry.
        virtual ISettingEntry * createIntRangeEntry(const std::string & name, const std::string & description, const int value, const int min, const int max, const int step, const IntHandler & onChange) = 0;

        // Creates a new FloatDistinctEntry.
        virtual ISettingEntry * createFloatDistinctEntry(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) = 0;

        // Creates a new FloatDistinctEntry.
        virtual ISettingEntry * createFloatRangeEntry(const std::string & name, const std::string & description, const float value, const float min, const float max, const float step, const FloatHandler & onChange) = 0;

        // Creates a new StringEntry.
        virtual ISettingEntry * createStringEntry(const std::string & name, const std::string & description, const std::string & value, const StringHandler & onChange) = 0;

        // Creates a new StringDistinctEntry.
        virtual ISettingEntry * createStringDistinctEntry(const std::string & name, const std::string & description, const std::string & value, const std::vector<std::string> & permittedValues, const StringHandler & onChange) = 0;

        virtual ~ISettingEntryFactory() {};
};

#endif