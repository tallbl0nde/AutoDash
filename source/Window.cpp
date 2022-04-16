#include <QScrollArea>
#include <QScroller>
#include <QStackedWidget>

#include "factory/ConfigFactory.hpp"
#include "interface/IModule.hpp"
#include "Launcher.hpp"
#include "widget/MainFrame.hpp"
#include "widget/Taskbar.hpp"
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

    // Create the main area
    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);
    Widget::MainFrame * stack = new Widget::MainFrame(scrollArea, this);

    // Create the taskbar
    Widget::Taskbar * taskbar = new Widget::Taskbar(Widget::Taskbar::Orientation::Vertical, this);
    taskbar->setBackButtonEnabled(false);
    taskbar->setGeometry(this->width() - 80, 0, 80, this->height());
    taskbar->onBackButtonClicked([stack]() {
        stack->goBack();
    });
    taskbar->onLauncherButtonClicked([stack]() {
        stack->goHome();
    });

    // Create the launcher
    Launcher * launcher = new Launcher(scrollArea);
    stack->setGeometry(0, 0, this->width() - taskbar->width(), this->height());
    stack->onWidgetChanged([taskbar](int frames) {
        taskbar->setBackButtonEnabled(frames > 1);
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
