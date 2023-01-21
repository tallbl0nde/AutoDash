#ifndef INTERFACE_TEMPLATE_LIST_ILISTOPTION_HPP
#define INTERFACE_TEMPLATE_LIST_ILISTOPTION_HPP

#include "interface/template/list/IListItem.hpp"

namespace Template {
    // Base interface for a ListItem which displays an option.
    class IListOption : public IListItem {
        protected:
            // Sets the widget to place at the right-hand side of the widget.
            // The deriving class should call this on construction.
            virtual void setRightWidget(QWidget * widget) = 0;

        public slots:
            // Sets the (optional) icon for the option.
            virtual void setIcon(QWidget * icon) = 0;

            // Sets the label for the option.
            virtual void setLabel(const std::string label) = 0;

            // Sets the (optional) description for the option.
            virtual void setDescription(const std::string description) = 0;
    };
};

Q_DECLARE_INTERFACE(Template::IListOption, "TemplateIListOption");

#endif