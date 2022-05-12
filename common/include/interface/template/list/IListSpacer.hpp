#ifndef INTERFACE_TEMPLATE_LIST_ILISTSPACER_HPP
#define INTERFACE_TEMPLATE_LIST_ILISTSPACER_HPP

#include "interface/template/list/IListItem.hpp"

namespace Template {
    class IListSpacer : public IListItem {
        public:
            // TODO: Make a slot
            // Sets the size of the spacer, in pixels.
            virtual void setSize(const int size) = 0;
    };
};

#endif