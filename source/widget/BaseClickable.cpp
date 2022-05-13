#include <QPainter>
#include <QPainterPath>

#include "widget/BaseClickable.hpp"

namespace Widget {
    BaseClickable::BaseClickable(QWidget * parent) : QWidget(parent) {
        this->isClicked = false;
        this->isEnabled = true;
        this->isFocussed = false;
        this->highlightColour = QColor(255, 255, 255, 0);
        this->highlightCornerRadius = 0;
    }

    void BaseClickable::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), this->highlightCornerRadius, this->highlightCornerRadius);

        painter.fillPath(path, this->highlightColour);
    }

    void BaseClickable::mousePressEvent(QMouseEvent * event) {
        if (!this->isEnabled) {
            return;
        }

        this->highlightColour.setAlpha(50);
        this->update();

        event->accept();
        emit clicked();

        this->isClicked = true;
        this->isFocussed = true;
    }

    void BaseClickable::mouseMoveEvent(QMouseEvent * event) {
        if (!this->isEnabled) {
            return;
        }

        if (this->isClicked) {
            QRect rect = this->rect();
            QPoint pos = event->pos();
            bool inWidget = (pos.x() >= rect.x() && pos.x() < rect.x() + rect.width() &&
                                pos.y() >= rect.y() && pos.y() < rect.y() + rect.height());

            if (inWidget && !this->isFocussed) {
                this->isFocussed = true;
                this->highlightColour.setAlpha(50);

            } else if (!inWidget && this->isFocussed){
                this->isFocussed = false;
                this->highlightColour.setAlpha(0);
            }
        }
    }

    void BaseClickable::mouseReleaseEvent(QMouseEvent * event) {
        if (!this->isEnabled) {
            return;
        }

        if (this->isClicked) {
            this->highlightColour.setAlpha(0);
            this->update();

            event->accept();
            emit released();
        }

        this->isClicked = false;
        this->isFocussed = false;
    }

    void BaseClickable::setHighlightShape(bool isRoundRect, int roundRectRadius) {
        if (!isRoundRect) {
            roundRectRadius = 0;
        }

        this->highlightCornerRadius = roundRectRadius;

        if (this->isClicked) {
            this->update();
        }
    }

    void BaseClickable::setHighlightColour(QColor colour) {
        this->highlightColour.setRed(colour.red());
        this->highlightColour.setGreen(colour.green());
        this->highlightColour.setBlue(colour.blue());

        if (this->isClicked) {
            this->update();
        }
    }

    void BaseClickable::setEnabled(const bool enabled) {
        this->isEnabled = enabled;

        if (!enabled) {
            this->isClicked = false;
            this->isFocussed = false;
            this->update();
        }
    }
};