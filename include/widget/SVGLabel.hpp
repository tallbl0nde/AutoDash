#ifndef WIDGET_SVGLABEL_HPP
#define WIDGET_SVGLABEL_HPP

#include <QFont>
#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QString>
#include <QSvgWidget>
#include <QWidget>

#include "interface/IClickable.hpp"

namespace Widget {
    // Widget consisting of an SVG icon positioned to the left of a label.
    class SVGLabel : public IClickable {
        Q_OBJECT

        private:
            // Background colour.
            QColor backgroundColour;

            // Label.
            QLabel * label;

            // SVG widget.
            QSvgWidget * svg;

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent *);

            // Overload to adjust svg size.
            void resizeEvent(QResizeEvent *);

            // Implement IClickable members.
            void onClick() override;
            void onRegainedFocus() override;
            void onLostFocus() override;
            void onRelease() override;

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
