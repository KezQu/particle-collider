cmake_minimum_required (VERSION 3.16)

project(particle-collider)

set (CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)
find_package(MPI REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mpi_guard.cpp
    src/base_process.cpp
    src/mediator_process.cpp
    src/worker_process.cpp

    src/cuda_compute_block.cpp
    src/opencl_compute_block.cpp
    src/compute_block_factory.cpp
    src/particle.cpp
    src/vec_2d.cpp

    src/simulation/simulation.cpp
    src/simulation/simulation_controls.cpp
    src/simulation/backend_selector.cpp
    src/simulation/block_num_selector.cpp
    src/simulation/particles_selector.cpp
)

add_subdirectory(dependencies)
add_subdirectory(graphics)
add_subdirectory(common)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/simulation
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    common_lib
    graphics
    MPI::MPI_CXX
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
