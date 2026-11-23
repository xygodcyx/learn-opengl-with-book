cmake_minimum_required(VERSION 3.16)

# support C need add xxx C flag
project(app C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # 生成 compile_commands.json

include(FetchContent)

FetchContent_Declare(
    glfw
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw
)

FetchContent_MakeAvailable(glfw)

add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# ---- 你的可执行文件 ----

set(LIB_FILES 
  # lib/lib.cpp
)

set(SOURCE_FILES 
  src/utils.cpp
  src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${LIB_FILES})
# 链接 外部库（会自动带上头文件路径和系统依赖）
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)


# ---- 编译器警告 ----
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

