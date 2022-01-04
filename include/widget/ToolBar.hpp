#ifndef WIDGET_TOOLBAR_HPP
#define WIDGET_TOOLBAR_HPP

#include "widget/Bar.hpp"
#include "widget/SVGLabel.hpp"

namespace Widget {
    class ToolBar : public Bar {
        Q_OBJECT

        private:
            // Back button.
            SVGLabel * back;

        public:
            // Creates a new ToolBar.
            explicit ToolBar(QWidget * parent = nullptr);

            // Toggles the state of the back button.
            void setBackEnabled(const bool enable);

            // Destructor.
            ~ToolBar();
    };
};

#endif
