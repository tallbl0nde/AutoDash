#include <QHBoxLayout>
#include <QPainter>

#include "widget/SVGLabel.hpp"
#include "Log.hpp"

namespace Widget {
    SVGLabel::SVGLabel(QWidget * parent) : IClickable(parent) {
        // Create layout
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setMargin(10);
        layout->setSpacing(10);

        // Insert widgets into layout
        this->backgroundColour = QColor(255, 255, 255, 0);
        this->label = new QLabel();
        this->svg = new QSvgWidget();

        layout->addWidget(this->svg);
        layout->addWidget(this->label);
    }

    void SVGLabel::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.fillRect(this->rect(), this->backgroundColour);
    }

    void SVGLabel::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of the svg to the height of the label (making it 1:1)
        int size = (this->size().height() - (this->layout()->margin()*2)) * 0.9;
        this->svg->setFixedSize(size, size);
    }

    void SVGLabel::onClick() {
        this->backgroundColour.setAlpha(50);
        this->update();
    }

    void SVGLabel::onRegainedFocus() {
        this->backgroundColour.setAlpha(50);
        this->update();
    }

    void SVGLabel::onLostFocus() {
        this->backgroundColour.setAlpha(20);
        this->update();
    }

    void SVGLabel::onRelease() {
        this->backgroundColour.setAlpha(0);
        this->update();
    }

    void SVGLabel::setLabel(QString label) {
        this->label->setText(label);
    }

    void SVGLabel::setLabelStyle(QFont & font, QString & stylesheet) {
        this->label->setFont(font);
        this->label->setStyleSheet(stylesheet);
    }

    void SVGLabel::setSVG(QString svg) {
        this->svg->load(svg);
    }
};
