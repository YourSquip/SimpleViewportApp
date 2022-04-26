#ifndef CONSOLEPROGRESSNOTIFIER_H
#define CONSOLEPROGRESSNOTIFIER_H

#include "progressnotifier.h"

class ConsoleProgressNotifier : public AbstractProgressNotifier
{
public:
    ConsoleProgressNotifier();
    void start(int minValue, int maxValue) override;
    void setProgress(int value) override;
    void finish() override;
protected:
    bool isRunning() const;
protected:
    bool m_isRunning = false;
    int m_minValue = -1;
    int m_maxValue = -1;
};

#endif // CONSOLEPROGRESSNOTIFIER_H
