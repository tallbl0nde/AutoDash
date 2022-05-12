#include <QFont>
#include <QPainter>
#include <QPainterPath>

#include "template/list/ListButton.hpp"

namespace Template {
    ListButton::ListButton(QWidget * parent) : IClickable(parent) {
        this->clickedColour = QColor(255, 255, 255, 0);
        this->icon = nullptr;
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->setFixedHeight(80);

        // Setup layout/widgets
        this->layout = new QHBoxLayout(this);
        this->layout->setContentsMargins(30, 0, 30, 0);
        this->layout->setSpacing(25);

        QFont labelFont = QFont();
        labelFont.setFamily("Rubik");
        labelFont.setPointSize(20);

        this->label = new QLabel("", this);
        this->label->setFont(labelFont);
        this->label->setStyleSheet("color: white");     // TODO_JG: Use config for all styling
        this->layout->addWidget(this->label, 0, Qt::AlignVCenter);

        this->layout->addStretch();

        QFont arrowFont = QFont();
        arrowFont.setFamily("Rubik");
        arrowFont.setPointSize(30);

        QLabel * arrow = new QLabel(">", this);
        arrow->setFont(arrowFont);
        arrow->setStyleSheet("color: grey");
        this->layout->addWidget(arrow, 0, Qt::AlignVCenter);
    }

    void ListButton::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.fillRect(this->rect(), this->clickedColour);
    }

    void ListButton::onClick() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void ListButton::onRegainedFocus() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void ListButton::onLostFocus() {
        this->clickedColour.setAlpha(0);
        this->update();
    }

    void ListButton::onRelease() {
        this->clickedColour.setAlpha(0);
        this->update();
        emit pressed();
    }

    void ListButton::setIcon(QWidget * icon) {
        if (this->icon != nullptr) {
            this->layout->removeWidget(this->icon);
            this->icon->setParent(nullptr);
            delete this->icon;
        }

        this->icon = icon;
        this->icon->setFixedSize(50, 50);       // TODO: Scale w.r.t. ratio
        this->icon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->icon->setParent(this);
        this->layout->insertWidget(0, this->icon, 0, Qt::AlignVCenter);
    }

    void ListButton::setLabel(const std::string label) {
        this->label->setText(QString::fromStdString(label));
    }

    QWidget * ListButton::widget() {
        return this;
    }
};