#ifndef MODULELOADER_HPP
#define MODULELOADER_HPP

#include "interface/IModule.hpp"
#include "interface/IResolver.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class QPluginLoader;

// Loads in modules from the given directory.
class ModuleLoader {
    private:
        // Root modules folder.
        std::string modulesFolder;

        // Resolver object.
        IResolver * resolver;

        // Module and loader instances.
        std::unordered_map<IModule *, QPluginLoader *> moduleLoaderMap;

    public:
        // Creates a new ModuleLoader.
        ModuleLoader(IResolver * resolver, const std::string & modulesFolder);

        // Loads all modules in the directory.
        std::vector<IModule *> loadAllModules();

        // Loads the module in the given subdirectory.
        IModule * loadModule(const std::string & moduleFolder);

        // Unloads the given module.
        void unloadModule(IModule * module);

        // Destroys the module loader.
        ~ModuleLoader();
};

#endif
