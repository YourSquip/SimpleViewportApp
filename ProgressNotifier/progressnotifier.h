#ifndef PROGRESSNOTIFIER_H
#define PROGRESSNOTIFIER_H

class AbstractProgressNotifier
{
public:
    AbstractProgressNotifier();
    virtual ~AbstractProgressNotifier();
    virtual void start(int minValue, int maxValue) = 0;
    virtual void setProgress(int value) = 0;
    virtual void finish() = 0;
protected:
};

#endif // PROGRESSNOTIFIER_H

