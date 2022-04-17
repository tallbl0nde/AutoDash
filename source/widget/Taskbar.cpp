#include <QPainter>

#include "Log.hpp"
#include "widget/Taskbar.hpp"

namespace Widget {
    // Helper method to get a line separator based on the passed orientation.
    static QWidget * getLine(Taskbar::Orientation orientation, int length) {
        QWidget * line = new QWidget();
        line->setStyleSheet(QString("background-color: #cccccc"));

        static int thickness = 1;
        switch (orientation) {
            case Taskbar::Orientation::Horizontal:
                line->setFixedHeight(length);
                line->setFixedWidth(thickness);
                break;

            case Taskbar::Orientation::Vertical:
                line->setFixedHeight(thickness);
                line->setFixedWidth(length);
                break;

            default:
                throw std::runtime_error("Invalid orientation provided");
                break;
        }

        return line;
    }

    Taskbar::Taskbar(Taskbar::Orientation orientation, QWidget * parent) : QWidget(parent) {
        // Create child layouts based on orientation
        switch (orientation) {
            case Taskbar::Orientation::Horizontal:
                this->mainLayout = new QHBoxLayout(this);
                this->mainLayout->setContentsMargins(10, 0, 10, 0);
                break;

            case Taskbar::Orientation::Vertical:
                this->mainLayout = new QVBoxLayout(this);
                this->mainLayout->setContentsMargins(0, 10, 0, 10);
                break;

            default:
                throw std::runtime_error("Invalid orientation provided");
                break;
        }

        Qt::AlignmentFlag alignment = (orientation == Orientation::Horizontal ? Qt::AlignVCenter : Qt::AlignHCenter);
        this->mainLayout->setSpacing(10);

        // Add launcher button
        this->launcherButton = new SvgButton(":/icons/launcher.svg");
        this->launcherButton->setBackgroundColour(QColor(40, 40, 40, 255));
        this->launcherButton->setFixedSize(60, 60);   // TODO: Scale
        this->launcherButton->setRoundingAmount(14);
        this->launcherButton->setPaddingPercentage(20);
        this->mainLayout->addWidget(this->launcherButton, 0, alignment);

        // Add splitter
        this->mainLayout->addWidget(getLine(orientation, 60), 0, alignment);

        // Add favourites section
        this->favourites = new Favourites(orientation == Orientation::Horizontal ? Favourites::Orientation::Horizontal : Favourites::Orientation::Vertical);
        this->mainLayout->addWidget(favourites);

        // Add another splitter
        this->mainLayout->addWidget(getLine(orientation, 60), 0, alignment);

        // Add back button
        this->backButton = new SvgButton(":/icons/back.svg");
        this->backButton->setBackgroundColour(QColor(40, 40, 40, 255));
        this->backButton->setFixedSize(60, 60);   // TODO: Scale
        this->backButton->setRoundingAmount(14);
        this->backButton->setPaddingPercentage(20);
        this->mainLayout->addWidget(this->backButton, 0, alignment);
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

    Favourites * Taskbar::favouritesWidget() {
        return this->favourites;
    }
};