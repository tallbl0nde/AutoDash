#ifndef WIDGET_BASECLICKABLE_HPP
#define WIDGET_BASECLICKABLE_HPP

#include <QColor>
#include <QWidget>

#include "interface/IClickable.hpp"

namespace Widget {
    // Interface for a QWidget that responds to clicks/presses.
    class BaseClickable : public QWidget, virtual public IClickable {
        Q_OBJECT
        Q_INTERFACES(IClickable)

        private:
            // Flag indicating if currently 'clicked'.
            bool isClicked;

            // Flag indicating if currently enabled.
            bool isEnabled;

            // Flag indicating if currently 'focussed'.
            bool isFocussed;

            // Colour of highlight.
            QColor highlightColour;

            // Radius of highlight corners.
            int highlightCornerRadius;

        protected:
            // Override to show highlight when clicked.
            virtual void paintEvent(QPaintEvent * event) override;

            // Implement IClickable.
            void mousePressEvent(QMouseEvent * event) override;
            void mouseMoveEvent(QMouseEvent * event) override;
            void mouseReleaseEvent(QMouseEvent * event) override;

        public:
            // Constructs a new BaseClickable.
            BaseClickable(QWidget * parent = nullptr);

        public slots:
            // Sets the colour of the highlight displayed when clicked.
            void setHighlightColour(QColor colour);

            // Sets the shape of the highlight displayed when clicked.
            // roundRectRadius is ignored if isRoundRect is false.
            void setHighlightShape(bool isRoundRect, int roundRectRadius = 5);

            // Implement IClickable.
            virtual void setEnabled(const bool enabled) override;

        signals:
            // Implement IClickable.
            void clicked() override;
            void released() override;
    };
};

#endif
