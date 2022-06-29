#include "gamecore.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    GameCore game;

    QObject::connect(&game, &GameCore::expectedClickCountChanged, &window, &MainWindow::expectedClickCountChanged);
    QObject::connect(&game, &GameCore::successCountChanged, &window, &MainWindow::successCountChanged);
    QObject::connect(&game, &GameCore::failureCountChanged, &window, &MainWindow::failureCountChanged);
    QObject::connect(&game, &GameCore::progressChanged, &window, &MainWindow::progressChanged);
    QObject::connect(&window, &MainWindow::clicked, &game, &GameCore::clicked);
    QObject::connect(&window, &MainWindow::newGame, &game, &GameCore::newGame);
    QObject::connect(&window, &MainWindow::stopGame, &game, &GameCore::stopGame);

    window.show();
    return a.exec();
}
