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

#ifndef SPLA_SPLAEXPRESSIONNODE_HPP
#define SPLA_SPLAEXPRESSIONNODE_HPP

#include <spla-cpp/SplaObject.hpp>
#include <spla-cpp/SplaDescriptor.hpp>
#include <vector>
#include <string>

namespace spla {

    /**
     * @class ExpressionNode
     *
     * Represents and operation in the expression.
     * Stores operation type and required arguments for evaluation.
     * Expression nodes form a computational expression (or dag) with specific dependencies ordering.
     */
    class SPLA_API ExpressionNode final: public Object {
    public:
        ~ExpressionNode() override = default;

        /** Type of the concrete node operation */
        enum class Operation {
            /** Read matrix data to the host buffers */
            MatrixDataRead,
            /** Write matrix data from the host buffers */
            MatrixDataWrite,
            /** Read vector data to the host buffers */
            VectorDataRead,
            /** Write vector data from the host buffers */
            VectorDataWrite,
            /** Read scalar data to the host buffers */
            ScalarDataRead,
            /** Write scalar data from the host buffers */
            ScalarDataWrite
        };

        /** @return Node arguments array */
        const std::vector<RefPtr<Object>> &GetArgs() const;

        /** @return Node argument at specified index */
        const RefPtr<Object> &GetArg(unsigned int idx) const;

        /** @return Node config descriptor */
        const RefPtr<Descriptor> &GetDescriptor() const;

        /** @return Node operation type */
        Operation GetNodeOp() const;

        /** @return Node index in the expression */
        size_t GetIdx() const;

    private:
        friend class Expression;
        friend class ExpressionManager;

        ExpressionNode(Operation operation, class Expression& expression, class Library& library);

        void Link(ExpressionNode* next);
        void SetIdx(size_t idx);
        bool Belongs(class Expression& expression) const;
        void SetArgs(std::vector<RefPtr<Object>> &&args);
        void SetDescriptor(const RefPtr<Descriptor> &desc);

        const std::vector<ExpressionNode*> &GetPrev() const;
        const std::vector<ExpressionNode*> &GetNext() const;

    private:
        // Node private content
        std::vector<RefPtr<Object>> mArgs;
        RefPtr<Descriptor> mDescriptor;
        Operation mNodeOp;
        size_t mIdx;

        // Expression impl related
        class Expression& mParent;
        std::vector<ExpressionNode*> mPrev;
        std::vector<ExpressionNode*> mNext;
    };

    /** @return String name of the expression node operation */
    static inline const wchar_t* ExpressionNodeOpToStr(ExpressionNode::Operation op) {
        switch (op) {
            case ExpressionNode::Operation::MatrixDataRead: return L"MatrixDataRead";
            case ExpressionNode::Operation::MatrixDataWrite: return L"MatrixDataWrite";
            case ExpressionNode::Operation::VectorDataRead: return L"VectorDataRead";
            case ExpressionNode::Operation::VectorDataWrite: return L"VectorDataWrite";
            case ExpressionNode::Operation::ScalarDataRead: return L"ScalarDataRead";
            case ExpressionNode::Operation::ScalarDataWrite: return L"ScalarDataWrite";

            default: return L"Unknown";
        }
    }
}

#endif //SPLA_SPLAEXPRESSIONNODE_HPP
