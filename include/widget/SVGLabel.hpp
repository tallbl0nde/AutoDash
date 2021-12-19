#ifndef WIDGET_SVGLABEL_HPP
#define WIDGET_SVGLABEL_HPP

#include <QFont>
#include <QLabel>
#include <QString>
#include <QSvgWidget>
#include <QWidget>

namespace Widget {
    // Widget consisting of an SVG icon positioned to the left of a label.
    class SVGLabel : public QWidget {
        Q_OBJECT

        private:
            // Label.
            QLabel * label;

            // SVG widget.
            QSvgWidget * svg;

        public:
            // Creates a new SVGLabel from the specified icon file and label.
            explicit SVGLabel(QWidget * parent = nullptr);

            // Sets the label text.
            void setLabel(QString label);

            // Sets the label style.
            void setLabelStyle(QFont & font, QString & stylesheet);

            // Sets the SVG icon.
            void setSVG(QString svg);
    };
};

#endif
