#include <QPalette>
#include <QPixmap>
#include <QScrollArea>
#include <QScroller>
#include <QStackedWidget>

#include "factory/ConfigFactory.hpp"
#include "interface/IModule.hpp"
#include "Launcher.hpp"
#include "widget/MainFrame.hpp"
#include "widget/StatusBar.hpp"
#include "widget/ToolBar.hpp"
#include "Window.hpp"

#include "Log.hpp"

Window::Window(std::vector<IModule *> modules, QWidget * parent) : QWidget(parent) {
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

    // Create the launcher
    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    Launcher * launcher = new Launcher(scrollArea);

    // Create the main widget stack with the launcher as the first widget
    Widget::MainFrame * stack = new Widget::MainFrame(scrollArea, this);
    stack->setGeometry(0, statusBar->y() + statusBar->height(), this->width(), this->height() - statusBar->height() - toolBar->height());
    stack->onWidgetChanged([toolBar](int historySize) {
         toolBar->setBackEnabled(historySize != 1);
    });
    scrollArea->resize(stack->size());

    // Process modules
    for (IModule * module : modules) {
        // Add widgets to the stack
        QWidget * widget = module->widget();
        stack->addWidget(widget);

        // Add entries to the launcher
        IModule::Metadata meta = module->metadata();
        launcher->addEntry(meta.iconPath, meta.name, meta.version, [stack, widget]() {
            stack->goToWidget(widget);
        });
    }

    launcher->finalize(stack);
}
