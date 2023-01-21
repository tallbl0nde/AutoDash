#ifndef INTERFACE_FACTORY_ILISTOPTIONFACTORY_HPP
#define INTERFACE_FACTORY_ILISTOPTIONFACTORY_HPP

#include <string>
#include <vector>

#include "interface/template/list/IListOption.hpp"
#include "Typedefs.hpp"

// Factory for creating IListOption objects.
class IListOptionFactory {
    public:
        // Creates a new ListOptionComboBox.
        virtual Template::IListOption * createComboBox(const std::string & name, const std::string & description, const int value, const std::vector<int> permittedValues, const IntHandler & onChange) = 0;
        virtual Template::IListOption * createComboBox(const std::string & name, const std::string & description, const float value, const std::vector<float> permittedValues, const FloatHandler & onChange) = 0;
        virtual Template::IListOption * createComboBox(const std::string & name, const std::string & description, const std::string value, const std::vector<std::string> permittedValues, const StringHandler & onChange) = 0;

        virtual ~IListOptionFactory() {};
};

#endif