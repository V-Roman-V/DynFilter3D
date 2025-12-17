#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include "dynfilter3d/types.hpp"

namespace dynfilter3d {

struct Result {
    // Which frame was predicted
    Timestamp frame_timestamp = 0.0;
    std::size_t k_from_oldest = 0;

    // Per-point outputs for the *full-res* cloud at that k
    // 0 => static, 1 => dynamic
    std::vector<std::uint8_t> is_dynamic;
};

} // namespace dynfilter3d
