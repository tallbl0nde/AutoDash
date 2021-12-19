#ifndef WIDGET_TOOLBAR_HPP
#define WIDGET_TOOLBAR_HPP

#include "widget/Bar.hpp"

namespace Widget {
    class ToolBar : public Bar {
        Q_OBJECT

        public:
            // Creates a new ToolBar.
            explicit ToolBar(QWidget * parent = nullptr);

            // Destructor.
            ~ToolBar();
    };
};

#endif
