#ifndef SETTINGS_SETTINGSFRAME_HPP
#define SETTINGS_SETTINGSFRAME_HPP

#include "interface/IModule.hpp"
#include "interface/IResolver.hpp"
#include "interface/ISettingEntry.hpp"
#include "interface/template/IHeaderPage.hpp"

class SettingsFrame : public QWidget {
    Q_OBJECT

    public:
        // Struct containing module metadata along with
        // the module's setting entries.
        struct ModuleSettingsData {
            IModule::Metadata metadata;
            std::vector<ISettingEntry *> settingEntries;
        };

    private slots:
        // TODO: Remove
        void onTestPressed();

    public:
        // Constructs a new SettingsFrame.
        SettingsFrame(Template::IHeaderPage * parent, std::vector<ModuleSettingsData> moduleSettingData, IResolver * resolver);
};

#endif