#include "factory/ListOptionFactory.hpp"
#include "template/list/ListOptionComboBox.hpp"

Template::IListOption * ListOptionFactory::createComboBox(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) {
    // return new Template::ListOptionComboBox();
    return nullptr;
}

Template::IListOption * ListOptionFactory::createComboBox(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) {
    // return new Template::ListOptionComboBox();
    return nullptr;
}

Template::IListOption * ListOptionFactory::createComboBox(const std::string & name, const std::string & description, const std::string value, const std::vector<std::string> permittedValues, const StringHandler & onChange) {
    return new Template::ListOptionComboBox(name, description, value, permittedValues, onChange);
}
