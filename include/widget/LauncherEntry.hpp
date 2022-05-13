#ifndef WIDGET_MODULEICON_HPP
#define WIDGET_MODULEICON_HPP

#include <functional>

#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSvgWidget>

#include "widget/BaseClickable.hpp"

namespace Widget {
    // Widget representing a module. It consists of a background,
    // icon and label.
    class LauncherEntry : public BaseClickable {
        Q_OBJECT

        private:
            // Background corner radius.
            static int BackgroundCornerRadius;

            // Layout.
            QLayout * layout;

            // Label.
            QLabel * label;

            // SVG icon.
            QSvgWidget * svg;

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent * event) override;

            // Overload to adjust svg size.
            void resizeEvent(QResizeEvent * event) override;

        public:
            // Constructs a new LauncherEntry.
            LauncherEntry(QWidget * parent = nullptr);

        public slots:
            // Sets the label colour.
            void setLabelColour(QColor colour);

            // Sets the label style.
            void setLabelFont(QFont font);

            // Sets the label text.
            void setLabelText(QString label);

            // Sets the SVG icon.
            void setSVG(QString svg);
    };
};

#endif
