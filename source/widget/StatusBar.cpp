#include <QHBoxLayout>
#include <QTime>

#include "widget/StatusBar.hpp"

namespace Widget {
    StatusBar::StatusBar(QWidget * parent) : Bar(parent) {
        // Get font + style sheet
        QFont font = this->labelFont();
        QString stylesheet = this->labelStyleSheet();

        // Create clock object
        this->clock = new QLabel();
        this->clock->setFont(font);
        this->clock->setStyleSheet(stylesheet);
        this->updateClock();

        // Create title object
        this->title = new QLabel();
        this->title->setFont(font);
        this->title->setStyleSheet(stylesheet);
        this->title->setText("( Home )");

        // TODO: Create icon group
        QLabel * icons = new QLabel();
        icons->setFont(font);
        icons->setStyleSheet(stylesheet);
        icons->setText("[B] [⇑]");

        // Set up the status bar's layout.
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->addWidget(this->clock, 0, Qt::AlignLeft);
        layout->addWidget(this->title, 0, Qt::AlignCenter);
        layout->addWidget(icons, 0, Qt::AlignRight);

        // Finally start timer
        this->clockTimer = new QTimer(this);
        connect(this->clockTimer, &QTimer::timeout, this, &StatusBar::updateClock);
        this->clockTimer->start(1000);
    }

    void StatusBar::updateClock() {
        // Get current time
        QTime time = QTime::currentTime();

        // TODO: 12-hour/24-hour configurable
        QString text = time.toString("HH:mm");
        this->clock->setText(text);
        this->adjustSize();
    }

    void StatusBar::updateTitle(QString & title) {
        this->title->setText(title);
        this->adjustSize();
    }

    StatusBar::~StatusBar() {
        this->clockTimer->stop();
        delete this->clockTimer;
    }
};
