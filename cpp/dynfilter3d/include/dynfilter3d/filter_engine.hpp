#pragma once

#include <cstddef>
#include <optional>

#include "dynfilter3d/types.hpp"
#include "dynfilter3d/params.hpp"
#include "dynfilter3d/result.hpp"

namespace dynfilter3d {

class DynamicFilter3D {
public:
    explicit DynamicFilter3D(Params params = Params{});
    ~DynamicFilter3D() = default;

    // --- lifecycle ---
    void reset();

    // --- ingestion ---
    // 3D: all points share the same timestamp (frame_ts)
    void push(Cloud3fRef xyz, Timestamp frame_ts);
    void push(Cloud3dRef xyz, Timestamp frame_ts);

    // 4D: per-point absolute timestamps in col=3
    void push(Cloud4fRef xyzt_absolute);
    void push(Cloud4dRef xyzt_absolute);

    // 4D: per-point relative timestamps (dt) in col=3 w.r.t. reference_ts
    // Absolute point time: t_abs = reference_ts + dt
    void push(Cloud4fRef xyzt_relative, Timestamp reference_ts);
    void push(Cloud4dRef xyzt_relative, Timestamp reference_ts);

    // --- inference ---
    // Predict for the k-th frame from the oldest in the current window.
    // Returns nullopt if k is out of range or prediction is not possible yet.
    std::optional<Result> predict(std::size_t k_from_oldest) const;

    inline std::optional<Result> predict_first() const { return predict(0); }
    inline std::optional<Result> predict_mid() const {
        const auto n = size();
        return (n == 0) ? std::nullopt : predict(n / 2);
    }
    inline std::optional<Result> predict_last() const {
        const auto n = size();
        return (n == 0) ? std::nullopt : predict(n - 1);
    }

    // --- params ---
    const Params& params() const { return params_; }

    // Small convenience setters
    void set_window_size(std::size_t window_size);
    void set_downsample_voxel_size(double vs);
    void set_neighbourhood_radius(double r);
    void set_min_points_for_covariance(int n);
    void set_dynamic_threshold(double thr);
    void set_upsample_radius(double r);
    void set_omp_threads(int n);

    // --- window info ---
    std::size_t size() const;
    std::size_t capacity() const { return params_.window_size; }

private:
    Params params_;
};

} // namespace dynfilter3d
