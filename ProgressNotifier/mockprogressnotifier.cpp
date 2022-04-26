#include "mockprogressnotifier.h"
#include <QtGlobal>

MockProgressNotifier::MockProgressNotifier()
{
}

void MockProgressNotifier::start(int minValue, int maxValue)
{
    Q_UNUSED(minValue)
    Q_UNUSED(maxValue)
}

void MockProgressNotifier::setProgress(int value)
{
    Q_UNUSED(value)
}

void MockProgressNotifier::finish()
{
}
