#ifndef TEMPLATE_BUTTON_HPP
#define TEMPLATE_BUTTON_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

#include "interface/template/IButton.hpp"
#include "widget/BaseClickable.hpp"

namespace Template {
    class Button : public Widget::BaseClickable, public IButton {
        Q_OBJECT
        Q_INTERFACES(Template::IButton)

        private:
            // Background corner radius.
            static int BackgroundCornerRadius;

            // Layout
            QHBoxLayout * mainLayout;

            // Button label
            QLabel * label;

            // Button icon (optional)
            QWidget * icon;

            // Flag indicating if custom colour(s) set.
            bool customColours;

            // Background colour.
            QColor backgroundColour;

        protected:
            // Override paintEvent to draw background.
            void paintEvent(QPaintEvent * event) override;

        public:
            // Constructs a new button.
            Button(QWidget * parent = nullptr);

            // Implement IButton.
            QWidget * widget();

        public slots:
            // Implement IButton.
            void resetButtonColour();
            void setButtonColour(QColor background, QColor foreground);
            void setButtonIcon(QWidget * icon);
            void setButtonText(const std::string & text);
    };
};

#endif