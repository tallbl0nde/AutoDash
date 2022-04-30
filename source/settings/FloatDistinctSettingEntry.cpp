#include <algorithm>

#include "settings/FloatDistinctSettingEntry.hpp"

FloatDistinctSettingEntry::FloatDistinctSettingEntry(const std::string & name, const std::string & description, const float value, const std::vector<float> & permittedValues, const FloatHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->permittedValues_ = permittedValues;
    this->onChange_ = onChange;
}

float FloatDistinctSettingEntry::value() {
    return this->value_;
}

std::vector<float> FloatDistinctSettingEntry::permittedValues() {
    return this->permittedValues_;
}

void FloatDistinctSettingEntry::setValue(const float value) {
    if (std::find(this->permittedValues_.begin(), this->permittedValues_.end(), value) == this->permittedValues_.end()) {
        return;
    }

    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}