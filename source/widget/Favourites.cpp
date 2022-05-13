#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "widget/Favourites.hpp"

namespace Widget {
    Favourites::Favourites(Orientation orientation, QWidget * parent) : QWidget(parent) {
        // Create layout based on orientation
        switch (orientation) {
            case Favourites::Orientation::Horizontal:
                this->layout = new QHBoxLayout(this);
                break;

            case Favourites::Orientation::Vertical:
                this->layout = new QVBoxLayout(this);
                break;

            default:
                throw std::runtime_error("Invalid orientation provided");
                break;
        }

        // Setup common layout properties
        this->layout->setMargin(10);
        this->layout->setSpacing(20);
    }

    void Favourites::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        if (this->highlightMidpoint == QPoint(0, 0)) {
            return;
        }

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        static int width = 10;
        static int height = 36;

        QPainterPath path;
        path.addRoundedRect(this->highlightMidpoint.x() - width/2, this->highlightMidpoint.y() - height/2, width, height, 5, 5);
        painter.fillPath(path, QColor(255, 255, 255, 200));
    }

    void Favourites::addEntry(const std::string & id, const std::string & svgPath) {
        // Create SvgButton for entry
        SvgButton * button = new SvgButton(QString::fromStdString(svgPath));
        connect(button, &SvgButton::released, this, [this, id]() {
            emit this->entryClicked(id);
        });
        button->setFixedSize(60, 60);
        button->setPaddingPercentage(15);
        button->setRoundingAmount(14);

        // Add to layout and store entry
        this->layout->addWidget(button, 0, Qt::AlignCenter);
        this->entries.push_back(Entry{id, button});
    }

    void Favourites::removeEntry(const std::string & id) {
        // Find matching entry
        auto it = std::find_if(this->entries.begin(), this->entries.end(), [id](const Entry entry) {
            return (entry.id == id);
        });

        // Abort if not found
        if (it == this->entries.end()) {
            return;
        }

        // Remove from vector and remove from layout
        this->layout->removeWidget((*it).button);
        delete (*it).button;
        this->entries.erase(it);
    }

    void Favourites::removeAllEntries() {
        for (Entry & entry : this->entries) {
            this->layout->removeWidget(entry.button);
        }

        this->entries.clear();
    }

    void Favourites::setActiveEntry(const std::string & id) {
        // Find widget for id
        auto it = std::find_if(this->entries.begin(), this->entries.end(), [id](const Entry entry) {
            return (entry.id == id);
        });

        // Abort if not found
        if (it == this->entries.end()) {
            // Update anyway to hide highlight if needed
            this->highlightMidpoint = QPoint(0, 0);
            this->update();
            return;
        }

        // Set position of active highlight to this widget
        QWidget * widget = (*it).button;
        this->highlightMidpoint = QPoint(this->x() + this->width(), widget->y() + widget->height()/2);
        this->update();
    }
};