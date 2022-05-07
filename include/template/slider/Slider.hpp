#ifndef TEMPLATE_SLIDER_SLIDER_HPP
#define TEMPLATE_SLIDER_SLIDER_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QWidget>

#include "interface/template/slider/ISlider.hpp"

namespace Template {
    // Base slider class.
    class Slider : public QWidget, virtual public ISlider {
        Q_OBJECT
        Q_INTERFACES(Template::ISlider)

        private:
            // Actual slider
            QSlider * slider;

            // Label for value
            QLabel * valueLabel;

            // Label formatter.
            std::function<std::string(int)> labelFormatter;

            // Sets up the child widgets.
            void initializeWidget(Qt::Orientation orientation);

        protected slots:
            // Invoked whenever the slider's value changes.
            // Should invoke onValueChanged_().
            virtual void onValueChanged(int value) = 0;

        protected:
            void onValueChanged_(int value);

            // Sets the minimum bound of the slider.
            void setMin(const int min);

            // Sets the maximum bound of the slider.
            void setMax(const int max);

            // Sets the slider step amount.
            void setStep(const int step);

            // Sets the slider value.
            void setValue(const int value);

        public:
            // Constructs a new Slider.
            Slider(Qt::Orientation orientation, QWidget * parent = nullptr);

            ~Slider();

            // Implement ISlider.
            void setLabelFormatter(const std::function<std::string(int)> & formatter);
            QWidget * widget() override;

        public slots:
            void setAccentColour(int r, int g, int b) override;
    };
};

#endif