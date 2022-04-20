#include "settings/SettingsFrame.hpp"
#include "settings/SettingsModule.hpp"

SettingsModule::SettingsModule() {
    this->resolver = nullptr;
}

void SettingsModule::initialize(IResolver * resolver) {
    this->resolver = resolver;
}

IModule::Metadata SettingsModule::metadata() {
    return IModule::Metadata {
        "Settings",                             // Name
        "tallbl0nde",                           // Author
        ":/Settings/icons/settings.svg",        // Icon
        "1.0.0"                                 // Version
    };
}

QWidget * SettingsModule::widget(QWidget * parent) {
    Template::IHeaderPage * headerPage = this->resolver->templateProvider()->createHeaderPage();
    SettingsFrame * settingsFrame = new SettingsFrame(headerPage);
    return headerPage->widget();
}

SettingsModule::~SettingsModule() {

}