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

#ifndef SPLA_REGISTRY_HPP
#define SPLA_REGISTRY_HPP

#include <spla/config.hpp>
#include <spla/schedule.hpp>

#include <robin_hood.hpp>

#include <string>

namespace spla {

#define CPU_SUFFIX                          "__cpu"
#define GPU_CL_SUFFIX                       "__cl"
#define OP_KEY(op)                          "_" + (op)->get_key()
#define TYPE_KEY(type)                      "_" + (type)->get_code()
#define MAKE_KEY_0(name, type)              std::string(name) + TYPE_KEY(type)
#define MAKE_KEY_1(name, op)                std::string(name) + OP_KEY(op)
#define MAKE_KEY_2(name, op1, op2)          std::string(name) + OP_KEY(op1) + OP_KEY(op2)
#define MAKE_KEY_3(name, op1, op2, op3)     std::string(name) + OP_KEY(op1) + OP_KEY(op2) + OP_KEY(op3)
#define MAKE_KEY_CPU_0(name, type)          MAKE_KEY_0(name, type) + CPU_SUFFIX
#define MAKE_KEY_CPU_1(name, op)            MAKE_KEY_1(name, op) + CPU_SUFFIX
#define MAKE_KEY_CPU_2(name, op1, op2)      MAKE_KEY_2(name, op1, op2) + CPU_SUFFIX
#define MAKE_KEY_CPU_3(name, op1, op2, op3) MAKE_KEY_3(name, op1, op2, op3) + CPU_SUFFIX
#define MAKE_KEY_CL_0(name, type)           MAKE_KEY_0(name, type) + GPU_CL_SUFFIX
#define MAKE_KEY_CL_1(name, op)             MAKE_KEY_1(name, op) + GPU_CL_SUFFIX
#define MAKE_KEY_CL_2(name, op1, op2)       MAKE_KEY_2(name, op1, op2) + GPU_CL_SUFFIX
#define MAKE_KEY_CL_3(name, op1, op2, op3)  MAKE_KEY_3(name, op1, op2, op3) + GPU_CL_SUFFIX

    /**
     * @addtogroup internal
     * @{
     */

    /**
     * @class RegistryAlgo
     * @brief Algorithm suitable to process schedule task based on task string key
     */
    class RegistryAlgo {
    public:
        virtual ~RegistryAlgo()                                        = default;
        virtual std::string get_name()                                 = 0;
        virtual std::string get_description()                          = 0;
        virtual Status      execute(const struct DispatchContext& ctx) = 0;
    };

    /**
     * @class Registry
     * @brief Registry with key-algo mapping of stored algo implementations
     */
    class Registry {
    public:
        virtual ~Registry() = default;
        virtual void                          add(const std::string& key, std::shared_ptr<RegistryAlgo> algo);
        virtual bool                          has(const std::string& key);
        virtual std::shared_ptr<RegistryAlgo> find(const std::string& key);

    private:
        robin_hood::unordered_flat_map<std::string, std::shared_ptr<RegistryAlgo>> m_registry;
    };

    /**
     * @}
     */

}// namespace spla

#endif//SPLA_REGISTRY_HPP
