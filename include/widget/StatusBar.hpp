#ifndef WIDGET_STATUSBAR_HPP
#define WIDGET_STATUSBAR_HPP

#include <QLabel>
#include <QTimer>

#include "widget/Bar.hpp"

// Main application status bar, displaying various status
// icons and the time.
namespace Widget {
    class StatusBar : public Bar {
        Q_OBJECT

        private:
            // Clock.
            QLabel * clock;

            // 1 second timer to update clock.
            QTimer * clockTimer;

            // Title.
            QLabel * title;

            // Updates the time shown in the clock.
            void updateClock();

            // Updates the title shown within the status bar.
            void updateTitle(QString & title);

        public:
            // Creates a new StatusBar.
            explicit StatusBar(QWidget * parent = nullptr);

            // Destructor.
            ~StatusBar();
    };
};

#endif
