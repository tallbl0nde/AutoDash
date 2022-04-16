#include <QBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPainter>

#include "widget/SvgButton.hpp"

namespace Widget {
    SvgButton::SvgButton(QString svgFile, QWidget * parent) : IClickable(parent) {
        this->backgroundColour = QColor(0, 0, 0, 0);
        this->clickedColour = QColor(255, 255, 255, 0);
        this->onClickedCallback = nullptr;
        this->paddingPercentage = 0;
        this->roundingAmount = 0;

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
        painter.fillPath(path, this->clickedColour);
    }

    void SvgButton::resizeEvent(QResizeEvent * event) {
        int hPadding = this->height() * (paddingPercentage/100.0);
        int wPadding = this->width() * (paddingPercentage/100.0);

        this->svg->setFixedSize(this->width() - (wPadding * 2), this->height() - (hPadding * 2));
    }

    void SvgButton::onClick() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void SvgButton::onRegainedFocus() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void SvgButton::onLostFocus() {
        this->clickedColour.setAlpha(0);
        this->update();
    }

    void SvgButton::onRelease() {
        this->clickedColour.setAlpha(0);
        this->update();
        if (this->onClickedCallback != nullptr) {
            this->onClickedCallback();
        }
    }

    void SvgButton::onClicked(const std::function<void()> callback) {
        this->onClickedCallback = callback;
    }

    void SvgButton::setBackgroundColour(const QColor backgroundColour) {
        this->backgroundColour = backgroundColour;
        this->update();
    }

    void SvgButton::setEnabled(const bool enabled) {
        IClickable::setEnabled(enabled);

        QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect();
        effect->setOpacity(enabled ? 1 : 0.4);
        this->svg->setGraphicsEffect(effect);
    }

    void SvgButton::setPaddingPercentage(const int percent) {
        this->paddingPercentage = percent;
        this->update();
    }

    void SvgButton::setRoundingAmount(const ushort amount) {
        this->roundingAmount = amount;
        this->update();
    }
};