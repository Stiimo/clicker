#include "gamecore.h"

GameCore::GameCore(QObject* parent)
    : QObject(parent)
{
    m_timer.setInterval(10);
    connect(&m_timer, &QTimer::timeout, this, &GameCore::timeout);
}

void GameCore::clicked()
{
    ++m_currentClickCount;
}

void GameCore::timeout()
{
    m_progress += 10;
    emit progressChanged(m_progress);
    if (m_progress == 2000) {
        roundFinished();
    }
}

void GameCore::roundFinished()
{
    m_timer.stop();
    if (m_currentClickCount == m_expectedClickCount) {
        emit successCountChanged(++m_successCount);
    } else {
        emit failureCountChanged(++m_failureCount);
    }
    nextRound();
}

void GameCore::nextRound()
{
    m_progress = 0;
    emit progressChanged(0);
    m_currentClickCount = 0;
    m_expectedClickCount = dist(gen);
    emit expectedClickCountChanged(m_expectedClickCount);
    m_timer.start();
}

void GameCore::newGame()
{
    m_failureCount = 0;
    emit failureCountChanged(0);
    m_successCount = 0;
    emit successCountChanged(0);
    nextRound();
}

void GameCore::stopGame()
{
    m_timer.stop();
}
