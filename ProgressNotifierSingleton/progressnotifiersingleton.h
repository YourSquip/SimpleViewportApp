#ifndef PROGRESSNOTIFIERSINGLETON_H
#define PROGRESSNOTIFIERSINGLETON_H

#include <QProgressBar>

class ProgressNotifierSingleton
{
public:
    static ProgressNotifierSingleton *instance();
    static void init(QProgressBar *progressBar);
    void start(int min, int max);
    void setProgress(int value);
    void finish();
protected:
    ProgressNotifierSingleton();
    void setProgressBar(QProgressBar *progressBar);
    bool isInitialized() const;
    bool isRunning() const;
protected:
    static ProgressNotifierSingleton *m_instance;
    QProgressBar *m_progressBar = nullptr;
    bool m_isRunning = false;
};

#endif // PROGRESSNOTIFIERSINGLETON_H
