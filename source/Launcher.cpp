#include <QPushButton>
#include <QVBoxLayout>

#include "Launcher.hpp"
#include "widget/PluginIcon.hpp"

#include <iostream>

Launcher::Launcher(QWidget * parent) : QWidget(parent) {
    // Initialize the grid
    // TODO: Scale in terms of resolution
    QGridLayout * grid = new QGridLayout();
    grid->setMargin(20);
    grid->setHorizontalSpacing(30);
    grid->setVerticalSpacing(20);

    // Add a widget for each plugin
    // TODO: Use plugins
    int rows = 10;
    int columns = 2;
    for (size_t i = 0; i < (rows * columns); i++) {
        Widget::PluginIcon * plugin = new Widget::PluginIcon();
        std::string str = "Plugin Number " + std::to_string(i);
        plugin->setLabel(QString::fromStdString(str));
        plugin->setSVG("/home/jonathon/AutoDash/resources/icons/back.svg");
        plugin->setMinimumHeight(100);

        int row = (i/columns);
        int column = (i%columns);
        grid->addWidget(plugin, row, column);
    }


    this->setLayout(grid);
}
