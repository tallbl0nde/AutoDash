#include <QGraphicsColorizeEffect>
#include <QHBoxLayout>
#include <QSvgWidget>

#include <iostream>
#include "Log.hpp"

#include "settings/SettingsFrame.hpp"

SettingsFrame::SettingsFrame(Template::IHeaderPage * parent, std::vector<ModuleSettingsData> moduleSettingsData, IResolver * resolver) : QWidget(parent->widget()) {
    parent->setHeadingText("Settings");
    parent->setIcon(new QSvgWidget(":/Settings/icons/settings.svg"));
    this->window = resolver->window();

    ITemplateProvider * templateProvider = resolver->templateProvider();

    // TODO: Actually add widgets
    for (auto module : moduleSettingsData) {
        for (auto entry : module.settingEntries) {

        }
    }

    // TODO: Do this better probably
    QGraphicsColorizeEffect * iconEffect;
    Template::IList * list = templateProvider->createList();
    Template::IListSpacer * spacer = templateProvider->createListSpacer();
    list->addItem(spacer);

    IListOptionFactory * factory = templateProvider->listOptionFactory();
    Template::IListOption * brightnessOption = factory->createComboBox("", "", "100%", {"10%", "25%", "50%", "75%", "100%"}, [this](std::string value) {
        this->onBrightnessChanged(value);
    });
    QSvgWidget * brightnessIcon = new QSvgWidget(":/Settings/icons/sun.svg");
    iconEffect = new QGraphicsColorizeEffect();
    iconEffect->setColor(QColor{255, 255, 255});
    brightnessIcon->setGraphicsEffect(iconEffect);
    brightnessOption->setDescription("Set the brightness of the display");
    brightnessOption->setLabel("Brightness");
    brightnessOption->setIcon(brightnessIcon);
    list->addItem(brightnessOption);

    list->addItem(templateProvider->createListSeparator());

    Template::IListButton * minimizeButton = templateProvider->createListButton();
    QSvgWidget * minimizeIcon = new QSvgWidget(":/Settings/icons/minimize.svg");
    iconEffect = new QGraphicsColorizeEffect();
    iconEffect->setColor(QColor{255, 255, 255});
    minimizeIcon->setGraphicsEffect(iconEffect);
    minimizeButton->setDescription("Minimize AutoDash and show the desktop");
    minimizeButton->setIcon(minimizeIcon);
    minimizeButton->setLabel("Minimize");
    templateProvider->connect(minimizeButton, SIGNAL(clicked()), this, SLOT(onMinimizeClicked()));
    list->addItem(minimizeButton);

    list->addItem(templateProvider->createListSeparator());

    Template::IListButton * reloadButton = templateProvider->createListButton();
    QSvgWidget * reloadIcon = new QSvgWidget(":/Settings/icons/reload.svg");
    iconEffect = new QGraphicsColorizeEffect();
    iconEffect->setColor(QColor{255, 255, 255});
    reloadIcon->setGraphicsEffect(iconEffect);
    reloadButton->setDescription("Reload AutoDash");
    reloadButton->setIcon(reloadIcon);
    reloadButton->setLabel("Reload");
    templateProvider->connect(reloadButton, SIGNAL(clicked()), this, SLOT(onReloadClicked()));
    list->addItem(reloadButton);

    list->addItem(templateProvider->createListSeparator());

    Template::IListButton * rebootButton = templateProvider->createListButton();
    QSvgWidget * rebootIcon = new QSvgWidget(":/Settings/icons/restart.svg");
    iconEffect = new QGraphicsColorizeEffect();
    iconEffect->setColor(QColor{255, 255, 255});
    rebootIcon->setGraphicsEffect(iconEffect);
    rebootButton->setDescription("Reboot the computer");
    rebootButton->setIcon(rebootIcon);
    rebootButton->setLabel("Reboot");
    templateProvider->connect(rebootButton, SIGNAL(clicked()), this, SLOT(onRebootClicked()));
    list->addItem(rebootButton);

    list->addItem(templateProvider->createListSeparator());

    Template::IListButton * shutdownButton = templateProvider->createListButton();
    QSvgWidget * shutdownIcon = new QSvgWidget(":/Settings/icons/shutdown.svg");
    iconEffect = new QGraphicsColorizeEffect();
    iconEffect->setColor(QColor{255, 255, 255});
    shutdownIcon->setGraphicsEffect(iconEffect);
    shutdownButton->setDescription("Safely shutdown the computer");
    shutdownButton->setIcon(shutdownIcon);
    shutdownButton->setLabel("Shutdown");
    templateProvider->connect(shutdownButton, SIGNAL(clicked()), this, SLOT(onShutdownClicked()));
    list->addItem(shutdownButton);

    spacer = templateProvider->createListSpacer();
    spacer->setSize(20);
    list->addItem(spacer);

    parent->setMainWidget(list->widget());
}

void SettingsFrame::onBrightnessChanged(std::string value) {
    // Strip '%' off the end
    value = value.substr(0, value.length() - 1);

    // Write out to file
    #ifdef RPI_BUILD
        std::ofstream backlightFile("/sys/class/backlight/rpi_backlight/brightness");
        backlightFile << std::to_string(static_cast<int>(std::stoi(value) * 2.55)) << std::endl;
    #else
        std::cout << "Brightness set to " << value << "%" << std::endl;
    #endif
}

void SettingsFrame::onMinimizeClicked() {
    this->window->showMinimized();
}

void SettingsFrame::onReloadClicked() {
    // TODO: Actually work
    #ifdef RPI_BUILD
        system("pkill -f AutoDash && /home/pi/AutoDash/bin/AutoDash");
    #else
        system("pkill -f AutoDash && /home/jonathon/AutoDash/bin/AutoDash");
    #endif
}

void SettingsFrame::onRebootClicked() {
    system("sudo reboot");
}

void SettingsFrame::onShutdownClicked() {
    system("sudo shutdown now");
}