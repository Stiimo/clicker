#pragma once

#include <QDialog>

class GoodbyeDialog : public QDialog {
    Q_OBJECT
public:
    explicit GoodbyeDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
};
