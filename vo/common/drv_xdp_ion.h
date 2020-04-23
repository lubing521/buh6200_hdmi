/*
* Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: ion  adapter code
* Author: image_libin
* Create: 2019-03-28
 */
#ifndef __HI_DRV_ION_H__
#define __HI_DRV_ION_H__

#include <linux/dma-buf.h>
#include "hi_osal.h"


typedef enum {
    HI_DRV_MEM_CACHE_TO_DEVICE = 0,
    HI_DRV_MEM_CACHE_FROM_DEVICE,
    HI_DRV_MEM_CACHE_BIDIRECTIONAL,
    HI_DRV_MEM_CACHE_MAX,
} drv_xdp_mem_cache_mode;

typedef struct {
    osal_mem_type mode;   /* �ڴ�����ģʽ */
    hi_bool is_map_viraddr; /* �Ƿ���Ҫӳ��CPU��ַ */
    hi_bool is_cache;       /* �Ƿ���Ҫcache */
    hi_u32 size;            /* �ڴ����Ĵ�С */
    hi_u8 *name;            /* ion�ӿڲ��������ƣ���ΰ�ڿ�����������������*************************************/
} drv_xdp_mem_attr;

typedef struct {
    hi_u32 size;            /* �ڴ����Ĵ�С */
    dma_addr_t phy_addr;    /* �����ַ��32/64����Ӧ */
    hi_u8 *vir_addr;        /* CPU��ַ */
    osal_mem_type mode;

    struct dma_buf *dma_buf;
} drv_xdp_mem_info;

typedef struct {
    dma_addr_t nssmmu;
    dma_addr_t phys_addr;
    dma_addr_t secsmmu;
    int        fd;
    size_t     offset;
} drv_xdp_mem_just_addr_info;


// �Դ�cash���ڴ���flush
hi_void drv_xdp_mem_invalid(const drv_xdp_mem_info *mem_info, hi_bool is_cache);
hi_void drv_xdp_mem_flush(const drv_xdp_mem_info *mem_info, hi_bool is_cache);
hi_s32 drv_xdp_mem_alloc(const drv_xdp_mem_attr *mem_attr, drv_xdp_mem_info *mem_info);
hi_s32 drv_xdp_mem_free(drv_xdp_mem_info *mem_info);
hi_s32 drv_xdp_mem_get_fd(struct dma_buf *dma_buf);
hi_void drv_xdp_mem_close_fd(int fd);
struct dma_buf *drv_xdp_mem_get_dmabuf(int fd);
hi_s32 drv_xdp_mem_increase_refcnt(struct dma_buf *dma_buf);
hi_s32 drv_xdp_mem_decrease_refcnt(struct dma_buf *dma_buf);
hi_void drv_xdp_mem_get_refcnt(hi_u32 *ref_increase_cnt, hi_u32 *ref_decrease_cnt);
hi_void drv_xdp_mem_reset_refcnt(hi_void);
hi_s32 drv_xdp_mem_map_dma_handle(struct dma_buf *dma_buf_descp,
                                  drv_xdp_mem_info *fd_info);
hi_s32 drv_xdp_mem_unmap_dma_handle(struct dma_buf *dma_buf_descp,
                                    drv_xdp_mem_info *fd_info);
#endif
