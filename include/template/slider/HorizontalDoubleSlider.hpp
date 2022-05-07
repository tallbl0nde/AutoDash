#ifndef TEMPLATE_SLIDER_HORIZONTALDOUBLESLIDER_HPP
#define TEMPLATE_SLIDER_HORIZONTALDOUBLESLIDER_HPP

#include "interface/template/slider/IHorizontalDoubleSlider.hpp"
#include "template/slider/HorizontalSlider.hpp"
#include "Typedefs.hpp"

namespace Template {
    class HorizontalDoubleSlider : public HorizontalSlider, public IHorizontalDoubleSlider {
        Q_OBJECT

        private:
            // Method to invoke when the slider's value changes.
            DoubleHandler action;

        protected slots:
            // Implement HorizontalSlider methods.
            void onValueChanged(int value) override;

        public:
            // Constructs a new HorizontalDoubleSlider.
            HorizontalDoubleSlider(QWidget * parent = nullptr);

            // Implement IHorizontalDoubleSlider.
            void setSliderAction(const DoubleHandler & action) override;
            void setSliderMin(const double min) override;
            void setSliderMax(const double max) override;
            void setSliderStep(const double step) override;
            void setSliderValue(const double value) override;
    };
};

#endif