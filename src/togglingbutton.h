#pragma once

#include <QPushButton>

class TogglingButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TogglingButton(const QString& text, QWidget* parent = nullptr);

public slots:
    void toggleEnabled();
};
