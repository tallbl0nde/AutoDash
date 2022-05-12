#ifndef TEMPLATE_LIST_LISTSEPARATOR_HPP
#define TEMPLATE_LIST_LISTSEPARATOR_HPP

#include "interface/template/list/IListSeparator.hpp"

namespace Template {
    // Template for a ListSeparator.
    class ListSeparator : public QWidget, public IListSeparator {
        public:
            // Creates a new separator.
            ListSeparator(QWidget * parent = nullptr);

            // Implement IListSeparator.
            QWidget * widget() override;
    };
};

#endif