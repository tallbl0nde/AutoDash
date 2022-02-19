#include <stdexcept>

#include "config/BaseConfig.hpp"
#include "factory/ConfigFactory.hpp"

IConfig * ConfigFactory::instance = nullptr;

ConfigFactory::ConfigFactory() {

}

IConfig * ConfigFactory::getConfig() {
    if (instance == nullptr) {
        this->changeConfigType(ConfigType::Base);
    }

    return instance;
}

void ConfigFactory::deleteConfigObject() {
    delete instance;
}

void ConfigFactory::changeConfigType(const ConfigType type) {
    switch (type) {
        case ConfigType::Base:
            this->deleteConfigObject();
            instance = new BaseConfig();
            break;

        default:
            throw new std::invalid_argument("ConfigFactory::changeConfigType(): Invalid ConfigType");
    }
}

ConfigFactory::~ConfigFactory() {

}
