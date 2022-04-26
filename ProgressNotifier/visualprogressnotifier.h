#ifndef VISUALPROGRESSNOTIFIER_H
#define VISUALPROGRESSNOTIFIER_H

#include "progressnotifier.h"
#include <QProgressBar>

class VisualProgressNotifier : public AbstractProgressNotifier
{
public:
    VisualProgressNotifier(QProgressBar *progressBar);
    void start(int minValue, int maxValue) override;
    void setProgress(int value) override;
    void finish() override;
protected:
    bool isRunning() const;
protected:
    QProgressBar *m_progressBar;
    bool m_isRunning = false;
};

#endif // VISUALPROGRESSNOTIFIER_H
