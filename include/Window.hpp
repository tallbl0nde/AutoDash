#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>

class Window : public QWidget {
    Q_OBJECT

    public:
        // Constructs a new window.
        explicit Window(QWidget * parent = nullptr);
};

#endif
