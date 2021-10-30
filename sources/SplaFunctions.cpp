/**********************************************************************************/
/* This file is part of spla project                                              */
/* https://github.com/JetBrains-Research/spla                                     */
/**********************************************************************************/
/* MIT License                                                                    */
/*                                                                                */
/* Copyright (c) 2021 JetBrains-Research                                          */
/*                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/**********************************************************************************/

#include <spla-cpp/SplaFunctions.hpp>
#include <spla-cpp/SplaTypes.hpp>

spla::RefPtr<spla::FunctionBinary> spla::Functions::PlusInt32(spla::Library &library) {
    auto t = Types::Int32(library);
    return FunctionBinary::Make(t, t, t,
                                "int a = *((const __global int*)vp_a);"
                                "int b = *((const __global int*)vp_b);"
                                "__global int* c = (__global int*)vp_c;"
                                "*c = a + b;",
                                library);
}

spla::RefPtr<spla::FunctionBinary> spla::Functions::PlusInt64(spla::Library &library) {
    auto t = Types::Int64(library);
    return FunctionBinary::Make(t, t, t,
                                "long a = *((const __global long*)vp_a);"
                                "long b = *((const __global long*)vp_b);"
                                "__global long* c = (__global long*)vp_c;"
                                "*c = a + b;",
                                library);
}

spla::RefPtr<spla::FunctionBinary> spla::Functions::PlusFloat32(Library &library) {
    auto t = Types::Float32(library);
    return FunctionBinary::Make(t, t, t,
                                "float a = *((const __global float*)vp_a);"
                                "float b = *((const __global float*)vp_b);"
                                "__global float* c = (__global float*)vp_c;"
                                "*c = a + b;",
                                library);
}

spla::RefPtr<spla::FunctionBinary> spla::Functions::PlusFloat64(spla::Library &library) {
    auto t = Types::Float64(library);
    return FunctionBinary::Make(t, t, t,
                                "double a = *((const __global double*)vp_a);"
                                "double b = *((const __global double*)vp_b);"
                                "__global double* c = (double*)vp_c;"
                                "*c = a + b;",
                                library);
}
