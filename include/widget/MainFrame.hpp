#ifndef WIDGET_MAINFRAME_HPP
#define WIDGET_MAINFRAME_HPP

#include <functional>
#include <stack>

#include <QStackedWidget>

namespace Widget {
    // Inherits QStackedWidget to provide a memory of widgets accessed.
    class MainFrame : public QStackedWidget {
        public:
            // Collection of metadata for a frame.
            struct Frame {
                std::string id;         // ID of frame
                QWidget * frame;        // Frame object
            };

        private:
            // Frames registered with the main frame.
            std::vector<Frame> availableFrames;

            // ID of current frame.
            std::string currentID;

            // Method to invoke when the widget is changed.
            // Passed the ID of the new frame and the number of frames in the history (1 if home).
            std::function<void(std::string, int)> onChange;

            // Vector of recently accessed widgets, with the oldest being first
            // (i.e. the launcher).
            std::stack<Frame> stack;

        public:
            // Constructor.
            MainFrame(QWidget * home, QWidget * parent = nullptr);

            // Set the method to invoke when the active frame is changed.
            void onFrameChanged(const std::function<void(std::string, int)> & callback);

            // Passes the back method to the active frame, returning to the launcher
            // if not handled.
            void goBack();

            // Returns to the launcher, clearing the history.
            void goHome();

            // Adds a child frame with the given id.
            void addFrame(const std::string & id, QWidget *);

            // Launches the requested frame if it exists.
            void openFrame(const std::string & id);
    };
};

#endif
