#include <QHBoxLayout>
#include <QLabel>

#include "widget/ToolBar.hpp"

namespace Widget {
    ToolBar::ToolBar(QWidget * parent) : Bar(parent) {
        // Get font + style sheet
        QFont font = this->labelFont();
        QString stylesheet = this->labelStyleSheet();

        // Create back button
        QLabel * back = new QLabel();
        back->setFont(font);
        back->setStyleSheet(stylesheet);
        back->setText("< Back");

        // Create home/apps button
        QLabel * home = new QLabel();
        home->setFont(font);
        home->setStyleSheet(stylesheet);
        home->setText("[] Apps");

        // Create 'control panel'
        QLabel * controlPanel = new QLabel();
        controlPanel->setFont(font);
        controlPanel->setStyleSheet(stylesheet);
        controlPanel->setText("[R]");

        // Set up the tool bar's layout.
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->addWidget(back, 0, Qt::AlignLeft);
        layout->addWidget(home, 0, Qt::AlignCenter);
        layout->addWidget(controlPanel, 0, Qt::AlignRight);

        // Resize to fit text
        this->adjustSize();
    }

    ToolBar::~ToolBar() {

    }
};
