#ifndef TEMPLATE_BUTTON_HPP
#define TEMPLATE_BUTTON_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

#include "interface/template/IButton.hpp"
#include "interface/IConfig.hpp"
#include "interface/IClickable.hpp"

namespace Template {
    class Button : public IButton, IClickable {
        private:
            // Unique identifier
            static long nextID;
            std::string ID;

            // Layout
            QHBoxLayout * mainLayout;

            // Button label
            QLabel * label;

            // Button icon (optional)
            QWidget * icon;

            // Callback to invoke when button clicked.
            std::function<void()> action;

            // Flag indicating if custom colour(s) set.
            bool customColours;

            // Background colour.
            QColor backgroundColour;

            // Clicked colour.
            QColor clickedColour;

            // Handle BackgroundColourChanged event.
            void onBackgroundColourChanged(const IConfig::Colour & backgroundColour);

            // Handle FontFamilyChanged event.
            void onFontFamilyChanged(const std::string & fontFamily);

            // Handle FontSizeChanged event.
            void onFontSizeChanged(const int fontSize);

            // Handle MainTextColourChanged event.
            void onMainTextColourChanged(const IConfig::Colour & mainTextColour);

        protected:
            // Override paintEvent to draw background.
            void paintEvent(QPaintEvent * event) override;

            // Implement IClickable.
            void onClick() override;
            void onRegainedFocus() override;
            void onLostFocus() override;
            void onRelease() override;

        public:
            // Constructs a new button.
            Button(QWidget * parent = nullptr);

            // Implement IButton.
            void resetButtonColour();
            void setButtonAction(const std::function<void()> & action);
            void setButtonColour(QColor background, QColor foreground);
            void setButtonIcon(QWidget * icon);
            void setButtonText(const std::string & text);
            QWidget * widget();

            ~Button();
    };
};

#endif