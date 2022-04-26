#include "consoleprogressnotifier.h"
#include <QDebug>

ConsoleProgressNotifier::ConsoleProgressNotifier()
{
}

void ConsoleProgressNotifier::start(int minValue, int maxValue)
{
    Q_ASSERT(!isRunning());
    m_isRunning = true;
    m_minValue = minValue;
    m_maxValue = maxValue;
    qDebug() << "Progress started";
}

void ConsoleProgressNotifier::setProgress(int value)
{
    Q_ASSERT(value >= m_minValue);
    Q_ASSERT(value <= m_maxValue);
    Q_ASSERT(isRunning());
    float percent = (value - m_minValue) / float(m_maxValue - m_minValue) * 100;
    qDebug() << "Progress:" << percent << "%";
}

void ConsoleProgressNotifier::finish()
{
    Q_ASSERT(isRunning());
    qDebug() << "Finished";
    m_isRunning = false;
}

bool ConsoleProgressNotifier::isRunning() const
{
    return m_isRunning;
}
