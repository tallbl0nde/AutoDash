#ifndef INTERFACE_TEMPLATE_LIST_ILISTITEM_HPP
#define INTERFACE_TEMPLATE_LIST_ILISTITEM_HPP

#include "interface/template/ITemplate.hpp"

namespace Template {
    // Represents a templated entry within a list.
    class IListItem : public ITemplate {
        public:
            virtual ~IListItem() {};
    };
};

#endif