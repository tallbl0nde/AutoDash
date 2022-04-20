#include "Log.hpp"
#include "ModuleLoader.hpp"
#include "Version.hpp"

#include <QDir>
#include <QPluginLoader>

ModuleLoader::ModuleLoader(IResolver * resolver, const std::string & modulesFolder) {
    this->modulesFolder = modulesFolder;
    this->resolver = resolver;
}

std::vector<IModule *> ModuleLoader::loadAllModules() {
    Log::logInfo("Scanning for supported modules in '" + this->modulesFolder + "'...");
    Log::increaseIndent();

    std::vector<IModule *> modules;
    QDir modulesDir(QString::fromStdString(this->modulesFolder));
    for (const QString & moduleName : modulesDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        IModule * module = this->loadModule(moduleName.toStdString());
        if (module != nullptr) {
            modules.push_back(module);
        }
    }

    Log::decreaseIndent();
    return modules;
}

IModule * ModuleLoader::loadModule(const std::string & moduleFolder) {
    // Change to 'module' directory
    Log::logInfo("Found '" + moduleFolder + "'");
    QDir moduleDir = QDir(QString::fromStdString(this->modulesFolder)).absoluteFilePath(QString::fromStdString(moduleFolder));
    moduleDir.cd("module");

    // Attempt to load module
    Log::increaseIndent();
    QPluginLoader * loader = new QPluginLoader(moduleDir.absoluteFilePath(moduleDir.entryList(QDir::Files).first()));
    QObject * module = loader->instance();
    IModule * moduleObject = qobject_cast<IModule *>(module);
    if (module == nullptr) {
        Log::logError("Couldn't load module: " + loader->errorString().toStdString());

    } else {
        if (moduleObject != nullptr) {
            // Check version
            if (moduleObject->versionCompiledFor() != AUTODASH_VERSION) {
                Log::logWarning(QString("This module was compiled for a different version of AutoDash."));
                Log::logWarning(QString("Various problems such as weird behaviour/bugs/crashes may occur."));
                Log::logWarning(QString("Please update/downgrade this module ASAP."));
                Log::logWarning(QString("AutoDash version: " AUTODASH_VERSION));
                Log::logWarning("Module version: " + moduleObject->versionCompiledFor());
            }

            moduleObject->initialize(this->resolver);

            Log::logInfo(std::string("Loaded module successfully!"));
            Log::logInfo("Name:       " + moduleObject->metadata().name);
            Log::logInfo("Author:     " + moduleObject->metadata().author);
            Log::logInfo("Icon Path:  " + moduleObject->metadata().iconPath);
            Log::logInfo("Version:    " + moduleObject->metadata().version);

            this->moduleLoaderMap[moduleObject] = loader;

        } else {
            loader->unload();
            delete loader;
        }
    }

    Log::decreaseIndent();
    return moduleObject;
}

void ModuleLoader::unloadModule(IModule * module) {
    if (this->moduleLoaderMap.count(module) != 0) {
        this->moduleLoaderMap[module]->unload();
        delete this->moduleLoaderMap[module];

        this->moduleLoaderMap.erase(module);
    }
}

ModuleLoader::~ModuleLoader() {
    for (auto & entry : this->moduleLoaderMap) {
        this->unloadModule(entry.first);
    }
}
