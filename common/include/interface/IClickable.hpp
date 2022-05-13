#ifndef INTERFACE_ICLICKABLE_HPP
#define INTERFACE_ICLICKABLE_HPP

#include <QMouseEvent>

// Interface for a QWidget that responds to clicks/presses.
class IClickable {
    protected:
        // Listen for mouse presses/clicks.
        virtual void mousePressEvent(QMouseEvent * event) = 0;

        // Listen for mouse moves.
        virtual void mouseMoveEvent(QMouseEvent * event) = 0;

        // Listen for mouse release.
        virtual void mouseReleaseEvent(QMouseEvent * event) = 0;

    public:
        // Enables/disables the ability to react to clicks.
        virtual void setEnabled(const bool enabled) = 0;

        virtual ~IClickable() {}

    signals:
        // Signal emitted when the widget is first clicked (on click).
        virtual void clicked() = 0;

        // Signal emitted when the widget is clicked (on release).
        virtual void released() = 0;
};

Q_DECLARE_INTERFACE(IClickable, "IClickable");

#endif
