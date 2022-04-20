#ifndef INTERFACE_TEMPLATE_ITEMPLATE_HPP
#define INTERFACE_TEMPLATE_ITEMPLATE_HPP

#include <QWidget>

namespace Template {
    // Base template interface.
    class ITemplate {
        public:
            // Returns the widget the template uses.
            virtual QWidget * widget() = 0;

            virtual ~ITemplate() {};
    };
};

#endif