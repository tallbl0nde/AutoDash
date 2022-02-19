#include <iostream>
#include <QApplication>
#include <QDirIterator>
#include <QFontDatabase>

#include "factory/ConfigFactory.hpp"
#include "Window.hpp"

int main(int argc, char * argv[]) {
    // Create the application object
    QApplication app(argc, argv);

    // Initialize resources
    ConfigFactory configFactory;
    IConfig * config = configFactory.getConfig();

    // Initialize our custom fonts
    std::cout << "Scanning for fonts in '" << config->fontsFolderPath() << "'..." << std::endl;
    QDirIterator it(QString::fromStdString(config->fontsFolderPath()), QStringList() << "*.ttf", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        std::cout << "Adding font: " << it.fileName().toStdString() << std::endl;
        QFontDatabase::addApplicationFont(it.filePath());
    }

    // Create and show the main window
    Window * w = new Window();
    w->show();
    int result = app.exec();

    // Clean up resources
    configFactory.deleteConfigObject();

    return result;
}
