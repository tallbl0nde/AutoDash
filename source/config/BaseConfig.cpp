#include "config/BaseConfig.hpp"

BaseConfig::BaseConfig() {
    this->backgroundImageFilePath_ = ":/backgrounds/background.png";
    this->modulesFolderPath_ = "/home/jonathon/AutoDash/modules/";
    this->resourcesFolderPath_ = "/home/jonathon/AutoDash/resources/";
    this->fontFamily_ = "Rubik";
    this->fontSize_ = 18;
    this->backgroundColour_ = {0, 0, 0, 100};
    this->mainTextColour_ = {255, 255, 255, 255};
}

std::string BaseConfig::backgroundImageFilePath() {
    return this->backgroundImageFilePath_;
}

bool BaseConfig::setBackgroundImageFilePath(const std::string path) {
    this->backgroundImageFilePath_ = path;
    return true;
}

std::string BaseConfig::modulesFolderPath() {
    return this->modulesFolderPath_;
}

bool BaseConfig::setModulesFolderPath(const std::string path) {
    this->modulesFolderPath_ = path;
    return true;
}

std::string BaseConfig::resourcesFolderPath() {
    return this->resourcesFolderPath_;
}

bool BaseConfig::setResourcesFolderPath(const std::string path) {
    this->resourcesFolderPath_ = path;
    return true;
}

std::string BaseConfig::fontFamily() {
    return this->fontFamily_;
}

bool BaseConfig::setFontFamily(const std::string family) {
    this->fontFamily_ = family;
    return true;
}

int BaseConfig::fontSize() {
    return this->fontSize_;
}

bool BaseConfig::setFontSize(const int size) {
    this->fontSize_ = size;
    return true;
}

IConfig::Colour BaseConfig::backgroundColour() {
    return this->backgroundColour_;
}

bool BaseConfig::setBackgroundColour(const IConfig::Colour colour) {
    this->backgroundColour_ = colour;
    return true;
}

IConfig::Colour BaseConfig::mainTextColour() {
    return this->mainTextColour_;
}

bool BaseConfig::setMainTextColour(const IConfig::Colour colour) {
    this->mainTextColour_ = colour;
    return true;
}

BaseConfig::~BaseConfig() {

}
