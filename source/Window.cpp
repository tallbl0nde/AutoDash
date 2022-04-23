#include <QScrollArea>
#include <QScroller>
#include <QStackedWidget>

#include "factory/ConfigFactory.hpp"
#include "Launcher.hpp"
#include "widget/MainFrame.hpp"
#include "widget/Taskbar.hpp"
#include "Window.hpp"

#include "Log.hpp"

Window::Window(QWidget * parent) : QWidget(parent) {
    // Force resize to 800x480
    // TODO: Remove the forced size, scale dynamically
    this->resize(800, 480);
    this->setStyleSheet("background: transparent");
}

void Window::initialize(std::vector<IModule *> modules) {
    // Get config object
    ConfigFactory configFactory;
    IConfig * config = configFactory.getConfig();

    // Set the background of the window
    QWidget * background = new QWidget(this);
    background->setStyleSheet(QString::fromStdString("background-image: url('" + config->backgroundImageFilePath() + "');"));
    background->setGeometry(this->rect());
    background->setFixedSize(this->size());

    QWidget * backgroundTint = new QWidget(this);
    backgroundTint->setStyleSheet("background-color: rgba(0, 0, 0, 130)");
    backgroundTint->setGeometry(this->rect());
    backgroundTint->setFixedSize(this->size());

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

    Widget::Favourites * favourites = taskbar->favouritesWidget();
    favourites->onEntryClicked([stack](std::string id) {
        stack->openFrame(id);
    });

    // Create the launcher
    Launcher * launcher = new Launcher(scrollArea);
    stack->setGeometry(0, 0, this->width() - taskbar->width(), this->height());
    stack->onFrameChanged([favourites, taskbar](std::string id, int frames) {
        favourites->setActiveEntry(id);
        taskbar->setBackButtonEnabled(frames > 1);
    });
    scrollArea->resize(stack->size());

    // Process modules in alphabetical order
    std::sort(modules.begin(), modules.end(), [](IModule * lhs, IModule * rhs) {
        return (lhs->metadata().name < rhs->metadata().name);
    });

    for (IModule * module : modules) {
        IModule::Metadata meta = module->metadata();

        // Add widgets to the stack
        QWidget * widget = module->widget(stack);
        stack->addFrame(meta.name.toStdString(), widget);

        // Add entries to the launcher
        launcher->addEntry(meta.iconPath, meta.name, meta.version, [meta, stack]() {
            stack->openFrame(meta.name.toStdString());
        });

        // TODO: Remove this
        favourites->addEntry(meta.name.toStdString(), meta.iconPath.toStdString());
    }

    launcher->finalize(stack);
}
