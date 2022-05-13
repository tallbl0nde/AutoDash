#include <QBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPainter>

#include "widget/SvgButton.hpp"

namespace Widget {
    SvgButton::SvgButton(QString svgFile, QWidget * parent) : BaseClickable(parent) {
        this->backgroundColour = QColor(0, 0, 0, 0);
        this->paddingPercentage = 0;
        this->setRoundingAmount(0);

        // Place svg in layout to center
        this->svg = new QSvgWidget(svgFile);
        QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
        layout->setMargin(0);
        layout->addWidget(this->svg, Qt::AlignCenter);
    }

    void SvgButton::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), this->roundingAmount, this->roundingAmount);
        painter.fillPath(path, this->backgroundColour);

        // Draw highlight if needed
        BaseClickable::paintEvent(event);
    }

    void SvgButton::resizeEvent(QResizeEvent * event) {
        int hPadding = this->height() * (paddingPercentage/100.0);
        int wPadding = this->width() * (paddingPercentage/100.0);

        this->svg->setFixedSize(this->width() - (wPadding * 2), this->height() - (hPadding * 2));
    }

    void SvgButton::setBackgroundColour(const QColor backgroundColour) {
        this->backgroundColour = backgroundColour;
        this->update();
    }

    void SvgButton::setEnabled(const bool enabled) {
        QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect();
        effect->setOpacity(enabled ? 1 : 0.4);
        this->svg->setGraphicsEffect(effect);

        BaseClickable::setEnabled(enabled);
    }

    void SvgButton::setPaddingPercentage(const int percent) {
        this->paddingPercentage = percent;
        this->update();
    }

    void SvgButton::setRoundingAmount(const ushort amount) {
        this->roundingAmount = amount;
        this->setHighlightShape(true, amount);
        this->update();
    }
};