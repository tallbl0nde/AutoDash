#include <QHBoxLayout>
#include <QSvgWidget>

#include <iostream>
#include "Log.hpp"

#include "settings/SettingsFrame.hpp"

SettingsFrame::SettingsFrame(Template::IHeaderPage * parent, std::vector<ModuleSettingsData> moduleSettingsData, IResolver * resolver) : QWidget(parent->widget()) {
    parent->setHeadingText("Settings");
    parent->setIcon(new QSvgWidget(":/Settings/icons/settings.svg"));

    // TODO: Actually add widgets
    for (auto module : moduleSettingsData) {
        for (auto entry : module.settingEntries) {

        }
    }

    Template::IList * list = resolver->templateProvider()->createList();

    Template::IListSpacer * spacer = resolver->templateProvider()->createListSpacer();
    list->addItem(spacer);

    for (size_t i = 0; i < 20; i++) {
        Template::IListButton * test = resolver->templateProvider()->createListButton();
        connect(dynamic_cast<QObject *>(test), SIGNAL(pressed()), this, SLOT(onTestPressed()));
        test->setLabel("Android Auto Test");
        test->setIcon(new QSvgWidget(":/OpenAuto/icons/android-auto.svg"));
        list->addItem(test);

        Template::IListSeparator * sep = resolver->templateProvider()->createListSeparator();
        list->addItem(sep);
    }

    spacer = resolver->templateProvider()->createListSpacer();
    spacer->setSize(20);
    list->addItem(spacer);

    parent->setMainWidget(list->widget());

    // // Create test widget
    // QWidget * child = new QWidget();
    // QVBoxLayout * childLayout = new QVBoxLayout(child);

    // QWidget * buttonRow = new QWidget(child);
    // QHBoxLayout * buttonRowLayout = new QHBoxLayout(buttonRow);
    // childLayout->addWidget(buttonRow);

    // // Minimize button
    // QWidget * window = resolver->window();
    // Template::IButton * minimize = resolver->templateProvider()->createButton();
    // minimize->setButtonIcon(new QSvgWidget(":/Settings/icons/minimize.svg"));
    // minimize->setButtonText("Minimize");
    // minimize->setButtonAction([window]() {
    //     window->showMinimized();
    // });
    // minimize->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // buttonRowLayout->addWidget(minimize->widget(), 0, Qt::AlignVCenter);

    // // Reboot button
    // Template::IButton * reboot = resolver->templateProvider()->createButton();
    // reboot->setButtonIcon(new QSvgWidget(":/Settings/icons/restart.svg"));
    // reboot->setButtonText("Reboot");
    // reboot->setButtonAction([]() {
    //     // TODO: Better
    //     system("sudo reboot");
    // });
    // reboot->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // buttonRowLayout->addWidget(reboot->widget(), 0, Qt::AlignVCenter);

    // // Shutdown button
    // Template::IButton * shutdown = resolver->templateProvider()->createButton();
    // shutdown->setButtonIcon(new QSvgWidget(":/Settings/icons/shutdown.svg"));
    // shutdown->setButtonText("Shutdown");
    // shutdown->setButtonAction([]() {
    //     // TODO: Better
    //     system("sudo shutdown now");
    // });
    // shutdown->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // buttonRowLayout->addWidget(shutdown->widget(), 0, Qt::AlignVCenter);


    // QWidget * sliderRow = new QWidget(child);
    // QHBoxLayout * sliderRowWidget = new QHBoxLayout(sliderRow);
    // childLayout->addWidget(sliderRow);

    // Template::IHorizontalIntSlider * slider = resolver->templateProvider()->createHorizontalIntSlider();
    // slider->setLabelFormatter([](int value) {
    //     return std::to_string(value) + "%";
    // });
    // slider->setAccentColour(50, 100, 200);
    // slider->setSliderMin(0);
    // slider->setSliderMax(100);
    // slider->setSliderStep(1);
    // slider->setSliderValue(100);
    // slider->setSliderAction([](int value) {
    //     #ifdef RPI_BUILD
    //         std::ofstream backlightFile("/sys/class/backlight/rpi_backlight/brightness");
    //         backlightFile << std::to_string(static_cast<int>(value * 2.55)) << std::endl;
    //     #else
    //         std::cout << value << std::endl;
    //     #endif
    // });
    // slider->widget()->setGeometry(0, 0, 100, 50);

    // sliderRowWidget->addWidget(slider->widget());

    // parent->setMainWidget(child);
}

void SettingsFrame::onTestPressed() {
    std::cout << "CLICK!" << std::endl;
}