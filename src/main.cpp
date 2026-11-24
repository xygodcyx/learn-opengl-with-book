#include "main.h"

#include <iostream>

#include "utils.h"

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

  // compile shader
  unsigned vertex_shader =
      complie_shader("shader/simple.vert", GL_VERTEX_SHADER);

  unsigned fragment_shader =
      complie_shader("shader/simple.frag", GL_FRAGMENT_SHADER);

  unsigned int program = create_program(vertex_shader, fragment_shader);

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  // clang-format off
  // 给VBO用的顶点数据
  float vertices[] = {
    -0.25,0.5,0.0,
    -0.5,0,0.0,
    0.0,0.0,0.0,
  };
  float vertices2[] = {
    0.0,0.0,0.0,
    0.25,0.5,0.0,
    0.5,0.0,0.0
  };
  
  //EBO
  unsigned int indices[] = {
    0,1,3,
    1,2,3
  };

  // clang-format on

  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  unsigned int VAO1;
  glGenVertexArrays(1, &VAO1);
  glBindVertexArray(VAO1);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),

                        (void*)0);
  glEnableVertexAttribArray(0);

  unsigned int VBO2;
  glGenBuffers(1, &VBO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

  unsigned int VAO2;
  glGenVertexArrays(1, &VAO2);
  glBindVertexArray(VAO2);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),

                        (void*)0);
  glEnableVertexAttribArray(0);

  unsigned int EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);

    glBindVertexArray(VAO1);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(VAO2);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
