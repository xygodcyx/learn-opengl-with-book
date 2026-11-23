#pragma once

#include <string>
bool read_shader_source(const char* path, std::string& out);

unsigned int complie_shader(const char* path, unsigned int type);

unsigned int create_program(unsigned int vert, unsigned int frag);
