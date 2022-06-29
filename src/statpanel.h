#pragma once

#include <QWidget>

class StatPanel : public QWidget
{
    Q_OBJECT
public:
    explicit StatPanel(QWidget* parent = nullptr);

signals:
    void successCountChanged(int successCount);
    void failureCountChanged(int failureCount);
    void progressChanged(int value);
};
