#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainWindow window;
    window.setWindowTitle("QtApp - Truncated Text");
    window.show();

    return app.exec();
}
