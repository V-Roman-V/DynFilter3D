cmake_minimum_required(VERSION 3.16)
project(dynfilter3d LANGUAGES CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Dependencies ----
find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
find_package(nanobind CONFIG REQUIRED)

# --- Python module ---
nanobind_add_module(_dynfilter3d
    cpp/dynfilter3d/bindings.cpp
)

install(TARGETS _dynfilter3d
        LIBRARY DESTINATION ${SKBUILD_PLATLIB_DIR}/dynfilter3d)
