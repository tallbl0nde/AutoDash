#include <QHBoxLayout>
#include <QPainter>

#include "widget/LauncherEntry.hpp"

namespace Widget {
    int LauncherEntry::BackgroundCornerRadius = 20;

    LauncherEntry::LauncherEntry(QWidget * parent) : BaseClickable(parent) {
        // Create layout
        // TODO: Update
        this->layout = new QHBoxLayout(this);
        this->layout->setMargin(0);
        this->layout->setSpacing(0);

        // Insert widgets into layout
        this->label = new QLabel();
        this->svg = new QSvgWidget();

        this->layout->addWidget(this->svg);
        this->layout->addWidget(this->label);

        // TODO: Better defaults
        QFont font = QFont("Rubik");
        font.setBold(true);
        font.setPointSize(20);
        this->setLabelFont(font);
        this->setLabelColour(QColor(255, 255, 255, 255));
        this->setHighlightShape(true, this->BackgroundCornerRadius);
    }

    void LauncherEntry::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour = QColor(0, 0, 0, 120);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), this->BackgroundCornerRadius, this->BackgroundCornerRadius);

        painter.fillPath(path, colour);

        // Draw highlight if needed
        BaseClickable::paintEvent(event);
    }

    void LauncherEntry::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of the svg to the height of the label (making it 1:1)
        // TODO: Update
        int size = this->size().height();
        int svgSize = size * 0.6;
        this->svg->setFixedSize(svgSize, svgSize);

        int padding = size * 0.2;
        this->layout->setMargin(padding);
        this->layout->setSpacing(padding * 1.25);
    }

    void LauncherEntry::setLabelColour(QColor colour) {
        QPalette palette = this->label->palette();
        palette.setColor(QPalette::Foreground, colour);
        this->label->setPalette(palette);
    }

    void LauncherEntry::setLabelFont(QFont font) {
        this->label->setFont(font);
    }

    void LauncherEntry::setLabelText(QString label) {
        this->label->setText(label);
    }

    void LauncherEntry::setSVG(QString svg) {
        this->svg->load(svg);
    }
};
