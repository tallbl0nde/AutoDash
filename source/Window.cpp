#include <QPalette>
#include <QPixmap>
#include <QScrollArea>
#include <QScroller>
#include <QStackedWidget>

#include "Launcher.hpp"
#include "widget/StatusBar.hpp"
#include "widget/ToolBar.hpp"
#include "Window.hpp"

Window::Window(QWidget * parent) : QWidget(parent) {
    // Force resize to 800x480
    // TODO: Remove the forced size, scale dynamically
    this->resize(800, 480);
    this->setStyleSheet("background: transparent");

    // Set the background of the window
    // TODO: Relative path / allow changing within
    QWidget * background = new QWidget(this);
    background->setStyleSheet("background-image: url('/home/jonathon/AutoDash/resources/backgrounds/index.jpeg');");
    background->setGeometry(this->rect());
    background->setFixedSize(this->size());

    // Create and position status bar
    Widget::StatusBar * statusBar = new Widget::StatusBar(this);
    statusBar->setGeometry(0, 0, this->width(), statusBar->height());
    statusBar->setTitle("Home");

    // Create and position tool bar
    Widget::ToolBar * toolBar = new Widget::ToolBar(this);
    toolBar->setGeometry(0, this->height() - toolBar->height(), this->width(), toolBar->height());

    // Create the main widget stack with the launcher as the first widget
    QStackedWidget * stack = new QStackedWidget(this);
    stack->setGeometry(0, statusBar->y() + statusBar->height(), this->width(), this->height() - statusBar->height() - toolBar->height());

    QScrollArea * scrollArea = new QScrollArea(stack);
    scrollArea->resize(stack->size());
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    Launcher * launcher = new Launcher();
    scrollArea->setWidget(launcher);
    launcher->resize(scrollArea->width(), launcher->height());
}
