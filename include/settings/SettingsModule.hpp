#ifndef SETTINGS_SETTINGSMODULE_HPP
#define SETTINGS_SETTINGSMODULE_HPP

#include "interface/IModule.hpp"

class SettingsModule : public QObject, public IModule {
    private:
        // Module setting entries.
        std::vector<std::vector<ISettingEntry *>> moduleSettingEntries_;

        // Resolver object.
        IResolver * resolver;

    public:
        // Creates a new settings 'module'.
        SettingsModule();

        // Store setting entries for each module.
        void setModuleSettingEntries(std::vector<std::vector<ISettingEntry *>> moduleSettingEntries);

        // Implement IModule.
        virtual std::string versionCompiledFor() override;
        virtual void initialize(IResolver * resolver) override;
        virtual IModule::Metadata metadata() override;
        virtual std::vector<ISettingEntry *> settingEntries(ISettingEntryFactory *) override;
        virtual QWidget * widget(QWidget * parent) override;

        // Destroys the settings module.
        ~SettingsModule();
};

#endif