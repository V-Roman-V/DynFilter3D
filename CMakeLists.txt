cmake_minimum_required(VERSION 3.16)
project(dynfilter3d LANGUAGES CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Dependencies ----
find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
find_package(nanobind CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

# ---- C++ extension ----
add_subdirectory(cpp/dynfilter3d)
