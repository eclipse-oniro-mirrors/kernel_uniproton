/*
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd. All rights reserved.
 *
 * UniProton is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Create: 2022-09-21
 * Description: UniProton 任务测试用例。
 */
#include "osTest.h"
#include "It_os_task.h"

static VOID TaskF01(VOID)
{
    return;
}

static UINT32 TestCase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = { 0 };
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.stackSize = TASK_STACK_SIZE_TEST;
    task1.name = "Tsk021A";
    task1.taskPrio = TASK_PRIO_TEST - 1;
    task1.reserved = 0;

    ret = PRT_TaskCreate(NULL, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_ERRNO_TSK_PTR_NULL, ret);

    return OS_OK;
}

VOID ItOsTask021(VOID)
{
    TEST_ADD_CASE("ItOsTask021", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

