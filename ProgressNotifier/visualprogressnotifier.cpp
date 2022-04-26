#include "visualprogressnotifier.h"
#include <QApplication>

VisualProgressNotifier::VisualProgressNotifier(QProgressBar *progressBar) :
    AbstractProgressNotifier(),
    m_progressBar(progressBar)
{
}

void VisualProgressNotifier::start(int minValue, int maxValue)
{
    Q_ASSERT(!isRunning());
    m_isRunning = true;
    m_progressBar->setRange(minValue, maxValue);
    m_progressBar->setValue(minValue);
    m_progressBar->show();
}

void VisualProgressNotifier::setProgress(int value)
{
    Q_ASSERT(value >= m_progressBar->minimum());
    Q_ASSERT(value <= m_progressBar->maximum());
    Q_ASSERT(isRunning());
    m_progressBar->setValue(value);
    QApplication::processEvents();
}

void VisualProgressNotifier::finish()
{
    Q_ASSERT(isRunning());
    m_progressBar->hide();
    m_isRunning = false;
}

bool VisualProgressNotifier::isRunning() const
{
    return m_isRunning;
}
