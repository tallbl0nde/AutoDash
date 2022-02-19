#ifndef WIDGET_PLUGINICON_HPP
#define WIDGET_PLUGINICON_HPP

#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSvgWidget>
#include <QWidget>

namespace Widget {
    // Widget representing a plugin. It consists of a background,
    // icon and label.
    class PluginIcon : public QWidget {
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
            // Constructs a new PluginIcon.
            explicit PluginIcon(QWidget * parent = nullptr);

            // Sets the label text.
            void setLabel(QString label);

            // Sets the label style.
            void setLabelStyle(QFont & font, QString & stylesheet);

            // Sets the SVG icon.
            void setSVG(QString svg);
    };
};

#endif
