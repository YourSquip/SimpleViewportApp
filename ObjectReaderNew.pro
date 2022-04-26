QT += gui testlib widgets

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    meshtooltests.cpp \
    objreadertests.cpp


include(ObjReader/ObjReader.pri)
include(MeshTools/MeshTools.pri)
include(DrawableMesh/DrawableMesh.pri)
include(DrawableGrid/DrawableGrid.pri)
include(Viewport/Viewport.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    meshtooltests.h \
    objreadertests.h

