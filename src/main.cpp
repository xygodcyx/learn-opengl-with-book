#include "main.h"

// clang-format off
#include "glad/glad.h"
#include "GLFW/glfw3.h"
// clang-format on

int main() {
  GLFWwindow* window;
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHintString(GLFW_WAYLAND_APP_ID, "opengl-window");

  glfwInit();
  window = glfwCreateWindow(455, 457, "Hello OpenGl", NULL, NULL);

  glfwMakeContextCurrent(window);
  return 0;
}
