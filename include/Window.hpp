#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <vector>

#include "Log.hpp"

class IModule;

// Root application object.
class Window : public QWidget {
    Q_OBJECT

    public:
        // Constructs a new window.
        explicit Window(std::vector<IModule *> modules, QWidget * parent = nullptr);
};

#endif
