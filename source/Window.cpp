#include <QPalette>
#include <QPixmap>
#include <QScrollArea>
#include <QScroller>
#include <QStackedWidget>

#include "factory/ConfigFactory.hpp"
#include "Launcher.hpp"
#include "widget/StatusBar.hpp"
#include "widget/ToolBar.hpp"
#include "Window.hpp"

Window::Window(QWidget * parent) : QWidget(parent) {
    // Get config object
    ConfigFactory configFactory;
    IConfig * config = configFactory.getConfig();

    // Force resize to 800x480
    // TODO: Remove the forced size, scale dynamically
    this->resize(800, 480);
    this->setStyleSheet("background: transparent");

    // Set the background of the window
    QWidget * background = new QWidget(this);
    background->setStyleSheet(QString::fromStdString("background-image: url('" + config->backgroundImageFilePath() + "');"));
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

    Launcher * launcher = new Launcher(scrollArea);
    scrollArea->setWidget(launcher);
    launcher->resize(scrollArea->width(), launcher->height());
}
