#ifndef WIDGET_BAR_HPP
#define WIDGET_BAR_HPP

#include <QFont>
#include <QPaintEvent>
#include <QString>
#include <QWidget>

namespace Widget {
    // Generic 'bar' object which should be inherited to create
    // more 'specific' bars.
    class Bar : public QWidget {
        Q_OBJECT

        protected:
            // Returns the font to use for text within the bar.
            QFont labelFont();

            // Returns the stylesheet for text within the bar.
            QString labelStyleSheet();

            // Overload to paint transparent black background.
            void paintEvent(QPaintEvent * event);

        public:
            // Creates a new Bar.
            explicit Bar(QWidget * parent = nullptr);
    };
};

#endif
