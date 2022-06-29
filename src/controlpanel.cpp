#include "controlpanel.h"
#include "togglingbutton.h"
#include <QHBoxLayout>

ControlPanel::ControlPanel(QWidget* parent)
    : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(10);

    auto startButton = new TogglingButton("Старт", this);
    layout->addWidget(startButton);

    auto stopButton = new TogglingButton("Стоп", this);
    stopButton->setEnabled(false);
    layout->addWidget(stopButton);

    QObject::connect(startButton, &TogglingButton::clicked, stopButton, &TogglingButton::toggleEnabled);
    QObject::connect(startButton, &TogglingButton::clicked, this, &ControlPanel::newGame);
    QObject::connect(stopButton, &TogglingButton::clicked, startButton, &TogglingButton::toggleEnabled);
    QObject::connect(stopButton, &TogglingButton::clicked, this, &ControlPanel::stopGame);
}
