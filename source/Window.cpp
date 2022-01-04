#include <QPalette>
#include <QPixmap>
#include <QStackedWidget>

#include "Launcher.hpp"
#include "widget/StatusBar.hpp"
#include "widget/ToolBar.hpp"
#include "Window.hpp"

Window::Window(QWidget * parent) : QWidget(parent) {
    // Force resize to 800x480
    // TODO: Remove the forced size, scale dynamically
    this->resize(800, 480);

    // Set the background of the window
    // TODO: Relative path / allow changing within
    QPixmap background("/home/jonathon/AutoDash/resources/backgrounds/index.jpeg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    // Create and position status bar
    Widget::StatusBar * statusBar = new Widget::StatusBar(this);
    statusBar->setGeometry(0, 0, this->width(), statusBar->height());
    statusBar->setTitle("Home");

    // Create the main widget stack
    QStackedWidget * stack = new QStackedWidget(this);
    stack->setGeometry(0, statusBar->y() + statusBar->height(), this->width(), this->height() - statusBar->height());

    // Create and position tool bar
    Widget::ToolBar * toolBar = new Widget::ToolBar(this);
    toolBar->setGeometry(0, this->height() - toolBar->height(), this->width(), toolBar->height());
}
