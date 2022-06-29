#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

signals:
    void newGame();
    void stopGame();
    void clicked();
    void successCountChanged(int successCount);
    void failureCountChanged(int failureCount);
    void progressChanged(int value);
    void expectedClickCountChanged(int expectedClickCount);

protected:
    void closeEvent(QCloseEvent* event) override;
};
