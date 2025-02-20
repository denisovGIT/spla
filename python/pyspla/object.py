"""
Wrapped native (spla C API) object primitive implementation.
"""

__copyright__ = "Copyright (c) 2021-2022 SparseLinearAlgebra"

__license__ = """
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

import ctypes


class Object:
    """
    Base class for any spla library object.

    Attributes
    ----------

    - label : `str` user provided text label for object for debugging
    - hnd : `ctypes.p_void` hnd to native object in spla C API

    Details
    -------

    Object class support all spla C API matrix functions.
    It provides bind functionality as well as new functions/methods for better python user experience.

    Object class used for runtime-introspection of spla primitives, as well as for safe ref-count
    of native spla C/C++ instances, created inside imported native shared spla (.dll/.so/.dylib) library.
    """

    def __init__(self):
        pass
