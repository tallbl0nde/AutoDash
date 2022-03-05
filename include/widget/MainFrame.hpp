#ifndef WIDGET_MAINFRAME_HPP
#define WIDGET_MAINFRAME_HPP

#include <functional>
#include <stack>

#include <QStackedWidget>

namespace Widget {
    // Inherits QStackedWidget to provide a memory of widgets accessed.
    class MainFrame : public QStackedWidget {
        private:
            // Vector of recently accessed widgets, with the oldest being first
            // (i.e. the launcher).
            std::stack<QWidget *> stack;

            // Method to invoke when the widget is changed.
            // Passed the number of widgets in the history (1 if home).
            std::function<void(int)> onChange;

        public:
            // Constructor.
            MainFrame(QWidget *, QWidget * = nullptr);

            // Set the method to invoke when the widget is changed.
            void onWidgetChanged(const std::function<void(int)> &);

            // Moves back one widget in the history. Does nothing if
            // already at the start.
            void goBack();

            // Returns to the first widget, clearing the history.
            void goHome();

            // Adds a widget to the frame, for future navigation.
            void addWidget(QWidget *);

            // Moves to the requested widget, pushing the current widget
            // onto the history. Does nothing if the widget is not in
            // the frame.
            void goToWidget(QWidget *);
    };
};

#endif
