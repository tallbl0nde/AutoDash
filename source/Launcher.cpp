#include <QPushButton>
#include <QVBoxLayout>

#include "Launcher.hpp"
#include "widget/ModuleIcon.hpp"

#include <iostream>

Launcher::Launcher(QWidget * parent) : QWidget(parent) {
    this->entries = 0;

    // Initialize the grid
    // TODO: Scale in terms of resolution
    this->grid = new QGridLayout();
    this->grid->setMargin(20);
    this->grid->setHorizontalSpacing(30);
    this->grid->setVerticalSpacing(20);

    this->setLayout(this->grid);
}

void Launcher::addEntry(const QString iconPath, const QString name, const QString version) {
    // Add a widget for the entry
    Widget::ModuleIcon * plugin = new Widget::ModuleIcon();
    plugin->setLabel(name);
    plugin->setSVG(iconPath);

    // TODO: Scale with window size
    plugin->setMinimumHeight(100);
    plugin->setMaximumHeight(100);

    this->grid->addWidget(plugin, entries/2, entries%2, Qt::AlignTop);
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
