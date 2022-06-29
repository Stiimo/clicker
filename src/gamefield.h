#pragma once

#include <QFrame>

class GameField : public QFrame {
    Q_OBJECT
public:
    explicit GameField(QWidget* parent = nullptr);

signals:
    void expectedClickCountChanged(int count);
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
};
