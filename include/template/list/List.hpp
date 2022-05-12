#ifndef TEMPLATE_LIST_LIST_HPP
#define TEMPLATE_LIST_LIST_HPP

#include <QScrollArea>
#include <QVBoxLayout>

#include "interface/template/list/IList.hpp"

namespace Template {
    // Template for a list.
    class List : public QScrollArea, public IList {
        private:
            // Inner widget.
            QWidget * innerWidget;

            // Inner widget layout.
            QVBoxLayout * innerLayout;

        public:
            // Creates a new List.
            List(QWidget * parent = nullptr);

            // Implement IList.
            void addItem(IListItem * item) override;
            bool removeItem(IListItem * item) override;
            QWidget * widget() override;
    };
};

#endif