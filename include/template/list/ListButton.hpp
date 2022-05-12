#ifndef TEMPLATE_LIST_LISTBUTTON_HPP
#define TEMPLATE_LIST_LISTBUTTON_HPP

#include <QColor>
#include <QHBoxLayout>
#include <QLabel>
#include <QPaintEvent>

#include "interface/IClickable.hpp"
#include "interface/template/list/IListButton.hpp"

namespace Template {
    // Implementation of a ListButton.
    class ListButton : public IClickable, public IListButton {
        Q_OBJECT
        Q_INTERFACES(Template::IListButton)

        private:
            // Colour when clicked.
            QColor clickedColour;

            // Main layout.
            QHBoxLayout * layout;

            // Icon widget.
            QWidget * icon;

            // Label widget.
            QLabel * label;

        protected:
            // Override to draw click highlight.
            void paintEvent(QPaintEvent * event) override;

            // Implement IClickable.
            void onClick() override;
            void onRegainedFocus() override;
            void onLostFocus() override;
            void onRelease() override;

        signals:
            void pressed() override;

        public:
            ListButton(QWidget * parent = nullptr);

            // Implement IListButton.
            void setIcon(QWidget * icon) override;
            void setLabel(const std::string label) override;
            QWidget * widget() override;
    };
};

#endif