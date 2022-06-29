#include "mainwindow.h"
#include "controlpanel.h"
#include "gamefield.h"
#include "goodbyedialog.h"
#include "statpanel.h"
#include <QCloseEvent>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Clicker");
    setMinimumSize(300, 500);

    auto widget = new QWidget(this);
    setCentralWidget(widget);
    auto layout = new QVBoxLayout(widget);
    layout->setSpacing(10);
    auto gameField = new GameField(this);
    layout->addWidget(gameField);
    auto statPanel = new StatPanel(this);
    layout->addWidget(statPanel);
    auto controlPanel = new ControlPanel(this);
    layout->addWidget(controlPanel);

    QObject::connect(gameField, &GameField::clicked, this, &MainWindow::clicked);
    QObject::connect(this, &MainWindow::expectedClickCountChanged, gameField, &GameField::expectedClickCountChanged);
    QObject::connect(this, &MainWindow::successCountChanged, statPanel, &StatPanel::successCountChanged);
    QObject::connect(this, &MainWindow::failureCountChanged, statPanel, &StatPanel::failureCountChanged);
    QObject::connect(this, &MainWindow::progressChanged, statPanel, &StatPanel::progressChanged);
    QObject::connect(controlPanel, &ControlPanel::newGame, this, &MainWindow::newGame);
    QObject::connect(controlPanel, &ControlPanel::stopGame, this, &MainWindow::stopGame);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    GoodbyeDialog dialog;
    dialog.exec();
    event->accept();
}
