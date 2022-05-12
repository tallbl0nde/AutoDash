#ifndef TEMPLATE_LIST_LISTSPACER_HPP
#define TEMPLATE_LIST_LISTSPACER_HPP

#include "interface/template/list/IListSpacer.hpp"

namespace Template {
    class ListSpacer : public QWidget, public IListSpacer {
        public:
            // Constructs a new ListSpacer, defaulting to 10px.
            ListSpacer(QWidget * parent = nullptr);

            // Implement IListSpacer.
            void setSize(const int size) override;
            QWidget * widget() override;
    };
};

#endif