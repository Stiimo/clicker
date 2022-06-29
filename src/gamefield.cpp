#include "gamefield.h"
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QVBoxLayout>

GameField::GameField(QWidget* parent)
    : QFrame(parent)
{
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(palette);
    setFrameShape(QFrame::Box);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    auto layout = new QVBoxLayout(this);
    auto label = new QLabel("0", this);
    auto font = label->font();
    font.setPixelSize(36);
    label->setFont(font);
    connect(this, &GameField::expectedClickCountChanged, this, [label](int count) {
        label->setText(QString::number(count));
    });
    layout->addWidget(label);
    label->setAlignment(Qt::AlignCenter);
}

void GameField::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}
