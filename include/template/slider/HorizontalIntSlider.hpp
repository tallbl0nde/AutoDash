#ifndef TEMPLATE_SLIDER_HORIZONTALINTSLIDER_HPP
#define TEMPLATE_SLIDER_HORIZONTALINTSLIDER_HPP

#include "interface/template/slider/IHorizontalIntSlider.hpp"
#include "template/slider/HorizontalSlider.hpp"
#include "Typedefs.hpp"

namespace Template {
    class HorizontalIntSlider : public HorizontalSlider, public IHorizontalIntSlider {
        Q_OBJECT

        private:
            // Action to invoke when value changes.
            IntHandler action;

        protected slots:
            // Implement HorizontalSlider methods.
            void onValueChanged(int value) override;

        public:
            // Constructs a new HorizontalIntSlider.
            HorizontalIntSlider(QWidget * parent = nullptr);

            // Implement IHorizontalIntSlider.
            void setSliderAction(const IntHandler & action) override;
            void setSliderMin(const int min) override;
            void setSliderMax(const int max) override;
            void setSliderStep(const int step) override;
            void setSliderValue(const int value) override;
    };
};

#endif