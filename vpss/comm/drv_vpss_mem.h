/*
* Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: ion  adapter code
* Author: image_libin
* Create: 2019-03-28
 */
#ifndef __DRV_VPSS_MEM__
#define __DRV_VPSS_MEM__

#include <linux/dma-buf.h>
#include "hi_osal.h"

typedef enum {
    HI_DRV_MEM_CACHE_TO_DEVICE = 0,
    HI_DRV_MEM_CACHE_FROM_DEVICE,
    HI_DRV_MEM_CACHE_BIDIRECTIONAL,
    HI_DRV_MEM_CACHE_MAX,
} drv_vpss_mem_cache_mode;

typedef struct {
    osal_mem_type mode;   /* �ڴ�����ģʽ */
    hi_bool is_map_viraddr; /* �Ƿ���Ҫӳ��CPU��ַ */
    hi_bool is_cache;       /* �Ƿ���Ҫcache */
    hi_u32 size;            /* �ڴ����Ĵ�С */
    hi_u8 *name;            /* ion�ӿڲ��������ƣ���ΰ�ڿ�����������������*************************************/
} drv_vpss_mem_attr;

typedef struct {
    hi_bool is_cache;       /* �Ƿ�����cache */
    hi_u32 size;            /* �ڴ����Ĵ�С */
    dma_addr_t phy_addr;    /* �����ַ��32/64����Ӧ */
    hi_u8 *vir_addr;        /* CPU��ַ */
    osal_mem_type mode;   /* �ڴ�����ģʽ */

    struct dma_buf *dma_handle; /* fd��Ӧ��dma buf�����߲���Ҫ��ע */
} drv_vpss_mem_info;

typedef struct {
    struct dma_buf *dma_handle;

    hi_mem_size_t  addr_offset_y;
    hi_mem_size_t  addr_offset_c;
} vpss_dma_para_out;

typedef struct {
    struct dma_buf *dma_handle;
    dma_addr_t phy_addr;
    hi_u64  vir_addr;
} vpss_dma_para_umap;

// �����ڴ�ʹ�ã����ü���+1��Ĭ��ֱ�Ӹ�����Ӧ��fd�������ַ����Ҫ�����ַ
hi_s32 drv_vpss_mem_alloc(const drv_vpss_mem_attr *mem_attr, drv_vpss_mem_info *mem_info);
// �ͷ��ڴ�ʹ�ã����ü���-1
hi_s32 drv_vpss_mem_free(drv_vpss_mem_info *mem_info);

hi_s32 drv_vpss_mem_increase_refcnt(struct dma_buf *dma_handle);
hi_s32 drv_vpss_mem_decrease_refcnt(struct dma_buf *dma_handle);

/* user space must give smmu nosafe fd,can't suppot CMA, safe type */
hi_s32 drv_vpss_mem_map_dma_handle(struct dma_buf *dma_handle, drv_vpss_mem_info *mem_info);
hi_s32 drv_vpss_mem_unmap_dma_handle(vpss_dma_para_umap *dma_info);
hi_s32 drv_vpss_mem_map_vir_addr(struct dma_buf *dma_handle, drv_vpss_mem_info *mem_info);
hi_s32 drv_vpss_mem_unmap_vir_addr(struct dma_buf *dma_handle, hi_u8 *vir_addr);
#endif
