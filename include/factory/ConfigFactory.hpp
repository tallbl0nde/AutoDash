#ifndef FACTORY_CONFIGFACTORY_HPP
#define FACTORY_CONFIGFACTORY_HPP

#include "interface/IConfig.hpp"

// Singleton factory to return a *single* instance of an IConfig class.
class ConfigFactory {
    public:
        // Types of config storage.
        enum class ConfigType {
            Base              // In-memory, resets after each start.
        };

    private:
        // IConfig instance.
        static IConfig * instance;

    public:
        // Creates a new ConfigFactory.
        ConfigFactory();

        // Returns the IConfig instance.
        IConfig * getConfig();

        // Deletes the IConfig object.
        // This should be called as one of the final steps
        // in the exit sequence to avoid UB.
        void deleteConfigObject();

        // Changes the returned config type.
        // This should be called *only* if it is known no
        // other references to the existing config object
        // are being held, as it will be deleted.
        void changeConfigType(const ConfigType);

        // Destroys the ConfigFactory.
        ~ConfigFactory();
};

#endif
