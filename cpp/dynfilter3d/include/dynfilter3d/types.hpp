#pragma once

#include <cstddef>
#include <cstdint>

#include <Eigen/Core>

namespace dynfilter3d {

using Timestamp = double;

template <typename Scalar, int Cols>
using MatXR = Eigen::Matrix<Scalar, Eigen::Dynamic, Cols, Eigen::RowMajor>;

using MatX3f = MatXR<float, 3>;
using MatX3d = MatXR<double, 3>;
using MatX4f = MatXR<float, 4>;
using MatX4d = MatXR<double, 4>;

using Cloud3fRef = Eigen::Ref<const MatX3f>;
using Cloud3dRef = Eigen::Ref<const MatX3d>;
using Cloud4fRef = Eigen::Ref<const MatX4f>;
using Cloud4dRef = Eigen::Ref<const MatX4d>;

} // namespace dynfilter3d
