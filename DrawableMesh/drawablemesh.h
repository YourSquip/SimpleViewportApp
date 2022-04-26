#ifndef DRAWABLEMESH_H
#define DRAWABLEMESH_H

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include "drawableobject.h"

class DrawableMesh : public DrawableObject
{
public:
    DrawableMesh(QVector<float> color, QVector<QVector3D> vertices, QVector<int> polygonVertexIndices, QVector<int> polygonStart, QVector<QVector3D> normals, QVector<int> polygonNormalIndices);
    ~DrawableMesh() override;
    void draw(QMatrix4x4 viewMatrix, QMatrix4x4 projectionMatrix) override;


protected:
    QOpenGLBuffer *m_vertexBuffer = nullptr;
    QOpenGLBuffer *m_normalBuffer = nullptr;
    QOpenGLBuffer *m_colorBuffer = nullptr;//!
    int m_nVertices = -1;
    QOpenGLShaderProgram *m_shader = nullptr;
};

#endif // DRAWABLEMESH_H

