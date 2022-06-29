#pragma once

#include <QWidget>

class ControlPanel : public QWidget {
    Q_OBJECT
public:
    explicit ControlPanel(QWidget* parent = nullptr);

signals:
    void newGame();
    void stopGame();
};
