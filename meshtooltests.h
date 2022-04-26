#ifndef MESHTOOLTESTS_H
#define MESHTOOLTESTS_H

#include <QObject>
#include <QTest>

class MeshToolTests : public QObject
{
    Q_OBJECT
public:
    explicit MeshToolTests(QObject *parent = nullptr);
private slots:
    void testBuildPolygonVertexIndicesVector01();
    void testBuildPolygonVertexIndicesVector02();
    void testBuildPolygonStartVector01();
    void testBuildPolygonStartVector02();
    void testBuildTriangleVertexIndices01();
    void testBuildTriangleVertexIndices02();
    void testPackTriangleVertexCoords01();
};

#endif // MESHTOOLTESTS_H
