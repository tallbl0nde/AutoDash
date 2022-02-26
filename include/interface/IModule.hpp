#ifndef INTERFACE_IMODULE_HPP
#define INTERFACE_IMODULE_HPP

#include <QObject>
#include <QtPlugin>
#include <QString>

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

        // Returns the metadata for the module.
        virtual Metadata metadata() = 0;

        // Destroys the module object.
        virtual ~IModule() {}
};

// Declare the class as a module interface.
Q_DECLARE_INTERFACE(IModule, IMODULE_IID)

#endif
