#include <algorithm>
#include <QResizeEvent>

#include "widget/IconGroup.hpp"

namespace Widget {
    IconGroup::IconGroup(QWidget * parent) : QWidget(parent) {
        // Create layout
        this->layout = new QHBoxLayout(this);
        this->layout->setMargin(0);
        this->layout->setSpacing(0);
    }

    void IconGroup::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of all svg's to their height (making it 1:1)
        int size = this->size().height() * 0.9;
        for (Icon & icon : this->icons) {
            icon.widget->setFixedSize(size, size);
        }
    }

    void IconGroup::setIconSpacing(int spacing) {
        this->layout->setSpacing(spacing);
    }

    bool IconGroup::addIcon(QString identifier, QString svg) {
        // Search array for icon
        std::vector<IconGroup::Icon>::iterator it = std::find_if(this->icons.begin(), this->icons.end(), [&identifier](const Icon & icon) {
            return (icon.identifier == identifier);
        });

        if (it == this->icons.end()) {
            // Icon doesn't exist, so add into array and layout
            QSvgWidget * widget = new QSvgWidget();
            widget->load(svg);

            struct Icon icon;
            icon.identifier = identifier;
            icon.widget = widget;
            this->icons.push_back(icon);

            this->layout->addWidget(widget);
            return true;
        }

        // Icon exists, don't re-add
        return false;
    }

    QSvgWidget * IconGroup::getIcon(QString identifier) {
        // Search array for icon
        std::vector<IconGroup::Icon>::iterator it = std::find_if(this->icons.begin(), this->icons.end(), [&identifier](const Icon & icon) {
            return (icon.identifier == identifier);
        });

        // Return widget if found
        if (it != this->icons.end()) {
            return (*it).widget;
        }

        // Otherwise return nullptr as not found
        return nullptr;
    }
};
