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
        this->launcherButton->setFixedSize(60, 60);   // TODO: Scale
        this->launcherButton->setRoundingAmount(14);
        this->launcherButton->setPaddingPercentage(15);
        this->mainLayout->addWidget(this->launcherButton, 0, alignment);
        connect(this->launcherButton, &SvgButton::released, this, [this]() {
            emit this->launcherButtonClicked();
        });

        // Add splitter
        this->mainLayout->addWidget(getLine(orientation, 50), 0, alignment);

        // Add favourites section
        this->favourites = new Favourites(orientation == Orientation::Horizontal ? Favourites::Orientation::Horizontal : Favourites::Orientation::Vertical);
        this->mainLayout->addWidget(favourites);

        // Add another splitter
        this->mainLayout->addWidget(getLine(orientation, 50), 0, alignment);

        // Add back button
        this->backButton = new SvgButton(":/icons/back.svg");
        this->backButton->setFixedSize(60, 60);   // TODO: Scale
        this->backButton->setRoundingAmount(14);
        this->backButton->setPaddingPercentage(15);
        this->mainLayout->addWidget(this->backButton, 0, alignment);
        connect(this->backButton, &SvgButton::released, this, [this]() {
            emit this->backButtonClicked();
        });
    }

    void Taskbar::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour = QColor(0, 0, 0, 120);
        QColor colour2 = QColor(100, 100, 100, 100);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRect(this->rect());
        painter.fillPath(path, colour);

        path = QPainterPath();
        path.addRect(QRect(0, 10, 1, this->height() - 20));
        painter.fillPath(path, colour2);
    }

    void Taskbar::setBackButtonEnabled(const bool enabled) {
        this->backButton->setEnabled(enabled);
    }

    Favourites * Taskbar::favouritesWidget() {
        return this->favourites;
    }
};