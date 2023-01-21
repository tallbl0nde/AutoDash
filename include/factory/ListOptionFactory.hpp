#ifndef FACTORY_LISTOPTIONFACTORY_HPP
#define FACTORY_LISTOPTIONFACTORY_HPP

#include "interface/factory/IListOptionFactory.hpp"

class ListOptionFactory : public IListOptionFactory {
    public:
        // Implement IListOptionFactory.
        Template::IListOption * createComboBox(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) override;
        Template::IListOption * createComboBox(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) override;
        Template::IListOption * createComboBox(const std::string & name, const std::string & description, const std::string value, const std::vector<std::string> permittedValues, const StringHandler & onChange) override;
};

#endif