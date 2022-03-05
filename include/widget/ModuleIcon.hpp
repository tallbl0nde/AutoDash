#ifndef WIDGET_MODULEICON_HPP
#define WIDGET_MODULEICON_HPP

#include <functional>

#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSvgWidget>

#include "interface/IClickable.hpp"

namespace Widget {
    // Widget representing a module. It consists of a background,
    // icon and label.
    class ModuleIcon : public IClickable {
        Q_OBJECT

        private:
            // Background colour.
            QColor backgroundColour;

            // Layout.
            QLayout * layout;

            // Label.
            QLabel * label;

            // SVG icon.
            QSvgWidget * svg;

            // Callback to invoke when the widget is clicked/pressed.
            std::function<void()> onClickedCallback;

            // Returns the font.
            QFont labelFont();

            // Returns the stylesheet for the label.
            QString labelStylesheet();

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent * event) override;

            // Overload to adjust svg size.
            void resizeEvent(QResizeEvent * event) override;

            // Implement IClickable methods.
            void onClick() override;
            void onRegainedFocus() override;
            void onLostFocus() override;
            void onRelease() override;

        public:
            // Constructs a new ModuleIcon.
            explicit ModuleIcon(QWidget * parent = nullptr);

            // Sets the method to invoke when clicked/pressed.
            void onClicked(const std::function<void()> &);

            // Sets the label text.
            void setLabel(QString label);

            // Sets the label style.
            void setLabelStyle(QFont & font, QString & stylesheet);

            // Sets the SVG icon.
            void setSVG(QString svg);
    };
};

#endif
