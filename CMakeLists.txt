cmake_minimum_required(VERSION 3.20)

set(project_target ghw-sorting-challenge)

project(
    ${project_target}
    VERSION 1.0
    LANGUAGES C CXX
)

file(GLOB src_files ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(
    ${project_target}
    ${src_files}
)

target_include_directories(${project_target} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)