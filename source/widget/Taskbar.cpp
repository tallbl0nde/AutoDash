#include <QPainter>

#include "Log.hpp"
#include "widget/Taskbar.hpp"

namespace Widget {
    Taskbar::Taskbar(Taskbar::Orientation orientation, QWidget * parent) : QWidget(parent) {
        // Create child layouts based on orientation
        switch (orientation) {
            case Taskbar::Orientation::Horizontal:
                this->favouritesLayout = new QHBoxLayout();
                this->mainLayout = new QHBoxLayout(this);
                break;

            case Taskbar::Orientation::Vertical:
                this->favouritesLayout = new QVBoxLayout();
                this->mainLayout = new QVBoxLayout(this);
                break;

            default:
                throw std::runtime_error("Invalid orientation provided");
                break;
        }

        // Add launcher button
        this->launcherButton = new SvgButton(":/icons/launcher.svg");
        this->launcherButton->setBackgroundColour(QColor(40, 40, 40, 255));
        this->launcherButton->setMaximumSize(60, 60);
        this->launcherButton->setRoundingAmount(14);
        this->launcherButton->setPaddingPercentage(20);
        this->mainLayout->addWidget(this->launcherButton, orientation == Orientation::Horizontal ? Qt::AlignRight : Qt::AlignTop);

        // Add splitter

        // Add favourites section

        // Add another splitter

        // Add back button
        this->backButton = new SvgButton(":/icons/back.svg");
        this->backButton->setBackgroundColour(QColor(40, 40, 40, 255));
        this->backButton->setMaximumSize(60, 60);
        this->backButton->setRoundingAmount(14);
        this->backButton->setPaddingPercentage(20);
        this->mainLayout->addWidget(this->backButton, orientation == Orientation::Horizontal ? Qt::AlignLeft : Qt::AlignBottom);
    }

    void Taskbar::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour = QColor(0, 0, 0, 80);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRect(this->rect());
        painter.fillPath(path, colour);
    }

    void Taskbar::onBackButtonClicked(const std::function<void()> callback) {
        this->backButton->onClicked(callback);
    }

    void Taskbar::onLauncherButtonClicked(const std::function<void()> callback) {
        this->launcherButton->onClicked(callback);
    }

    void Taskbar::setBackButtonEnabled(const bool enabled) {
        this->backButton->setEnabled(enabled);
    }
};