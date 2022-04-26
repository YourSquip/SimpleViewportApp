!PROGRESS_NOTIFIER_PRI {

CONFIG += PROGRESS_NOTIFIER_PRI

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/consoleprogressnotifier.h \
    $$PWD/mockprogressnotifier.h \
    $$PWD/progressnotifier.h \
    $$PWD/visualprogressnotifier.h

SOURCES += \
    $$PWD/consoleprogressnotifier.cpp \
    $$PWD/mockprogressnotifier.cpp \
    $$PWD/progressnotifier.cpp \
    $$PWD/visualprogressnotifier.cpp

}
