#include <QHBoxLayout>
#include <QTime>

#include "widget/StatusBar.hpp"

namespace Widget {
    StatusBar::StatusBar(QWidget * parent) : Bar(parent) {
        // Get font + style sheet
        QFont font = this->labelFont();
        QString stylesheet = this->labelStyleSheet();

        // Create clock object
        // TODO: Change path
        this->clock = new SVGLabel();
        this->clock->setSVG("/home/jonathon/AutoDash/resources/icons/clock.svg");
        this->clock->setLabelStyle(font, stylesheet);
        this->updateClock();

        // Create title object
        font.setBold(false);
        this->title = new QLabel();
        this->title->setFont(font);
        this->title->setStyleSheet(stylesheet);
        this->title->setText("( Home )");
        font.setBold(true);

        // TODO: Create icon group
        QLabel * icons = new QLabel();
        icons->setFont(font);
        icons->setStyleSheet(stylesheet);
        icons->setText("[B] [⇑]");

        // Set up the status bar's layout
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
        if (time.second() % 2 == 0) {
            text[2] = ' ';
        }

        this->clock->setLabel(text);
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
