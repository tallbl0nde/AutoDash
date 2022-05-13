#ifndef TEMPLATE_LIST_LISTBUTTON_HPP
#define TEMPLATE_LIST_LISTBUTTON_HPP

#include <QHBoxLayout>
#include <QLabel>

#include "widget/BaseClickable.hpp"
#include "interface/template/list/IListButton.hpp"

namespace Template {
    // Implementation of a ListButton.
    class ListButton : public Widget::BaseClickable, public IListButton {
        Q_OBJECT
        Q_INTERFACES(Template::IListButton)

        private:
            // Main layout.
            QHBoxLayout * layout;

            // Icon widget.
            QWidget * icon;

            // Label widget.
            QLabel * label;

        public:
            // Constructs a new ListButton.
            ListButton(QWidget * parent = nullptr);

            // Implement IListButton.
            QWidget * widget() override;

        public slots:
            // Implement IListButton.
            void setIcon(QWidget * icon) override;
            void setLabel(const std::string label) override;
    };
};

#endif