"""
dynfilter3d - Python interface for dynamic point filtering.
"""

from ._version import __version__

# Expose C++ bindings when available
try:
    from ._dynfilter3d import *  # noqa: F401,F403
except Exception:
    # Allow imports even before building the extension
    pass
    