#include "template/list/ListSpacer.hpp"

namespace Template {
    ListSpacer::ListSpacer(QWidget * parent) : QWidget(parent) {
        this->setSize(10);
    }

    void ListSpacer::setSize(const int size) {
        this->setFixedHeight(size);
    }

    QWidget * ListSpacer::widget() {
        return this;
    }
};