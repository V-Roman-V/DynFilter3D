#include <nanobind/nanobind.h>
#include <nanobind/eigen/dense.h>

namespace nb = nanobind;

NB_MODULE(_dynfilter3d, m) {
    m.doc() = "DynFilter3D C++ extension (placeholder)";
    
    // minimal function for testing the build
    m.def("hello", []() {
        return "DynFilter3D extension loaded!";
    });
}
