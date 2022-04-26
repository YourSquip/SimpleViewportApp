!OBJ_READER_PRI {

CONFIG += OBJ_READER_PRI

INCLUDEPATH += $$PWD

include($$PWD/../ProgressNotifier/ProgressNotifier.pri)

HEADERS += \
    $$PWD/objreader.h

SOURCES += \
    $$PWD/objreader.cpp

}
