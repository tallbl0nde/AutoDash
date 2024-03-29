#include <QFont>
#include <QPainter>
#include <QPainterPath>

#include "template/list/ListButton.hpp"

namespace Template {
    ListButton::ListButton(QWidget * parent) : BaseClickable(parent) {
        this->icon = nullptr;
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->setFixedHeight(80);

        // Setup layout/widgets
        this->layout = new QHBoxLayout(this);
        this->layout->setContentsMargins(30, 0, 30, 0);
        this->layout->setSpacing(25);

        QWidget * textWidget = new QWidget(this);
        textWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QVBoxLayout * textLayout = new QVBoxLayout(textWidget);
        textLayout->setMargin(0);
        textLayout->setSpacing(2);
        textLayout->addStretch();

        QFont labelFont = QFont();
        labelFont.setFamily("Rubik");
        labelFont.setPointSize(20);

        this->label = new QLabel("", this);
        this->label->setFont(labelFont);
        this->label->setStyleSheet("color: white");     // TODO_JG: Use config for all styling
        this->label->setWordWrap(true);
        textLayout->addWidget(this->label);

        QFont descriptionFont = QFont();
        descriptionFont.setBold(true);
        descriptionFont.setFamily("Rubik");
        descriptionFont.setPointSize(14);

        this->description = new QLabel("", this);
        this->description->setFont(descriptionFont);
        this->description->setStyleSheet("color: grey");     // TODO_JG: Use config for all styling
        this->description->setWordWrap(true);
        this->description->setHidden(true);
        textLayout->addWidget(this->description);

        textLayout->addStretch();
        this->layout->addWidget(textWidget);

        QFont arrowFont = QFont();
        arrowFont.setFamily("Rubik");
        arrowFont.setPointSize(30);

        QLabel * arrow = new QLabel(">", this);
        arrow->setFont(arrowFont);
        arrow->setStyleSheet("color: grey");
        this->layout->addWidget(arrow, 0, Qt::AlignVCenter);
    }

    QWidget * ListButton::widget() {
        return this;
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

    void ListButton::setDescription(const std::string description) {
        this->description->setText(QString::fromStdString(description));
        this->description->setHidden(description.empty());
    }
};