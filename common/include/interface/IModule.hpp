#ifndef INTERFACE_IMODULE_HPP
#define INTERFACE_IMODULE_HPP

#include <QObject>
#include <QtPlugin>
#include <QString>

#include "interface/factory/ISettingEntryFactory.hpp"
#include "interface/IResolver.hpp"

// Unique identifier for this interface.
#define IMODULE_IID "tallbl0nde.AutoDash.IModule"

// Represents the base methods of a module (Qt plugin).
class IModule {
    public:
        // Module metadata.
        struct Metadata {
            QString name;           // Module name
            QString author;         // Module author
            QString iconPath;       // Module icon path (SVG)
            QString version;        // Module version
        };

        // Creates a new module object.
        IModule() {}

        // Returns the version of AutoDash the module was compiled for.
        // This method should be implemented to return Version::version().
        virtual std::string versionCompiledFor() = 0;

        // Initializes the module.
        // This should always be called straight after creation.
        virtual void initialize(IResolver * resolver) = 0;

        // Returns the metadata for the module.
        virtual Metadata metadata() = 0;

        // Returns the setting entries for the module.
        // Order is important (first will be listed first).
        virtual std::vector<ISettingEntry *> settingEntries(ISettingEntryFactory *) = 0;

        // Returns the widget to show when selecting
        // this module from the launcher.
        virtual QWidget * widget(QWidget * parent = nullptr) = 0;

        // Destroys the module object.
        virtual ~IModule() {}
};

// Declare the class as a module interface.
Q_DECLARE_INTERFACE(IModule, IMODULE_IID)

#endif
