#ifndef TEMPLATE_LIST_LISTOPTIONCOMBOBOX_HPP
#define TEMPLATE_LIST_LISTOPTIONCOMBOBOX_HPP

#include "template/list/ListOption.hpp"
#include "Typedefs.hpp"

namespace Template {
    class ListOptionComboBox : public ListOption {
        public:
            // Constructs a new ListOptionComboBox with the given parameters.
            ListOptionComboBox(const std::string & name, const std::string & description, const std::string value, const std::vector<std::string> permittedValues, const StringHandler & onChange);
    };
};

#endif