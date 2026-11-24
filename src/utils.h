#pragma once

#include <string>

#include "glad/glad.h"

bool read_shader_source(const char* path, std::string& out);

unsigned int complie_shader(const char* path, unsigned int type);

unsigned int create_program(unsigned int vert, unsigned int frag);

GLenum glCheckError_(const char* file, int line);

#define glCheckError() glCheckError_(__FILE__, __LINE__ - 1);
