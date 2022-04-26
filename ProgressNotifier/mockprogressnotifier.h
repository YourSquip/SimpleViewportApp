#ifndef MOCKPROGRESSNOTIFIER_H
#define MOCKPROGRESSNOTIFIER_H

#include "progressnotifier.h"

class MockProgressNotifier : public AbstractProgressNotifier
{
public:
    MockProgressNotifier();
    void start(int minValue, int maxValue) override;
    void setProgress(int value) override;
    void finish() override;
};

#endif // MOCKPROGRESSNOTIFIER_H
