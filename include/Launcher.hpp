#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP

#include <QWidget>

// Main page for 'launching' subwidgets.
class Launcher : public QWidget {
    Q_OBJECT

    public:
        // Constructs a new launcher.
        explicit Launcher(QWidget * parent);
};

#endif
