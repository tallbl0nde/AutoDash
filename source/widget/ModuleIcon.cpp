#include <QHBoxLayout>
#include <QPainter>

#include "widget/ModuleIcon.hpp"

namespace Widget {
    ModuleIcon::ModuleIcon(QWidget * parent) : QWidget(parent) {
        // Create layout
        // TODO: Update
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setMargin(0);
        layout->setSpacing(0);

        // Insert widgets into layout
        this->label = new QLabel();
        this->svg = new QSvgWidget();

        layout->addWidget(this->svg);
        layout->addWidget(this->label);
    }

    void ModuleIcon::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour(0, 0, 0, 80);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), 20, 20);

        painter.fillPath(path, colour);
    }

    void ModuleIcon::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of the svg to the height of the label (making it 1:1)
        // TODO: Update
        int size = this->size().height() * 0.9;
        this->svg->setFixedSize(size, size);
    }

    void ModuleIcon::setLabel(QString label) {
        this->label->setText(label);
    }

    void ModuleIcon::setLabelStyle(QFont & font, QString & stylesheet) {
        this->label->setFont(font);
        this->label->setStyleSheet(stylesheet);
    }

    void ModuleIcon::setSVG(QString svg) {
        this->svg->load(svg);
    }
};
