#ifndef TEMPLATE_SLIDER_HORIZONTALSLIDER_HPP
#define TEMPLATE_SLIDER_HORIZONTALSLIDER_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QWidget>

#include "interface/template/slider/IHorizontalSlider.hpp"
#include "template/slider/Slider.hpp"

namespace Template {
    // Base horizontal slider class.
    class HorizontalSlider : public Slider, virtual public IHorizontalSlider {
        public:
            // Constructs a new HorizontalSlider.
            HorizontalSlider(QWidget * parent = nullptr);
    };
};

#endif