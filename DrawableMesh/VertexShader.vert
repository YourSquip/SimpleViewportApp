uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix;
attribute vec3 vertex;
attribute vec3 normal;
attribute vec3 color;

varying vec3 m_vertex;
varying vec3 m_normal;
varying vec3 m_color;

void main(void)
{
    m_vertex = (modelViewMatrix * vec4(vertex, 1.0)).xyz;
    m_normal = (normalMatrix * vec4(normal, 1.0)).xyz;
    m_color = color;
    gl_Position = projectionMatrix * vec4(m_vertex, 1.0);
}
