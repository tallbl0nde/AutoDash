#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP

#include <QGridLayout>
#include <QWidget>

// Main page for 'launching' subwidgets.
class Launcher : public QWidget {
    Q_OBJECT

    private:
        QGridLayout * grid;

        int entries;

    public:
        // Constructs a new launcher.
        explicit Launcher(QWidget * parent = nullptr);

        // Adds an entry to the launcher.
        void addEntry(const QString iconPath, const QString name, const QString version);

        // Finalizes the launcher after adding entries.
        void finalize(QWidget *);
};

#endif
