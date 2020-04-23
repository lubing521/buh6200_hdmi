/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: ion  adapter code
 * Author: image_libin
 * Create: 2019-03-28
 */
#ifndef __DRV_PQ_MEM_H__
#define __DRV_PQ_MEM_H__

#include <linux/dma-buf.h>
#include "hi_osal.h"

typedef enum {
    HI_DRV_MEM_CACHE_TO_DEVICE = 0,
    HI_DRV_MEM_CACHE_FROM_DEVICE,
    HI_DRV_MEM_CACHE_BIDIRECTIONAL,
    HI_DRV_MEM_CACHE_MAX,
} drv_pq_mem_cache_mode;

typedef struct {
    osal_mem_type mode;     /* �ڴ�����ģʽ */
    hi_bool is_map_viraddr; /* �Ƿ���Ҫӳ��CPU��ַ */
    hi_bool is_cache;       /* �Ƿ���Ҫcache */
    hi_u32 size;            /* �ڴ����Ĵ�С */
    hi_u8 *name;            /* ion�ӿڲ��������ƣ���ΰ�ڿ�����������������************************************ */
} drv_pq_mem_attr;

typedef struct {
    osal_mem_type mode;     /* �ڴ�����ģʽ */
    hi_bool is_map_viraddr; /* �Ƿ�ӳ����CPU��ַ */
    hi_bool is_cache;       /* �Ƿ�����cache */
    hi_u32 size;            /* �ڴ����Ĵ�С */
    dma_addr_t phy_addr;    /* �����ַ��32/64����Ӧ */
    hi_u8 *vir_addr;        /* CPU��ַ */
    hi_u8 *name;            /* ion�ӿڲ��������ƣ���ΰ�ڿ�����������������************************************ */

    struct dma_buf *dma_buf; /* fd��Ӧ��dma buf�����߲���Ҫ��ע */
} drv_pq_mem_info;

typedef struct {
    hi_u64 fd;               /* dma_buffer ��shared_fd */
    hi_bool is_map_viraddr;  /* �Ƿ���Ҫӳ��CPU��ַ */
    hi_bool is_secure;       /* �Ƿ���Ҫӳ��CPU��ַ */
    dma_addr_t phy_addr;     /* fd��Ӧ�������ַ��32/64����Ӧ */
    hi_u8 *vir_addr;         /* fd��Ӧ��CPU��ַ */
    struct dma_buf *dma_buf; /* fd��Ӧ��dma buf�����߲���Ҫ��ע */
} drv_pq_mem_fd_info;

/* �����ڴ�ӿ� */
// �����ڴ�ʹ�ã����ü���+1��Ĭ��ֱ�Ӹ�����Ӧ��fd�������ַ����Ҫ�����ַ
hi_s32 drv_pq_mem_alloc(const drv_pq_mem_attr *mem_attr, drv_pq_mem_info *mem_info);
// �ͷ��ڴ�ʹ�ã����ü���-1
hi_s32 drv_pq_mem_free(drv_pq_mem_info *mem_info);

hi_s32 drv_pq_mem_get_fd(struct dma_buf *dma_buf);

// �Դ�cash���ڴ���flush
hi_s32 drv_pq_mem_flush(const drv_pq_mem_info *mem_info, drv_pq_mem_cache_mode cache_mode);

/* ʹ���ⲿ���ݵ�fd��ͨ������ĺ����ӿ���ʹ�� */
// ͨ��fd��ȡ�����ַ���������ַ�����ü���+1
hi_s32 drv_pq_mem_map_fd(struct dma_buf *dma_buf_descp, drv_pq_mem_info *fd_info);

// ��ӳ��fd�����ü���-1
hi_s32 drv_pq_mem_unmap_fd(struct dma_buf *dma_buf_descp, drv_pq_mem_info *fd_info);

#endif
