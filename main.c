#define GLFW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: Could not start GLFW3\n");
        return 1;
    }

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte *version = glGetString(GL_VERSION);   // version as a string
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);

    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS);    // depth-testing interprets a smaller value as "closer"

    float points[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    GLuint vbo = 0; // Create a vertex buffer object (VBO) to store vertex data
    glGenBuffers(1, &vbo); // Generate a unique buffer ID for the VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // Bind the VBO to the GL_ARRAY_BUFFER target
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW); // Copy the vertex data to the VBO

    GLuint vao = 0; // Create a vertex array object (VAO) to store vertex attribute configurations
    glGenVertexArrays(1, &vao); // Generate a unique buffer ID for the VAO
    glBindVertexArray(vao); // Bind the VAO
    glEnableVertexAttribArray(0); // Enable the vertex attribute at index 0
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // Bind the VBO to the GL_ARRAY_BUFFER target
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Specify the layout of the vertex data in the VBO
    // close GL context and any other GLFW resources
    glfwTerminate();
}
