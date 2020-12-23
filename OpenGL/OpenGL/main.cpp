#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main()
{
  // BEGIN - Initialize GLFW 
  glfwInit();
  // Specify OpenGL version 3.3 (Major = 3.0, Minor = 0.3)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Add next line if using MAC OS X
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  // END - Initialize GLFW
  
  // BEGIN - Create window object
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  // END - Create window object

  // BEGIN - Initialize GLAD for OpenGL operations
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  // END - Initialize GLAD for OpenGL operations

  // Inform dimensions to OpenGL
  glViewport(0, 0, 800, 600);

  // for resizing
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // BEGIN - Keep running the window
  while (!glfwWindowShouldClose(window))
  {
    // Check if ESC is pressed
    processInput(window);

    // BEGIN - Render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // END - Render

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  // END - Keep running the window

  // BEGIN - Clean up
  glfwTerminate();
  // END - Clean up

  return 0;
}