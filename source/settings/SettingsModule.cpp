#include "settings/SettingsFrame.hpp"
#include "settings/SettingsModule.hpp"
#include "Version.hpp"

SettingsModule::SettingsModule() {
    this->resolver = nullptr;
}

void SettingsModule::setModuleSettingEntries(std::vector<SettingsFrame::ModuleSettingsData> moduleSettingsData) {
    this->moduleSettingsData_ = moduleSettingsData;
}

std::string SettingsModule::versionCompiledFor() {
    return AUTODASH_VERSION;
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

std::vector<ISettingEntry *> SettingsModule::settingEntries(ISettingEntryFactory * settingEntryFactory) {
    // TODO: Probably add some entries here
    return std::vector<ISettingEntry *>();
}

QWidget * SettingsModule::widget(QWidget * parent) {
    Template::IHeaderPage * headerPage = this->resolver->templateProvider()->createHeaderPage();
    SettingsFrame * settingsFrame = new SettingsFrame(headerPage, this->moduleSettingsData_, this->resolver);
    return headerPage->widget();
}

SettingsModule::~SettingsModule() {

}