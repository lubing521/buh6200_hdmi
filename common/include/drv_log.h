/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-17
 */

#ifndef __DRV_LOG_H__
#define __DRV_LOG_H__

#include "hi_debug.h"
#include "hi_osal.h"

#include "hi_drv_module.h"

#define LOG_DEV_NAME "sys/log"

#define LOG_MAX_FILE_NAME_LENTH 256

#define LOG_MSG_FROM_USER   0
#define LOG_MSG_FROM_KERNEL 1

typedef struct {
    hi_u32 start_phy_addr;        /* start physic address */ /* CNcomment: ��������ʼ�����ַ */
    hi_u8 *start_virt_addr;       /* start virtual address */ /* CNcomment: ��������ʼ�����ַ */
    hi_u32 buf_size;              /* buffer size */ /* CNcomment: ��������С */
    hi_u32 write;                 /* write offset */ /* CNcomment: д��ַƫ�� */
    hi_u32 read;                  /* read offset */ /* CNcomment: ����ַƫ�� */
    hi_u32 reset_cnt;             /* reset count */ /* CNcomment: ��λ���� */
    hi_u32 write_cnt;             /* write count */ /* CNcomment: д����� */
    osal_wait wq_no_data;         /* wait queque no data */ /* CNcomment: û�����ݵȴ����� */
} log_buf_info;

#ifdef HI_PROC_SUPPORT
hi_s32  drv_log_add_proc(hi_void);
hi_void drv_log_remove_proc(hi_void);
#else
static inline hi_s32 drv_log_add_proc(hi_void)
{
    return HI_SUCCESS;
}

static inline hi_void drv_log_remove_proc(hi_void)
{
    return;
}
#endif

#ifdef HI_LOG_SUPPORT
hi_s32  drv_log_init(hi_void);
hi_void drv_log_exit(hi_void);
#else
static inline hi_s32 drv_log_init(hi_void)
{
    return HI_SUCCESS;
}

static inline hi_void drv_log_exit(hi_void)
{
    return;
}
#endif

hi_s32 drv_log_ioctl(unsigned int cmd, hi_void *arg, hi_void *private_data);

#ifdef CONFIG_COMPAT
hi_s32 drv_log_compat_ioctl(unsigned int cmd, hi_void *arg, hi_void *private_data);
#endif

hi_s32  hi_drv_log_add_module(const hi_char *name, hi_u32 module_id);
hi_s32  hi_drv_log_remove_module(hi_u32 module_id);

#endif /* __DRV_LOG_H__ */

