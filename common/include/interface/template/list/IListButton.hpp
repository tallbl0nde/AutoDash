#ifndef INTERFACE_TEMPLATE_LIST_ILISTBUTTON_HPP
#define INTERFACE_TEMPLATE_LIST_ILISTBUTTON_HPP

#include <string>

#include "interface/template/list/IListItem.hpp"

namespace Template {
    // Represents a horizontal list entry which acts as a button.
    class IListButton : public IListItem {
        signals:
            // Signal fired when the list button is pressed.
            virtual void pressed() = 0;

        public:
            // Sets the (optional) icon for the button.
            virtual void setIcon(QWidget * icon) = 0;

            // Sets the label for the button.
            virtual void setLabel(const std::string label) = 0;
    };
};

Q_DECLARE_INTERFACE(Template::IListButton, "TemplateIListButton");

#endif