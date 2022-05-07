#include "template/slider/HorizontalDoubleSlider.hpp"

namespace Template {
    HorizontalDoubleSlider::HorizontalDoubleSlider(QWidget * parent) : HorizontalSlider(parent) {
        this->action = nullptr;
    }

    void HorizontalDoubleSlider::onValueChanged(int value) {
        if (this->action != nullptr) {
            this->action(value / 1000.0);
        }

        this->onValueChanged_(value / 1000.0);
    }

    void HorizontalDoubleSlider::setSliderAction(const DoubleHandler & action) {
        this->action = action;
    }

    void HorizontalDoubleSlider::setSliderMin(const double min) {
        this->setMin(min * 1000);
    }

    void HorizontalDoubleSlider::setSliderMax(const double max) {
        this->setMax(max * 1000);
    }

    void HorizontalDoubleSlider::setSliderStep(const double step) {
        this->setStep(step * 1000);
    }

    void HorizontalDoubleSlider::setSliderValue(const double value) {
        this->setValue(value * 1000);
    }
};