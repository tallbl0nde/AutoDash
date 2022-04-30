#include <algorithm>

#include "settings/StringDistinctSettingEntry.hpp"

StringDistinctSettingEntry::StringDistinctSettingEntry(const std::string & name, const std::string & description, const std::string & value, const std::vector<std::string> & permittedValues, const StringHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->permittedValues_ = permittedValues;
    this->onChange_ = onChange;
}

std::string StringDistinctSettingEntry::value() {
    return this->value_;
}

std::vector<std::string> StringDistinctSettingEntry::permittedValues() {
    return this->permittedValues_;
}

void StringDistinctSettingEntry::setValue(const std::string value) {
    if (std::find(this->permittedValues_.begin(), this->permittedValues_.end(), value) == this->permittedValues_.end()) {
        return;
    }

    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}