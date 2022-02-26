#include <QApplication>
#include <QDirIterator>
#include <QFontDatabase>

#include "factory/ConfigFactory.hpp"
#include "interface/IModule.hpp"
#include "Log.hpp"
#include "ModuleLoader.hpp"
#include "Window.hpp"

int main(int argc, char * argv[]) {
    // Create the application object
    QApplication app(argc, argv);

    // Initialize resources
    ConfigFactory configFactory;
    IConfig * config = configFactory.getConfig();

    Log::setIndentAmount(4);
    Log::setLogLevel(Log::Level::Info);
    Log::setLogLocation(Log::Location::Console);

    // Initialize our custom fonts
    Log::logInfo("Scanning for .ttf fonts in '" + config->fontsFolderPath() + "'...");
    Log::increaseIndent();
    QDirIterator it(QString::fromStdString(config->fontsFolderPath()), QStringList() << "*.ttf", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        Log::logInfo("Adding font: " + it.fileName().toStdString());
        QFontDatabase::addApplicationFont(it.filePath());
    }
    Log::decreaseIndent();

    // Load any installed modules
    ModuleLoader moduleLoader = ModuleLoader(config->modulesFolderPath());
    std::vector<IModule *> modules = moduleLoader.loadAllModules();

    // Create and show the main window
    Window * w = new Window();
    w->show();
    int result = app.exec();

    // Unload modules
    for (IModule * module : modules) {
        moduleLoader.unloadModule(module);
    }
    modules.clear();

    // Clean up resources
    configFactory.deleteConfigObject();

    return result;
}
