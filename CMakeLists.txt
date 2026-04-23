cmake_minimum_required (VERSION 3.16)

project(particle-collider)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror -Wpedantic -Wall")

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

add_subdirectory(common)
add_subdirectory(dependencies)
add_subdirectory(graphics)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/include
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    common_lib
    graphics
)
