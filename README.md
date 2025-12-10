<h1 align="center">DynFilter3D</h1>

<p align="center">
  <strong>Dynamic object filtering for 3D LiDAR point clouds using spatiotemporal geometry</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/status-WIP-yellow.svg">
  <img src="https://img.shields.io/badge/python-3.9%20|%203.10%20|%203.11-blue.svg">
  <img src="https://img.shields.io/badge/c++-17-blue.svg">
  <img src="https://img.shields.io/badge/license-MIT-green.svg">
</p>


> **Status:** Work in progress. The API may change without notice.  
> **TODO:** Add a teaser image or short demo video illustrating the algorithm.

## Introduction

`dynfilter3d` is a clean, from-scratch Python/C++ toolkit for identifying and filtering dynamic points in LiDAR range data using spatiotemporal information such as surface normals and short-term motion cues.

The design of this project is inspired by the method described in:

> Falque, R., Le Gentil, C., & Sukkar, F.  
> **Dynamic Object Detection in Range Data using Spatiotemporal Normals**.  
> _Australasian Conference on Robotics and Automation (ACRA), 2023._  
> https://github.com/UTS-RI/dynamic_object_detection

### Motivation  

- Provide a simple, easy-to-use library/framework for dynamic filtering.  
- Separate logic from ROS dependency.  
- Add utilities for visualization, benchmarking, and dataset testing.  

## Features

- Lightweight C++17 core for fast geometric processing.
- Python bindings via `nanobind`.
- Dynamic point detection using spatiotemporal normals.
- High-level Python API for both offline and streaming use.
- Optional visualization utilities (via `open3d`).
- Examples on open datasets (e.g. KITTI).

---

## Quick Start (example usage)

```python
import numpy as np
import dynfilter3d as df

# Load a small sequence of LiDAR scans
scans = [
    np.load("scan_000.npy"),
    np.load("scan_001.npy"),
    np.load("scan_002.npy"),
]

# Create detector
f = df.DynamicFilter3D(window_size=3, min_neighbors=8)

# Estimate temporal surface statistics
f.fit_sequence(scans)

# Filter dynamic points in the last scan
mask = f.get_static_points(idx=-1)
static_points = scans[-1][mask]

print("Static points:", static_points.shape[0])
```

The API is still evolving, but this illustrates the intended workflow.

## Installation (from source)

```bash
git clone https://github.com/<your-username>/dynfilter3d.git
cd dynfilter3d

python -m venv .venv
source .venv/bin/activate

pip install -U pip
pip install -e .
```

This builds the native C++ extension and installs the Python package.

## Command Line Interface (planned)

```bash
dynfilter3d \
    --input "sequence/*.pcd" \
    --output "filtered/" \
    --config config/default.yaml
```

## Datasets

The package supports LiDAR point clouds in `.pcd`, `.bin`, `.npy`, and custom formats.
Example scripts will be provided for:

- KITTI odometry,
- open-source urban LiDAR datasets,
- synthetic demo point clouds.

---

## License

MIT License — a permissive, open-source license allowing commercial and academic use.

## Acknowledgement

This project is inspired by the original method:

```
@inproceedings{falque2023dynamic,
    title={Dynamic Object Detection in Range data using Spatiotemporal Normals}, 
    author={Raphael Falque and Cedric Le Gentil and Fouad Sukkar},
    booktitle={Australasian Conference on Robotics and Automation, ACRA},
    year={2023}
}
```
