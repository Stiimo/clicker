#include "togglingbutton.h"

TogglingButton::TogglingButton(const QString& text, QWidget* parent)
    : QPushButton(text, parent)
{
    QObject::connect(this, &TogglingButton::clicked, this, &TogglingButton::toggleEnabled);
}

void TogglingButton::toggleEnabled()
{
    setEnabled(!isEnabled());
}
