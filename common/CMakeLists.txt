cmake_minimum_required (VERSION 3.16)

set(COMMON_LIB_NAME common_lib)

add_library(${COMMON_LIB_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scope_guard.cpp
)

set(COMMON_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(${COMMON_LIB_NAME}
PUBLIC
    ${COMMON_INCLUDE_DIR}
)
