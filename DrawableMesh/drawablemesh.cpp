#include "drawablemesh.h"
#include "meshtools.h"
#include "drawableobjecttools.h"

DrawableMesh::DrawableMesh(QVector<float> color, QVector<QVector3D> vertices, QVector<int> polygonVertexIndices, QVector<int> polygonStart, QVector<QVector3D> normals, QVector<int> polygonNormalIndices)
{
    QVector<int> triangleVertexIndices = MeshTools::buildTriangleVertexIndices(polygonVertexIndices, polygonStart);
    QVector<float> triangleVertexCoords = MeshTools::packTriangleVertexCoords(vertices, triangleVertexIndices);
    m_nVertices = triangleVertexCoords.size() / 3;
    int dataSize = triangleVertexCoords.size() * static_cast<int>(sizeof(float));

    m_vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    if (!m_vertexBuffer->create())
        qFatal("Failed to create vertex buffer");
    if (!m_vertexBuffer->bind())
        qFatal("Failed to bind vertex buffer");
    m_vertexBuffer->allocate(triangleVertexCoords.constData(), dataSize);
    m_vertexBuffer->release();

    QVector<int> triangleNormalIndices = MeshTools::buildTriangleVertexIndices(polygonNormalIndices, polygonStart);
    QVector<float> triangleNormalCoords = MeshTools::packTriangleVertexCoords(normals, triangleNormalIndices);

    m_normalBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    if (!m_normalBuffer->create())
        qFatal("Failed to create normal buffer");
    if (!m_normalBuffer->bind())
        qFatal("Failed to bind normal buffer");
    m_normalBuffer->allocate(triangleNormalCoords.constData(), dataSize);
    m_normalBuffer->release();

    m_colorBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    if (!m_colorBuffer->create())
        qFatal("Failed to create color buffer");
    if (!m_colorBuffer->bind())
        qFatal("Failed to bind color buffer");
    m_colorBuffer->allocate(color.constData(), dataSize);
    m_colorBuffer->release();

    QString vertexShaderFileName = ":/DrawableMesh/VertexShader.vert";
    QString fragmentShaderFileName = ":/DrawableMesh/FragmentShader.frag";
    m_shader = DrawableObjectTools::createShaderProgram(vertexShaderFileName, fragmentShaderFileName);
    Q_ASSERT(m_shader != nullptr);
}

DrawableMesh::~DrawableMesh()
{
    delete m_vertexBuffer;
    delete m_normalBuffer;
    delete m_colorBuffer;//!
    delete m_shader;
}

void DrawableMesh::draw(QMatrix4x4 viewMatrix, QMatrix4x4 projectionMatrix)
{
    QMatrix4x4 normalMatrix = viewMatrix.inverted().transposed();

    bool isBound = m_shader->bind();
    Q_ASSERT(isBound);
    m_shader->setUniformValue("modelViewMatrix", viewMatrix);
    m_shader->setUniformValue("normalMatrix", normalMatrix);
    m_shader->setUniformValue("projectionMatrix", projectionMatrix);

    isBound = m_vertexBuffer->bind();
    Q_ASSERT(isBound);
    m_shader->setAttributeBuffer("vertex", GL_FLOAT, 0, 3, 0);
    m_shader->enableAttributeArray("vertex");
    m_vertexBuffer->release();

    isBound = m_normalBuffer->bind();
    Q_ASSERT(isBound);
    m_shader->setAttributeBuffer("normal", GL_FLOAT, 0, 3, 0);
    m_shader->enableAttributeArray("normal");
    m_normalBuffer->release();

    isBound = m_colorBuffer->bind();
    Q_ASSERT(isBound);
    m_shader->setAttributeBuffer("color", GL_FLOAT, 0, 3, 0);
    m_shader->enableAttributeArray("color");
    m_colorBuffer->release();

    glEnable(GL_DEPTH_TEST);
    glDrawArrays(GL_TRIANGLES, 0, m_nVertices);

    m_shader->disableAttributeArray("vertex");
    m_shader->disableAttributeArray("normal");
    m_shader->disableAttributeArray("color");

    m_shader->release();
}
