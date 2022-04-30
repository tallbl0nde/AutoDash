#include "settings/StringSettingEntry.hpp"

StringSettingEntry::StringSettingEntry(const std::string & name, const std::string & description, const std::string & value, const StringHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->onChange_ = onChange;
}

std::string StringSettingEntry::value() {
    return this->value_;
}

void StringSettingEntry::setValue(const std::string & value) {
    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}