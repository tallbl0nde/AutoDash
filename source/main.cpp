#include <QApplication>
#include <QFontDatabase>

#include "Window.hpp"

int main(int argc, char * argv[]) {
    // Create the application object
    QApplication app(argc, argv);

    // Initialize our custom fonts
    QFontDatabase::addApplicationFont("/home/jonathon/Pivot/resources/fonts/Rubik.ttf");

    // Create and show the main window
    Window w;
    w.show();

    return app.exec();
}
