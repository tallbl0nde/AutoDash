#include <sstream>

#include "template/slider/Slider.hpp"
#include "Typedefs.hpp"

namespace Template {
    Slider::Slider(Qt::Orientation orientation, QWidget * parent) : QWidget(parent) {
        this->labelFormatter = nullptr;

        this->initializeWidget(orientation);
        QWidget::connect(this->slider, &QSlider::valueChanged, this, &Slider::onValueChanged);
    }

    void Slider::initializeWidget(Qt::Orientation orientation) {
        // TODO_JG: Depends on orientation
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setSpacing(20);

        // Slider
        this->slider = new QSlider(orientation, this);
        this->setAccentColour(20, 20, 20);
        layout->addWidget(this->slider);

        // Label
        QFont font("Rubik");    // TODO_JG: Config
        font.setBold(true);
        font.setPointSize(16);

        this->valueLabel = new QLabel(this);
        this->valueLabel->setFont(font);
        this->valueLabel->setStyleSheet("color: white");

        layout->addWidget(this->valueLabel);
    }

    void Slider::onValueChanged_(int value) {
        QString labelText = QString::fromStdString(this->labelFormatter ? this->labelFormatter(value) : std::to_string(value));
        this->valueLabel->setText(labelText);
    }

    void Slider::setMin(const int min) {
        this->slider->setMinimum(min);
    }

    void Slider::setMax(const int max) {
        this->slider->setMaximum(max);
    }

    void Slider::setStep(const int step) {
        this->slider->setSingleStep(step);
    }

    void Slider::setValue(const int value) {
        this->slider->setValue(value);
    }

    void Slider::setLabelFormatter(const std::function<std::string(int)> & formatter) {
        this->labelFormatter = formatter;
    }

    QWidget * Slider::widget() {
        return this;
    }

    void Slider::setAccentColour(int r, int g, int b) {
        // Convert to hex string
        std::stringstream ss;
        ss << std::hex << "#" << (r << 16 | g << 8 | b);
        QString hex = QString::fromStdString(ss.str());

        this->slider->setStyleSheet(
            ".QSlider {                         "
            "    min-height: 50px;              "
            "    max-height: 50px;              "
            "}                                  "
            "                                   "
            ".QSlider::groove:horizontal {      "
            "    border: 1px solid #000000;     "
            "    height: 12px;                  "
            "    margin: 0 12px;                "
            "}                                  "
            "                                   "
            ".QSlider::handle:horizontal {      "
            "    background: #303030;           "
            "    border: 2px solid #202020;     "
            "    border-radius: 20px;           "
            "    width: 40px;                   "
            "    height: 40px;                  "
            "    margin: -16px -12px;           "
            "}                                  "
            "                                   "
            "QSlider::add-page:horizontal{      "
            "    border-radius: 6px;            "
            "    border: 2px solid #000000;     "
            "    background: #404040;           "
            "}                                  "
            "                                   "
            "QSlider::sub-page:horizontal{      "
            "    border-radius: 6px;            "
            "    border: 2px solid #000000;     "
            "    background: " + hex + "        "
            "}                                  "
        );
    }

    Slider::~Slider() {

    }
};