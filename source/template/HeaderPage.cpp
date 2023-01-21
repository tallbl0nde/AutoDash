#include <QGraphicsColorizeEffect>

#include "factory/ConfigFactory.hpp"
#include "template/HeaderPage.hpp"

#define HEADING_FONT_OFFSET 2

namespace Template {
    HeaderPage::HeaderPage(QWidget * parent) : QWidget(parent) {
        this->icon = nullptr;
        this->mainWidget = nullptr;

        // Set up header layout
        QWidget * headerWidget = new QWidget(this);

        this->heading = new QLabel("HeaderPage", headerWidget);

        QFont font = this->heading->font();
        font.setBold(true);
        font.setFamily(QString::fromStdString("Rubik"));        // TODO: Use config
        font.setPointSize(18 + HEADING_FONT_OFFSET);
        this->heading->setFont(font);

        QGraphicsColorizeEffect * headingEffect = new QGraphicsColorizeEffect();
        headingEffect->setColor(QColor{255, 255, 255});
        this->heading->setGraphicsEffect(headingEffect);

        this->headerLayout = new QHBoxLayout(headerWidget);
        this->headerLayout->addWidget(this->heading, 0, Qt::AlignVCenter);
        this->headerLayout->addStretch();
        this->headerLayout->setContentsMargins(10, 0, 0, 0);
        this->headerLayout->setSpacing(20);

        // Set up the layout
        this->mainLayout = new QVBoxLayout(this);
        this->mainLayout->setContentsMargins(30, 30, 30, 0);
        this->mainLayout->setSpacing(0);
        this->mainLayout->addWidget(headerWidget);
        this->mainLayout->addSpacing(20);

        QWidget * separator = new QWidget(this);
        separator->setFixedHeight(1);
        separator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        separator->setStyleSheet("background-color: gray");     // TODO: Use config
        this->mainLayout->addWidget(separator);
    }

    QWidget * HeaderPage::widget() {
        return this;
    }

    void HeaderPage::setHeadingText(const std::string & text) {
        this->heading->setText(QString::fromStdString(text));
    }

    void HeaderPage::setIcon(QWidget * icon) {
        if (this->icon != nullptr) {
            this->headerLayout->removeWidget(this->icon);
            this->icon->setParent(nullptr);
            delete this->icon;
        }

        this->icon = icon;
        this->icon->setFixedSize(50, 50);
        this->icon->setParent(this);
        this->headerLayout->insertWidget(0, this->icon, 0, Qt::AlignVCenter);
    }

    void HeaderPage::setMainWidget(QWidget * widget) {
        widget->setParent(this);
        this->mainLayout->addWidget(widget, 1);
        this->mainWidget = widget;
    }
};