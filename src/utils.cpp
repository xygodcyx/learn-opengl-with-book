#include "utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "glad/glad.h"

int success;
char infoLog[512];

bool read_shader_source(const char* path, std::string& out) {
  std::ifstream file(path);

  if (!file.is_open()) {
    return "error";
  }

  std::ostringstream buffer;
  buffer << file.rdbuf();
  out = buffer.str();

  return true;
}

unsigned int complie_shader(const char* path, unsigned int type) {
  std::string content;
  if (!read_shader_source(path, content)) {
  }

  const char* source_code = content.c_str();

  unsigned int shader;
  shader = glCreateShader(type);
  glShaderSource(shader, 1, &source_code, NULL);
  glCompileShader(shader);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  return shader;
}

unsigned int create_program(unsigned int vert, unsigned int frag) {
  unsigned int program;
  program = glCreateProgram();
  glAttachShader(program, vert);
  glAttachShader(program, frag);
  glLinkProgram(program);

  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(program, 512, NULL, infoLog);
    std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
  }
  return program;
}
