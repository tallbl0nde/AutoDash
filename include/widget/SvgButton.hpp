#ifndef WIDGET_SVGBUTTON_HPP
#define WIDGET_SVGBUTTON_HPP

#include <QColor>
#include <QSvgWidget>

#include "widget/BaseClickable.hpp"

namespace Widget {
    class SvgButton : public BaseClickable {
        Q_OBJECT

        private:
            // Background colour of button.
            QColor backgroundColour;

            // Percentage of width/height to pad with.
            int paddingPercentage;

            // Amount to round clicked background in pixels.
            ushort roundingAmount;

            // SVG.
            QSvgWidget * svg;

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent * event) override;

            // Override to resize SVG.
            void resizeEvent(QResizeEvent * event) override;

        public:
            // Creates a new SvgButton from the specified file.
            SvgButton(QString svgFile, QWidget * parent = nullptr);

        public slots:
            // Sets the background colour of the button.
            void setBackgroundColour(QColor backgroundColour);

            // Sets whether the button is enabled.
            void setEnabled(const bool enabled) override;

            // Sets the amount of padding to the given percentage (0 to 100).
            void setPaddingPercentage(const int percent);

            // Sets the amount to round the background when the button is clicked.
            void setRoundingAmount(const ushort amount);
    };
};

#endif