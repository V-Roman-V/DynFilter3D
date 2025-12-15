# ---- Core (header-only for now) ----
add_library(dynfilter3d_core INTERFACE)
target_include_directories(dynfilter3d_core INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# ---- Python module ----
nanobind_add_module(_dynfilter3d
  bindings.cpp
)

target_link_libraries(_dynfilter3d PRIVATE dynfilter3d_core)

# ---- Install ----
install(TARGETS _dynfilter3d
  LIBRARY DESTINATION ${SKBUILD_PLATLIB_DIR}/dynfilter3d
)

install(DIRECTORY include/
  DESTINATION include
)
