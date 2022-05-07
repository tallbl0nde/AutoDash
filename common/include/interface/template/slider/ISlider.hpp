#ifndef INTERFACE_TEMPLATE_SLIDER_ISLIDER_HPP
#define INTERFACE_TEMPLATE_SLIDER_ISLIDER_HPP

#include <functional>

#include "interface/template/ITemplate.hpp"

namespace Template {
    // Template for a slider (for choosing values).
    class ISlider : virtual public ITemplate {
        public slots:
            // Sets the accent colour in the slider.
            virtual void setAccentColour(int r, int g, int b) = 0;

        public:
            // Sets the method to invoke which formats the label to display.
            virtual void setLabelFormatter(const std::function<std::string(int)> & formatter) = 0;

            virtual ~ISlider() {};
    };
};

Q_DECLARE_INTERFACE(Template::ISlider, "TemplateISlider");

#endif