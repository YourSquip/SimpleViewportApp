#include "meshtools.h"

QVector<int> MeshTools::buildPolygonVertexIndicesVector(QVector<QVector<int> > polygonVertexIndices)
{
    QVector<int> polygonVertexIndicesVector;
    for (const QVector<int> &vertexIndicesInPolygon : polygonVertexIndices)
        for (int vertexInd : vertexIndicesInPolygon)
            polygonVertexIndicesVector.append(vertexInd);
    return polygonVertexIndicesVector;
}

QVector<int> MeshTools::buildPolygonStartVector(QVector<QVector<int> > polygonVertexIndices)
{
    int nPolygons = polygonVertexIndices.size();
    int startInd = 0;
    QVector<int> polygonStartVector;
    for (int polygonInd = 0; polygonInd < nPolygons; ++polygonInd) {
        polygonStartVector.append(startInd);
        int nVerticesInPolygon = polygonVertexIndices[polygonInd].size();
        startInd += nVerticesInPolygon;
    }
    polygonStartVector.append(startInd);
    return polygonStartVector;
}

QVector<int> MeshTools::buildTriangleVertexIndices(QVector<int> polygonIndices, QVector<int> polygonStart)
{
    Q_ASSERT(polygonStart.size() > 0);
    QVector<int> triangleIndices;
    int polygonCount = polygonStart.size() - 1;
    for (int polygonInd = 0; polygonInd < polygonCount; ++polygonInd) {
        int polygonStartInd = polygonStart[polygonInd];
        int originInd = polygonIndices[polygonStartInd];
        int vertexCount = polygonStart[polygonInd + 1] - polygonStart[polygonInd];
        for (int triangleInd = 0; triangleInd < vertexCount - 2; ++triangleInd) {
            int firstInd = polygonIndices[polygonStartInd + triangleInd + 1];
            int secondInd = polygonIndices[polygonStartInd + triangleInd + 2];
            triangleIndices << originInd << firstInd << secondInd;
        }
    }
    return triangleIndices;
}

QVector<float> MeshTools::packTriangleVertexCoords(QVector<QVector3D> vertices, QVector<int> triangleVertexIndices)
{
    Q_ASSERT(triangleVertexIndices.size() % 3 == 0);
    int nVertices = triangleVertexIndices.size();
    QVector<float> triangleVertexCoords;
    triangleVertexCoords.reserve(nVertices * 3);
    for (int vertexInd : triangleVertexIndices) {
        QVector3D triangleVertex = vertices[vertexInd];
        for (int coordInd = 0; coordInd < 3; ++coordInd)
            triangleVertexCoords.append(triangleVertex[coordInd]);
    }
    return triangleVertexCoords;
}
