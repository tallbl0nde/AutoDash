#include "settings/SettingsFrame.hpp"

SettingsFrame::SettingsFrame(Template::IHeaderPage * parent) : QWidget(parent->widget()) {
    parent->setHeadingText("Settings");

    // Create test widget
    QWidget * child = new QWidget();
    parent->setMainWidget(child);
}