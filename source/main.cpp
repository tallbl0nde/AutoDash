#include <QApplication>
#include <QDirIterator>
#include <QFontDatabase>

#include "factory/ConfigFactory.hpp"
#include "factory/SettingEntryFactory.hpp"
#include "Log.hpp"
#include "ModuleLoader.hpp"
#include "Resolver.hpp"
#include "settings/SettingsModule.hpp"
#include "TemplateProvider.hpp"
#include "Window.hpp"

int main(int argc, char * argv[]) {
    // Create the application object
    QApplication app(argc, argv);
    app.setOrganizationName("tallbl0nde");
    app.setApplicationName("AutoDash");
    Window * w = new Window();

    // Initialize resources
    ConfigFactory configFactory;
    IConfig * config = configFactory.getConfig();

    Log::setIndentAmount(4);
    Log::setLogLevel(Log::Level::Info);
    Log::setLogLocation(Log::Location::Console);

    // Initialize our custom fonts
    Log::logInfo(std::string("Loading fonts in ':/'..."));
    Log::increaseIndent();
    QDirIterator it(":/", QStringList() << "*.ttf", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        Log::logInfo("Adding font: " + it.fileName().toStdString());
        QFontDatabase::addApplicationFont(it.filePath());
    }
    Log::decreaseIndent();

    // Initialize the resolver and the objects it resolves
    Resolver * resolver = new Resolver();
    resolver->setTemplateProvider(new TemplateProvider());
    resolver->setWindow(w);

    // Load any installed modules
    ModuleLoader moduleLoader = ModuleLoader(resolver, config->modulesFolderPath());
    std::vector<IModule *> realModules = moduleLoader.loadAllModules();

    // Add a 'fake' IModule for the settings
    // (settings can't be a module but it will act like one :P)
    std::vector<IModule *> fakeModules;
    SettingsModule * settingsModule = new SettingsModule();
    settingsModule->initialize(resolver);
    fakeModules.push_back(settingsModule);

    // Concat all module types into one
    std::vector<IModule *> modules;
    modules.reserve(fakeModules.size() + realModules.size());
    modules.insert(modules.end(), fakeModules.begin(), fakeModules.end());
    modules.insert(modules.end(), realModules.begin(), realModules.end());

    // Add settings to the SettingsModule (alphabetically)
    std::sort(modules.begin(), modules.end(), [](IModule * lhs, IModule * rhs) {
        return (lhs->metadata().name < rhs->metadata().name);
    });

    SettingEntryFactory * settingEntryFactory = new SettingEntryFactory();
    std::vector<SettingsFrame::ModuleSettingsData> moduleSettingEntries;
    for (IModule * module : modules) {
        SettingsFrame::ModuleSettingsData data = {module->metadata(), module->settingEntries(settingEntryFactory)};
        moduleSettingEntries.push_back(data);
    }

    settingsModule->setModuleSettingEntries(moduleSettingEntries);
    delete settingEntryFactory;

    // Create and show the main window
    w->initialize(modules);
#ifdef RPI_BUILD
    w->setWindowState(Qt::WindowFullScreen);
#endif
    w->show();
    int result = app.exec();

    // Unload modules
    for (IModule * module : fakeModules) {
        delete module;
    }

    for (IModule * module : realModules) {
        moduleLoader.unloadModule(module);
    }

    fakeModules.clear();
    realModules.clear();
    modules.clear();

    // Clean up resources
    configFactory.deleteConfigObject();

    return result;
}
