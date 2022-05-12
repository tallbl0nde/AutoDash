#include <QScroller>

#include "template/list/List.hpp"

namespace Template {
    List::List(QWidget * parent) : QScrollArea(parent) {
        // Setup the scroll area itself
        this->setFrameShape(QFrame::NoFrame);
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        QScroller::grabGesture(this, QScroller::LeftMouseButtonGesture);

        // Create inner widget containing items
        this->innerWidget = new QWidget(this);
        this->innerWidget->setContentsMargins(20, 0, 20, 0);
        this->innerLayout = new QVBoxLayout(this->innerWidget);
        this->innerLayout->setMargin(0);
        this->innerLayout->setSpacing(0);

        this->setWidget(this->innerWidget);
        this->setWidgetResizable(true);
    }

    void List::addItem(IListItem * item) {
        this->innerLayout->addWidget(item->widget());
    }

    bool List::removeItem(IListItem * item) {
        this->innerLayout->removeWidget(item->widget());
    }

    QWidget * List::widget() {
        return this;
    }
};