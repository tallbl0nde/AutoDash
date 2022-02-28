#ifndef WIDGET_MODULEICON_HPP
#define WIDGET_MODULEICON_HPP

#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSvgWidget>
#include <QWidget>

namespace Widget {
    // Widget representing a module. It consists of a background,
    // icon and label.
    class ModuleIcon : public QWidget {
        Q_OBJECT

        private:
            // Label.
            QLabel * label;

            // SVG icon.
            QSvgWidget * svg;

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent * event);

            // Overload to adjust svg size.
            void resizeEvent(QResizeEvent * event);

        public:
            // Constructs a new ModuleIcon.
            explicit ModuleIcon(QWidget * parent = nullptr);

            // Sets the label text.
            void setLabel(QString label);

            // Sets the label style.
            void setLabelStyle(QFont & font, QString & stylesheet);

            // Sets the SVG icon.
            void setSVG(QString svg);
    };
};

#endif
