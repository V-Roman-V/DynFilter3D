#pragma once

#include <cstddef>
#include <cstdint>

namespace dynfilter3d {

struct Params {
    // -------- Spatiotemporal map --------
    std::size_t window_size = 5;           // [frames] number of frames to buffer
    double map_voxel_size = 0.65;          // [m] cell size of local spatiotemporal map

    // -------- Downsampling (per-scan prefilter) --------
    double downsample_voxel_size = 0.2;    // [m] voxel for initial scan downsample

    // -------- Detection on local spatio-temporal map --------
    double neighbourhood_radius = 0.4;     // [m] radius for neighborhood accumulation for covariance/score
    int min_points_for_covariance = 11;    // [-] minimum aggregated points to compute covariance
    double dynamic_threshold = 0.05;       // [-] mark point dynamic if score > threshold (typ. 0.03–0.08)

    // -------- Upsampling back to full resolution --------
    double upsample_radius = 0.3;         // [m] radius in full-res cloud for label propagation

    // -------- Performance / misc --------
    int omp_threads = 0;                  // [-] 0 => runtime default
};

} // namespace dynfilter3d
