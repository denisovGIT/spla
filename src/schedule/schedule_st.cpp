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

#include "schedule_st.hpp"

namespace spla {

    Status ScheduleSingleThread::step_task(ref_ptr<ScheduleTask> task) {
        std::vector<ref_ptr<ScheduleTask>> step = {task};
        m_steps.push_back(std::move(step));
        return Status::Ok;
    }

    Status ScheduleSingleThread::step_tasks(std::vector<ref_ptr<ScheduleTask>> tasks) {
        m_steps.push_back(std::move(tasks));
        return Status::Ok;
    }

    Status ScheduleSingleThread::submit() {

        return Status::Ok;
    }

    void ScheduleSingleThread::set_label(std::string label) {
        m_label = std::move(label);
    }

    const std::string& ScheduleSingleThread::get_label() const {
        return m_label;
    }

}// namespace spla
