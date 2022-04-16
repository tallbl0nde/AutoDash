#ifndef INTERFACE_ICLICKABLE_HPP
#define INTERFACE_ICLICKABLE_HPP

#include <QMouseEvent>
#include <QWidget>

// Interface for a QWidget that responds to clicks/presses.
class IClickable : public QWidget {
    private:
        // Flag indicating if currently 'clicked'.
        bool isClicked;

        // Flag indicating if currenlt enabled.
        bool isEnabled;

        // Flag indicating if currently 'focussed'.
        bool isFocussed;

    protected:
        // Listen for mouse presses/clicks.
        void mousePressEvent(QMouseEvent * event) override {
            if (!this->isEnabled) {
                return;
            }

            event->accept();
            this->onClick();

            this->isClicked = true;
            this->isFocussed = true;
        }

        // Listen for mouse moves.
        void mouseMoveEvent(QMouseEvent * event) override {
            if (!this->isEnabled) {
                return;
            }

            if (this->isClicked) {
                QRect rect = this->rect();
                QPoint pos = event->pos();
                bool inWidget = (pos.x() >= rect.x() && pos.x() < rect.x() + rect.width() &&
                                 pos.y() >= rect.y() && pos.y() < rect.y() + rect.height());

                if (inWidget && !this->isFocussed) {
                    this->isFocussed = true;
                    this->onRegainedFocus();

                } else if (!inWidget && this->isFocussed){
                    this->isFocussed = false;
                    this->onLostFocus();
                }
            }
        }

        // Listen for mouse release.
        void mouseReleaseEvent(QMouseEvent * event) override {
            if (!this->isEnabled) {
                return;
            }

            if (this->isClicked) {
                event->accept();
                this->onRelease();
            }

            this->isClicked = false;
            this->isFocussed = false;
        }

        // To be implemented by the inheriting class.
        // Called when the widget is initially clicked (but not released).
        virtual void onClick() = 0;

        // To be implemented by the inheriting class.
        // Called when the widget was clicked and the mouse is navigated
        // back to the widget.
        virtual void onRegainedFocus() = 0;

        // To be implemented by the inheriting class.
        // Called when the widget is clicked and the mouse is navigated
        // off the widget.
        virtual void onLostFocus() = 0;

        // To be implemented by the inheriting class.
        // Called when the widget is clicked and has the button released
        // (i.e. has been clicked).
        virtual void onRelease() = 0;

    public:
        // Constructor.
        IClickable(QWidget * parent) : QWidget(parent) {
            this->isClicked = false;
            this->isEnabled = true;
            this->isFocussed = false;
        }

        // Enables/disables the ability to react to clicks.
        virtual void setEnabled(const bool enabled) {
            this->isEnabled = enabled;

            if (!enabled) {
                this->isClicked = false;
                this->isFocussed = false;
                this->update();
            }
        }
};

#endif
