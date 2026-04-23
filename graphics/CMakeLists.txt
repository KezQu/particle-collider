cmake_minimum_required (VERSION 3.16)

find_package(OpenGL REQUIRED)

set(GRAPHICS_LIB_NAME graphics)

add_library(${GRAPHICS_LIB_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/context.cpp
)

set(GRAPHICS_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(${GRAPHICS_LIB_NAME}
PUBLIC
    ${GRAPHICS_INCLUDE_DIR}
)

target_link_libraries(${GRAPHICS_LIB_NAME}
PUBLIC
    common_lib
    glfw
    OpenGL::GL
)
