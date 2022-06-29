#pragma once

#include <QObject>
#include <QTimer>
#include <random>

class GameCore : public QObject {
    Q_OBJECT
public:
    explicit GameCore(QObject* parent = nullptr);

public slots:
    void clicked();
    void timeout();
    void nextRound();
    void newGame();
    void stopGame();

signals:
    void successCountChanged(int successCount);
    void failureCountChanged(int failureCount);
    void progressChanged(int progress);
    void expectedClickCountChanged(int expectedClickCount);

private:
    void roundFinished();

    QTimer m_timer;
    int m_progress { 0 };
    int m_successCount { 0 };
    int m_failureCount { 0 };
    int m_expectedClickCount { 0 };
    int m_currentClickCount { 0 };
    std::random_device rd;
    std::mt19937 gen { rd() };
    std::uniform_int_distribution<> dist { 1, 9 };
};
