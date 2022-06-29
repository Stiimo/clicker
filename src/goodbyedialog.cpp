#include "goodbyedialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GoodbyeDialog::GoodbyeDialog(QWidget* parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setModal(true);
    setFixedSize(200, 100);
    auto layout = new QVBoxLayout(this);
    layout->setSpacing(10);

    layout->addWidget(new QLabel("Приходите еще.", this));

    auto button = new QPushButton("Обязательно приду", this);
    QObject::connect(button, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(button, Qt::AlignRight);
}
