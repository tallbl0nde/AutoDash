#ifndef WIDGET_TASKBAR_HPP
#define WIDGET_TASKBAR_HPP

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

#include "widget/Favourites.hpp"
#include "widget/SvgButton.hpp"

namespace Widget {
    // Main taskbar widget. Contains launcher, back, and favourited
    // module icons.
    class Taskbar : public QWidget {
        Q_OBJECT

        public:
            enum class Orientation {
                Horizontal,         // Horizontal taskbar
                Vertical            // Vertical taskbar
            };

        private:
            // Main layout
            QBoxLayout * mainLayout;

            // Launcher button
            SvgButton * launcherButton;

            // Favourites bar
            Favourites * favourites;

            // Back button
            SvgButton * backButton;

        protected:
            // Overload to draw background.
            void paintEvent(QPaintEvent * event) override;

        public:
            // Constructs a new taskbar with the given orientation.
            Taskbar(Orientation orientation, QWidget * parent = nullptr);

            // Assigns a callback to invoke when the back button is pressed.
            void onBackButtonClicked(const std::function<void()> callback);

            // Assigns a callback to invoke when the launcher button is pressed.
            void onLauncherButtonClicked(const std::function<void()> callback);

            // Toggles whether the back button is enabled.
            void setBackButtonEnabled(const bool enabled);

            // Allows access to the inner favourites object.
            Favourites * favouritesWidget();
    };
};

#endif