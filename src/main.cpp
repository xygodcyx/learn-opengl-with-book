#include "main.h"

#include <iostream>

// clang-format off
#include "glad/glad.h"
#include "GLFW/glfw3.h"
// clang-format on

void glfw_error_Callback(int code, const char* error) {
  std::cout << "[GLFW Error]: " << error << " \n[GLFW ERROR Code]: " << code
            << std::endl;
}

void framebuffer_size_callback(GLFWwindow* _, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
int main() {
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHintString(GLFW_WAYLAND_APP_ID, "opengl-window");

  glfwSetErrorCallback(glfw_error_Callback);

  GLFWwindow* window = glfwCreateWindow(455, 457, "Hello OpenGl", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to Create GLFW Window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // clang-format off
  float vertices[] = {
    -0.5,-0.5,0.0,
    0.5,-0.5,0.0,
    0.0,0.5,0.0
  };
  // clang-format on
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    processInput(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
