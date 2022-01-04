#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QLabel>

#include "widget/SVGLabel.hpp"
#include "widget/ToolBar.hpp"

namespace Widget {
    ToolBar::ToolBar(QWidget * parent) : Bar(parent) {
        // Get font + style sheet
        QFont font = this->labelFont();
        QString stylesheet = this->labelStyleSheet();

        // Create back button
        this->back = new SVGLabel();
        this->back->setLabel("Back");
        this->back->setLabelStyle(font, stylesheet);
        this->back->setSVG("/home/jonathon/AutoDash/resources/icons/back.svg");
        this->setBackEnabled(false);

        // Create home/apps button
        SVGLabel * home = new SVGLabel();
        home->setLabel("Home");
        home->setLabelStyle(font, stylesheet);
        home->setSVG("/home/jonathon/AutoDash/resources/icons/apps.svg");

        // Create 'control panel'
        QLabel * controlPanel = new QLabel();
        controlPanel->setFont(font);
        controlPanel->setStyleSheet(stylesheet);
        controlPanel->setText("[R]");

        // Set up the tool bar's layout.
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->addWidget(this->back, 0, Qt::AlignLeft);
        layout->addWidget(home, 0, Qt::AlignCenter);
        layout->addWidget(controlPanel, 0, Qt::AlignRight);

        // Resize to fit text
        this->adjustSize();
    }

    void ToolBar::setBackEnabled(const bool enable) {
        QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(this->back);

        // TODO: Toggle press event?
        if (enable) {
            // *Undim* the widget
            effect->setOpacity(1.0);

        } else {
            // Dim the widget
            effect->setOpacity(0.3);
        }

        this->back->setGraphicsEffect(effect);
    }

    ToolBar::~ToolBar() {

    }
};
