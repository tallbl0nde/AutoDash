#include <QHBoxLayout>

#include "widget/SVGLabel.hpp"

namespace Widget {
    SVGLabel::SVGLabel(QWidget * parent) : QWidget(parent) {
        // Create layout
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setMargin(0);
        layout->setSpacing(0);

        // Insert widgets into layout
        this->label = new QLabel();
        this->svg = new QSvgWidget();

        layout->addWidget(this->svg);
        layout->addWidget(this->label);
    }

    void SVGLabel::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of the svg to the height of the label (making it 1:1)
        int size = this->size().height() * 0.9;
        this->svg->setFixedSize(size, size);
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
