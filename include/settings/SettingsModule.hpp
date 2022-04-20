#ifndef SETTINGS_SETTINGSMODULE_HPP
#define SETTINGS_SETTINGSMODULE_HPP

#include "interface/IModule.hpp"

class SettingsModule : public QObject, public IModule {
    private:
        // Resolver object.
        IResolver * resolver;

    public:
        // Creates a new settings 'module'.
        SettingsModule();

        // Implement IModule.
        virtual std::string versionCompiledFor() override;
        virtual void initialize(IResolver * resolver) override;
        virtual IModule::Metadata metadata() override;
        virtual QWidget * widget(QWidget * parent) override;

        // Destroys the settings module.
        ~SettingsModule();
};

#endif