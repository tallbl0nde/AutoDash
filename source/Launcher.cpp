#include <QPushButton>
#include <QVBoxLayout>

#include "Launcher.hpp"

Launcher::Launcher(QWidget * parent) : QWidget(parent) {
    // TODO: Widgets
    QPushButton * b1 = new QPushButton("Top", this);
    b1->setGeometry(0, 0, this->width(), b1->height());
    QPushButton * b2 = new QPushButton("Middle", this);
    QPushButton * b3 = new QPushButton("Bottom", this);
}
