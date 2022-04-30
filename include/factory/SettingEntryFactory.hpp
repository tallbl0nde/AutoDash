#ifndef FACTORY_SETTINGENTRYFACTORY_HPP
#define FACTORY_SETTINGENTRYFACTORY_HPP

#include "interface/factory/ISettingEntryFactory.hpp"

class SettingEntryFactory : public ISettingEntryFactory {
    public:
        // Creates a new factory.
        SettingEntryFactory();

        // Implement ISettingEntryFactory.
        virtual ISettingEntry * createBoolEntry(const std::string & name, const std::string & description, const bool value, const BoolHandler & onChange) override;
        virtual ISettingEntry * createIntDistinctEntry(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) override;
        virtual ISettingEntry * createIntRangeEntry(const std::string & name, const std::string & description, const int value, const int min, const int max, const int step, const IntHandler & onChange) override;
        virtual ISettingEntry * createFloatDistinctEntry(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) override;
        virtual ISettingEntry * createFloatRangeEntry(const std::string & name, const std::string & description, const float value, const float min, const float max, const float step, const FloatHandler & onChange) override;
        virtual ISettingEntry * createStringEntry(const std::string & name, const std::string & description, const std::string & value, const StringHandler & onChange) override;
        virtual ISettingEntry * createStringDistinctEntry(const std::string & name, const std::string & description, const std::string & value, const std::vector<std::string> & permittedValues, const StringHandler & onChange) override;

};

#endif