#ifndef INTERFACE_TEMPLATE_LIST_ILIST_HPP
#define INTERFACE_TEMPLATE_LIST_ILIST_HPP

#include "interface/template/list/IListItem.hpp"
#include "interface/template/ITemplate.hpp"

namespace Template {
    // Represents a list containing one or more IListItems.
    class IList : public ITemplate {
        public:
            // Adds an IListItem to the list.
            // Items are added underneath any other items.
            virtual void addItem(IListItem * item) = 0;

            // Removes the IListItem from the list.
            // The item is not deleted.
            virtual bool removeItem(IListItem * item) = 0;

            virtual ~IList() {};
    };
};

#endif