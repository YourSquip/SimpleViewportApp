#ifndef MESHTOOLS_H
#define MESHTOOLS_H

#include <QVector>
#include <QVector3D>

namespace MeshTools
{
    QVector<int> buildPolygonVertexIndicesVector(QVector<QVector<int> > polygonVertexIndices);
    QVector<int> buildPolygonStartVector(QVector<QVector<int> > polygonVertexIndices);
    QVector<int> buildTriangleVertexIndices(QVector<int> polygonIndices, QVector<int> polygonStart);
    QVector<float> packTriangleVertexCoords(QVector<QVector3D> vertices, QVector<int> triangleVertexIndices);
}

#endif // MESHTOOLS_H

