#include <QCoreApplication>
#include "objreader.h"
#include "objreadertests.h"
#include "meshtooltests.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ObjReaderTests readerTests;
    QTest::qExec(&readerTests);
    MeshToolTests meshToolTests;
    QTest::qExec(&meshToolTests);

    QString fileName = "D:/OBJ/Teapot.obj";
    ObjReadingTools::ObjData objData;
    QString errorMsg;

    if (!ObjReadingTools::read(fileName, objData, errorMsg)) {
        qDebug() << errorMsg;
        return -1;
    }
    QFile fileOut("D:/OBJ/Teapot_copy2.obj");//file directory
    ObjReadingTools::save(objData, fileOut,errorMsg);
    qDebug() << "Done";
    return 0;
}
