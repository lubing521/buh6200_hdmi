/*
* Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:osal_math
* Author: seg
* Create: 2019-10-11
*/

#if defined(__KERNEL__) && !defined(__UBOOT__)
#include <linux/module.h>
#include <linux/kernel.h>
#else
#include <linux/math64.h>
#endif
#include "hi_osal.h"

#ifdef __UBOOT__
#define EXPORT_SYMBOL(x)
#endif

/* the result of u64/u32. */
unsigned long long osal_div_u64(unsigned long long dividend, unsigned int divisor)
{
    return div_u64(dividend, divisor);
}
EXPORT_SYMBOL(osal_div_u64);

/* the result of s64/s32. */
long long osal_div_s64(long long dividend, int divisor)
{
    return div_s64(dividend, divisor);
}
EXPORT_SYMBOL(osal_div_s64);

/* the result of u64/u64. */
unsigned long long osal_div64_u64(unsigned long long dividend, unsigned long long divisor)
{
    return div64_u64(dividend, divisor);
}
EXPORT_SYMBOL(osal_div64_u64);

/* the result of s64/s64. */
long long osal_div64_s64(long long dividend, long long divisor)
{
    return div64_s64(dividend, divisor);
}
EXPORT_SYMBOL(osal_div64_s64);

/* the remainder of u64/u32. */
unsigned long long osal_div_u64_rem(unsigned long long dividend, unsigned int divisor)
{
    unsigned int remainder;

    div_u64_rem(dividend, divisor, &remainder);

    return remainder;
}
EXPORT_SYMBOL(osal_div_u64_rem);

/* the remainder of s64/s32. */
long long osal_div_s64_rem(long long dividend, int divisor)
{
    int remainder;

    div_s64_rem(dividend, divisor, &remainder);

    return remainder;
}
EXPORT_SYMBOL(osal_div_s64_rem);

/* the remainder of u64/u64. */
unsigned long long osal_div64_u64_rem(unsigned long long dividend, unsigned long long divisor)
{
    unsigned long long remainder;

    div64_u64_rem(dividend, divisor, &remainder);

    return remainder;
}
EXPORT_SYMBOL(osal_div64_u64_rem);
