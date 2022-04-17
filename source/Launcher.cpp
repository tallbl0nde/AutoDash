#include <QPushButton>
#include <QVBoxLayout>

#include "Launcher.hpp"
#include "widget/LauncherEntry.hpp"

#include <iostream>
#include "Log.hpp"

Launcher::Launcher(QWidget * parent) : QWidget(parent) {
    this->entries = 0;

    // Initialize the grid
    // TODO: Scale in terms of resolution
    this->grid = new QGridLayout(this);
    this->grid->setMargin(30);
    this->grid->setHorizontalSpacing(30);
    this->grid->setVerticalSpacing(20);
}

void Launcher::addEntry(const QString iconPath, const QString name, const QString version, const std::function<void()> & onPress) {
    // Add a widget for the entry
    Widget::LauncherEntry * module = new Widget::LauncherEntry();
    module->setLabel(name);
    module->setSVG(iconPath);
    module->onClicked(onPress);

    // TODO: Scale with window size
    module->setFixedHeight(90);

    this->grid->addWidget(module, entries/2, entries%2, Qt::AlignTop);
    entries++;
}

void Launcher::finalize(QWidget * parent) {
    // Add placeholder to get a second column
    if (entries < 2) {
        QWidget * w = new QWidget();
        w->setMaximumHeight(100);
        this->grid->addWidget(w, 0, 1, Qt::AlignTop);
    }

    // Resize to parent
    this->resize(parent->size());
}
