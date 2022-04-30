#include "settings/BoolSettingEntry.hpp"

BoolSettingEntry::BoolSettingEntry(const std::string & name, const std::string & description, const bool value, const BoolHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->onChange_ = onChange;
}

bool BoolSettingEntry::value() {
    return this->value_;
}

void BoolSettingEntry::setValue(const bool value) {
    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}