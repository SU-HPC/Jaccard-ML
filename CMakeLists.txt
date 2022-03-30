cmake_minimum_required(VERSION 3.12)

project(Jaccard-ML VERSION 0.1 LANGUAGES CUDA CXX)

enable_language(CUDA)
find_package(CUDA REQUIRED)

option(_CPU "Use CPU kernels" ON)
option(_GPU "Use GPU kernels" OFF)
option(SIMPLE_GPU "Simple GPU kernel" OFF)
option(SIMPLE_GPU_EDGE "Edge-based GPU kernel" OFF)
option(_CUGRAPH "use cuGraph" OFF)
option(_INHOUSE_CUGRAPH "use inhouse cuGraph" OFF)
option(_DONGARRA "use dongarra" OFF)
option(DIRECTED "Treat graphs as directed" OFF)
option(BINNING "Run binning experiment" OFF)

if (NOT ${_GPU})
set(SIMPLE_GPU OFF)
set(SIMPLE_GPU_EDGE OFF)
set(_CUGRAPH OFF)
set(_INHOUSE_CUGRAPH OFF)
set(_DONGARRA OFF)
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/src/config.h.in"
    "${PROJECT_BINARY_DIR}/src/config.h"
)

add_subdirectory(src)