#ifndef INTERFACE_TEMPLATE_SLIDER_IHORIZONTALDOUBLESLIDER_HPP
#define INTERFACE_TEMPLATE_SLIDER_IHORIZONTALDOUBLESLIDER_HPP

#include "interface/template/slider/IHorizontalSlider.hpp"
#include "Typedefs.hpp"

namespace Template {
    // Template for a horizontal slider using a double.
    class IHorizontalDoubleSlider : virtual public IHorizontalSlider {
        public:
            // Sets the method to invoke when the slider is changed.
            virtual void setSliderAction(const DoubleHandler & action) = 0;

            // Sets the minimum bound of the slider.
            virtual void setSliderMin(const double min) = 0;

            // Sets the maximum bound of the slider.
            virtual void setSliderMax(const double max) = 0;

            // Sets the slider step amount.
            virtual void setSliderStep(const double step) = 0;

            // Sets the slider value.
            virtual void setSliderValue(const double value) = 0;
    };
};

#endif