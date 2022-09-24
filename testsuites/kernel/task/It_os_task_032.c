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

static UINT32 TestCase(VOID)
{
    UINT32 ret;

    ret = PRT_TaskSuspend(g_idleTaskId);
    ICUNIT_ASSERT_EQUAL(ret, OS_ERRNO_TSK_OPERATE_IDLE, ret);

    ret = PRT_TaskResume(g_idleTaskId);
    ICUNIT_ASSERT_EQUAL(ret, OS_ERRNO_TSK_NOT_SUSPENDED, ret);

    return OS_OK;
}

VOID ItOsTask032(VOID)
{
    TEST_ADD_CASE("ItOsTask032", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

