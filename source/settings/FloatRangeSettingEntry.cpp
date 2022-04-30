#include "settings/FloatRangeSettingEntry.hpp"

FloatRangeSettingEntry::FloatRangeSettingEntry(const std::string & name, const std::string & description, const float value, const float min, const float max, const float step, const FloatHandler & onChange) : SettingEntry(name, description) {
    this->value_ = value;
    this->min_ = min;
    this->max_ = max;
    this->step_ = step;
    this->onChange_ = onChange;
}

float FloatRangeSettingEntry::value() {
    return this->value_;
}

float FloatRangeSettingEntry::min() {
    return this->min_;
}

float FloatRangeSettingEntry::max() {
    return this->max_;
}

float FloatRangeSettingEntry::step() {
    return this->step_;
}

void FloatRangeSettingEntry::setValue(const float value) {
    this->value_ = value;
    if (this->onChange_ != nullptr) {
        this->onChange_(value);
    }
}