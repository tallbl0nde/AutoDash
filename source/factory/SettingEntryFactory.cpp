#include "factory/SettingEntryFactory.hpp"
#include "settings/BoolSettingEntry.hpp"
#include "settings/IntDistinctSettingEntry.hpp"
#include "settings/IntRangeSettingEntry.hpp"
#include "settings/FloatDistinctSettingEntry.hpp"
#include "settings/FloatRangeSettingEntry.hpp"
#include "settings/StringSettingEntry.hpp"
#include "settings/StringDistinctSettingEntry.hpp"

SettingEntryFactory::SettingEntryFactory() {

}

ISettingEntry * SettingEntryFactory::createBoolEntry(const std::string & name, const std::string & description, const bool value, const BoolHandler & onChange) {
    return new BoolSettingEntry(name, description, value, onChange);
}

ISettingEntry * SettingEntryFactory::createIntDistinctEntry(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) {
    return new IntDistinctSettingEntry(name, description, value, permittedValues, onChange);
}

ISettingEntry * SettingEntryFactory::createIntRangeEntry(const std::string & name, const std::string & description, const int value, const int min, const int max, const int step, const IntHandler & onChange) {
    return new IntRangeSettingEntry(name, description, value, min, max, step, onChange);
}

ISettingEntry * SettingEntryFactory::createFloatDistinctEntry(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) {
    return new FloatDistinctSettingEntry(name, description, value, permittedValues, onChange);
}

ISettingEntry * SettingEntryFactory::createFloatRangeEntry(const std::string & name, const std::string & description, const float value, const float min, const float max, const float step, const FloatHandler & onChange) {
    return new FloatRangeSettingEntry(name, description, value, min, max, step, onChange);
}

ISettingEntry * SettingEntryFactory::createStringEntry(const std::string & name, const std::string & description, const std::string & value, const StringHandler & onChange) {
    return new StringSettingEntry(name, description, value, onChange);
}

ISettingEntry * SettingEntryFactory::createStringDistinctEntry(const std::string & name, const std::string & description, const std::string & value, const std::vector<std::string> & permittedValues, const StringHandler & onChange) {
    return new StringDistinctSettingEntry(name, description, value, permittedValues, onChange);
}

