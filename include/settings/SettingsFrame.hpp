#ifndef SETTINGS_SETTINGSFRAME_HPP
#define SETTINGS_SETTINGSFRAME_HPP

#include "interface/IModule.hpp"
#include "interface/IResolver.hpp"
#include "interface/ISettingEntry.hpp"
#include "interface/template/IHeaderPage.hpp"

class SettingsFrame : public QWidget {
    Q_OBJECT

    private:
        // Reference to window object.
        QWidget * window;

        void onBrightnessChanged(std::string value);

    private slots:
        void onMinimizeClicked();
        void onReloadClicked();
        void onRebootClicked();
        void onShutdownClicked();

    public:
        // Struct containing module metadata along with
        // the module's setting entries.
        struct ModuleSettingsData {
            IModule::Metadata metadata;
            std::vector<ISettingEntry *> settingEntries;
        };

    public:
        // Constructs a new SettingsFrame.
        SettingsFrame(Template::IHeaderPage * parent, std::vector<ModuleSettingsData> moduleSettingData, IResolver * resolver);
};

#endif