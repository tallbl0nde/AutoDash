#include "template/list/ListSeparator.hpp"

namespace Template {
    ListSeparator::ListSeparator(QWidget * parent) : QWidget(parent) {
        this->setFixedHeight(1);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->setStyleSheet("background-color: gray");
        // TODO: Make height and colour configurable
    }

    QWidget * ListSeparator::widget() {
        return this;
    }
};