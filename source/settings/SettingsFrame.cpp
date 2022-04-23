#include <QHBoxLayout>
#include <QSvgWidget>

#include "settings/SettingsFrame.hpp"

SettingsFrame::SettingsFrame(Template::IHeaderPage * parent, IResolver * resolver) : QWidget(parent->widget()) {
    parent->setHeadingText("Settings");

    // Create test widget
    QWidget * child = new QWidget();
    QHBoxLayout * buttonRow = new QHBoxLayout(child);

    // Minimize button
    QWidget * window = resolver->window();
    Template::IButton * minimize = resolver->templateProvider()->createButton();
    minimize->setButtonIcon(new QSvgWidget(":/Settings/icons/minimize.svg"));
    minimize->setButtonText("Minimize");
    minimize->setButtonAction([window]() {
        window->showMinimized();
    });
    minimize->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonRow->addWidget(minimize->widget(), 0, Qt::AlignVCenter);

    // Reboot button
    Template::IButton * reboot = resolver->templateProvider()->createButton();
    reboot->setButtonIcon(new QSvgWidget(":/Settings/icons/restart.svg"));
    reboot->setButtonText("Reboot");
    reboot->setButtonAction([]() {
        // TODO: Better
        system("sudo reboot");
    });
    reboot->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonRow->addWidget(reboot->widget(), 0, Qt::AlignVCenter);

    // Shutdown button
    Template::IButton * shutdown = resolver->templateProvider()->createButton();
    shutdown->setButtonIcon(new QSvgWidget(":/Settings/icons/shutdown.svg"));
    shutdown->setButtonText("Shutdown");
    shutdown->setButtonAction([]() {
        // TODO: Better
        system("sudo shutdown now");
    });
    shutdown->widget()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonRow->addWidget(shutdown->widget(), 0, Qt::AlignVCenter);

    parent->setMainWidget(child);
}