#include "progressnotifiersingleton.h"

ProgressNotifierSingleton *ProgressNotifierSingleton::m_instance = nullptr;

ProgressNotifierSingleton *ProgressNotifierSingleton::instance()
{
    if (m_instance == nullptr)
        m_instance = new ProgressNotifierSingleton();
    return m_instance;
}

void ProgressNotifierSingleton::init(QProgressBar *progressBar)
{
    m_instance = instance();
    m_instance->setProgressBar(progressBar);
}

void ProgressNotifierSingleton::start(int min, int max)
{
    Q_ASSERT(isInitialized());
    Q_ASSERT(!isRunning());
    m_isRunning = true;
    m_progressBar->setRange(min, max);
    m_progressBar->setValue(min);
    m_progressBar->show();
}

void ProgressNotifierSingleton::setProgress(int value)
{
    Q_ASSERT(isInitialized());
    Q_ASSERT(value >= m_progressBar->minimum());
    Q_ASSERT(value <= m_progressBar->maximum());
    Q_ASSERT(isRunning());
    m_progressBar->setValue(value);
}

void ProgressNotifierSingleton::finish()
{
    Q_ASSERT(isInitialized());
    Q_ASSERT(isRunning());
    m_isRunning = false;
    m_progressBar->hide();
}

ProgressNotifierSingleton::ProgressNotifierSingleton()
{
}

void ProgressNotifierSingleton::setProgressBar(QProgressBar *progressBar)
{
    m_progressBar = progressBar;
}

bool ProgressNotifierSingleton::isInitialized() const
{
    return m_progressBar != nullptr;
}

bool ProgressNotifierSingleton::isRunning() const
{
    return m_isRunning;
}
