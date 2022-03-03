#include <QPainter>

#include "widget/Bar.hpp"

namespace Widget {
    Bar::Bar(QWidget * parent) : QWidget(parent) {
        // Force width to 100% and set padding
        this->setFixedWidth(this->parentWidget()->width());
    }

    QFont Bar::labelFont() {
        QFont font = QFont("Rubik");
        font.setBold(true);
        font.setPointSize(18);
        return font;
    }

    QString Bar::labelStyleSheet() {
        return QString("QLabel { color: white; }");
    }

    void Bar::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour(0, 0, 0, 100);
        QPainter painter(this);
        painter.fillRect(this->rect(), colour);
    }
};
