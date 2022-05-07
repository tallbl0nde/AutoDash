#include "template/slider/HorizontalIntSlider.hpp"

namespace Template {
    HorizontalIntSlider::HorizontalIntSlider(QWidget * parent) : HorizontalSlider(parent) {
        this->action = nullptr;
    }

    void HorizontalIntSlider::onValueChanged(int value) {
        if (this->action != nullptr) {
            this->action(value);
        }

        this->onValueChanged_(value);
    }

    void HorizontalIntSlider::setSliderAction(const IntHandler & action) {
        this->action = action;
    }

    void HorizontalIntSlider::setSliderMin(const int min) {
        this->setMin(min);
    }

    void HorizontalIntSlider::setSliderMax(const int max) {
        this->setMax(max);
    }

    void HorizontalIntSlider::setSliderStep(const int step) {
        this->setStep(step);
    }

    void HorizontalIntSlider::setSliderValue(const int value) {
        this->setValue(value);
    }
};