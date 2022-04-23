#ifndef INTERFACE_TEMPLATE_IBUTTON_HPP
#define INTERFACE_TEMPLATE_IBUTTON_HPP

#include <functional>

#include "interface/template/ITemplate.hpp"

namespace Template {
    // Template for a button.
    class IButton : public ITemplate {
        public:
            // Reset the colour of the button to it's default.
            virtual void resetButtonColour() = 0;

            // Sets the method to invoke when the button is clicked.
            virtual void setButtonAction(const std::function<void()> & action) = 0;

            // Sets the colour of button's background and icon/text.
            virtual void setButtonColour(QColor background, QColor foreground) = 0;

            // Sets the button icon (optional).
            virtual void setButtonIcon(QWidget * icon) = 0;

            // Sets the button text.
            virtual void setButtonText(const std::string & text) = 0;

            virtual ~IButton() {};
    };
};

#endif