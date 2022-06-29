#include "statpanel.h"
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>

StatPanel::StatPanel(QWidget* parent)
    : QWidget(parent)
{
    auto layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(new QLabel("Осталось времени", this), 0, 0, 1, 2, Qt::AlignHCenter);

    auto progress = new QProgressBar(this);
    progress->setTextVisible(false);
    progress->setMinimum(0);
    progress->setMaximum(2000);
    connect(this, &StatPanel::progressChanged, progress, [progress](int value) {
        progress->setValue(value);
    });
    layout->addWidget(progress, 1, 0, 1, 2);

    layout->addWidget(new QLabel("Успехи:", this), 2, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel("Провалы:", this), 2, 1, Qt::AlignHCenter);

    auto successLabel = new QLabel("0", this);
    connect(this, &StatPanel::successCountChanged, successLabel, [successLabel](int count) {
        successLabel->setText(QString::number(count));
    });
    layout->addWidget(successLabel, 3, 0, Qt::AlignHCenter);

    auto failureLabel = new QLabel("0", this);
    connect(this, &StatPanel::failureCountChanged, failureLabel, [failureLabel](int count) {
        failureLabel->setText(QString::number(count));
    });
    layout->addWidget(failureLabel, 3, 1, Qt::AlignHCenter);
}
