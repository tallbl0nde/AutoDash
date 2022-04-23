#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <vector>

#include "interface/IModule.hpp"

// Root application object.
class Window : public QWidget {
    Q_OBJECT

    public:
        // Constructs a new window.
        explicit Window(QWidget * parent = nullptr);

        void initialize(std::vector<IModule *> modules);
};

#endif
