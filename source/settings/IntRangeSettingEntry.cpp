#include "settings/IntRangeSettingEntry.hpp"

IntRangeSettingEntry::IntRangeSettingEntry(const std::string & name, const std::string & description, const int value, const int min, const int max, const int step, const IntHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->min_ = min;
    this->max_ = max;
    this->step_ = step;
    this->onChange_ = onChange;
}

int IntRangeSettingEntry::value() {
    return this->value_;
}

int IntRangeSettingEntry::min() {
    return this->min_;
}

int IntRangeSettingEntry::max() {
    return this->max_;
}

int IntRangeSettingEntry::step() {
    return this->step_;
}

void IntRangeSettingEntry::setValue(const int value) {
    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}