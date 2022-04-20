#include "template/HeaderPage.hpp"

namespace Template {
    HeaderPage::HeaderPage(QWidget * parent) : QWidget(parent) {
        // Set up the layout
        this->layout = new QVBoxLayout(this);
        this->layout->setMargin(30);

        // Create heading
        this->heading = new QLabel("HeaderPage", this);
        this->layout->addWidget(this->heading, 0, Qt::AlignLeft);

        // Add spacer
        this->layout->addSpacing(20);

        QWidget * separator = new QWidget(this);
        separator->setFixedHeight(1);
        separator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        separator->setStyleSheet("background-color: gray");
        this->layout->addWidget(separator);

        this->mainWidget = nullptr;
    }

    void HeaderPage::setHeadingText(const std::string & text) {
        this->heading->setText(QString::fromStdString(text));
    }

    void HeaderPage::setMainWidget(QWidget * widget) {
        widget->setParent(this);
        this->layout->addWidget(widget, 1);
        this->mainWidget = widget;
    }

    QWidget * HeaderPage::widget() {
        return this;
    }
};