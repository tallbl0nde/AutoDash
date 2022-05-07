#ifndef INTERFACE_TEMPLATE_SLIDER_IHORIZONTALINTSLIDER_HPP
#define INTERFACE_TEMPLATE_SLIDER_IHORIZONTALINTSLIDER_HPP

#include "interface/template/slider/IHorizontalSlider.hpp"
#include "Typedefs.hpp"

namespace Template {
    // Template for a horizontal slider using an int.
    class IHorizontalIntSlider : virtual public IHorizontalSlider {
        public:
            // Sets the method to invoke when the slider is changed.
            virtual void setSliderAction(const IntHandler & action) = 0;

            // Sets the minimum bound of the slider.
            virtual void setSliderMin(const int min) = 0;

            // Sets the maximum bound of the slider.
            virtual void setSliderMax(const int max) = 0;

            // Sets the slider step amount.
            virtual void setSliderStep(const int step) = 0;

            // Sets the slider value.
            virtual void setSliderValue(const int value) = 0;
    };
};

#endif