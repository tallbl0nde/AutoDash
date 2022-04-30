#include <algorithm>

#include "settings/IntDistinctSettingEntry.hpp"

IntDistinctSettingEntry::IntDistinctSettingEntry(const std::string & name, const std::string & description, const int value, const std::vector<int> & permittedValues, const IntHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->permittedValues_ = permittedValues;
    this->onChange_ = onChange;
}

int IntDistinctSettingEntry::value() {
    return this->value_;
}

std::vector<int> IntDistinctSettingEntry::permittedValues() {
    return this->permittedValues_;
}

void IntDistinctSettingEntry::setValue(const int value) {
    if (std::find(this->permittedValues_.begin(), this->permittedValues_.end(), value) == this->permittedValues_.end()) {
        return;
    }

    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}