/**********************************************************************************/
/* This file is part of spla project                                              */
/* https://github.com/SparseLinearAlgebra/spla                                    */
/**********************************************************************************/
/* MIT License                                                                    */
/*                                                                                */
/* Copyright (c) 2023 SparseLinearAlgebra                                         */
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

#ifndef SPLA_CL_PROGRAM_BUILDER_HPP
#define SPLA_CL_PROGRAM_BUILDER_HPP

#include <core/top.hpp>
#include <core/ttype.hpp>
#include <opencl/cl_accelerator.hpp>
#include <opencl/cl_program.hpp>
#include <opencl/cl_program_cache.hpp>

#include <svector.hpp>

#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace spla {

    /**
     * @addtogroup internal
     * @{
     */

    /**
     * @class CLProgramBuilder
     * @brief Runtime opencl program builder
     */
    class CLProgramBuilder final {
    public:
        CLProgramBuilder& set_name(const char* name);
        CLProgramBuilder& add_define(const char* define, int value);
        CLProgramBuilder& add_type(const char* alias, const ref_ptr<Type>& type);
        CLProgramBuilder& add_op(const char* name, const ref_ptr<OpUnary>& op);
        CLProgramBuilder& add_op(const char* name, const ref_ptr<OpBinary>& op);
        CLProgramBuilder& add_op(const char* name, const ref_ptr<OpSelect>& op);
        CLProgramBuilder& set_source(const char* source);
        void              acquire();

        const std::shared_ptr<CLProgram>& get_program() { return m_program; };
        cl::Kernel                        make_kernel(const char* name) { return m_program->make_kernel(name); }

    private:
        ankerl::svector<std::pair<std::string, std::string>, 8> m_defines;
        ankerl::svector<std::pair<std::string, ref_ptr<Op>>, 8> m_functions;
        std::string                                             m_name;
        const char*                                             m_source = nullptr;
        std::shared_ptr<CLProgram>                              m_program;
        std::string                                             m_program_code;
    };

    /**
     * @}
     */

}// namespace spla

#endif//SPLA_CL_PROGRAM_BUILDER_HPP
