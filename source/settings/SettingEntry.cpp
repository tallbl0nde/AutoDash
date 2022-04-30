#include "settings/SettingEntry.hpp"

SettingEntry::SettingEntry(const std::string & name, const std::string & description) {
    this->name_ = name;
    this->description_ = description;
}

std::string SettingEntry::name() {
    return this->name_;
}

std::string SettingEntry::description() {
    return this->description_;
}