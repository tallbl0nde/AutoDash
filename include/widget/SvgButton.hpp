#ifndef WIDGET_SVGBUTTON_HPP
#define WIDGET_SVGBUTTON_HPP

#include <QColor>
#include <QSvgWidget>

#include "interface/IClickable.hpp"

namespace Widget {
    class SvgButton : public IClickable {
        private:
            // Background colour of button.
            QColor backgroundColour;

            // Instance's colour to fill with.
            QColor clickedColour;

            // Callback to invoke when clicked.
            std::function<void()> onClickedCallback;

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
            virtual void resizeEvent(QResizeEvent * event) override;

            // Implement IClickable members.
            virtual void onClick() override;
            virtual void onRegainedFocus() override;
            virtual void onLostFocus() override;
            virtual void onRelease() override;

        public:
            // Creates a new SvgButton from the specified file.
            SvgButton(QString svgFile, QWidget * parent = nullptr);

            // Sets the callback to invoke when clicked.
            void onClicked(const std::function<void()> callback);

            // Sets the background colour of the button.
            void setBackgroundColour(const QColor backgroundColour);

            // Sets if the button is enabled.
            void setEnabled(const bool enabled);

            // Sets the amount of padding to the given percentage (0 to 100).
            void setPaddingPercentage(const int percent);

            // Sets the amount to round the background when the button is clicked.
            void setRoundingAmount(const ushort amount);
    };
};

#endif