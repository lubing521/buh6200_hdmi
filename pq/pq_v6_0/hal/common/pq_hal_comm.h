/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: pq reg common api define
 * Author: pq
 * Create: 2016-01-1
 */

#ifndef __PQ_HAL_COMM_H__
#define __PQ_HAL_COMM_H__

#include "hi_debug.h"
#include "hi_type.h"
#include "hi_osal.h"
#include "hi_register_vdp.h"
#include "hi_vpss_register.h"
#include "hi_drv_pq.h"
#include "hi_drv_mem.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define VPSS_REGS_ADDR    0x1300000UL
#define VDP_REGS_ADDR     0x00f00000UL
#define SPECIAL_REGS_ADDR 0xffe00000UL

#define PQ_VPSS_SCAN_REG_OFF ((0x2000 + 15) / 16 * 4)  // NOTE: VPSS_REG_OFF%4==0 NodeAddr need 16 align
#define PQ_DEI_ME_OFFSET (PQ_VPSS_SCAN_REG_OFF * 4)
#define PQ_DEI_ME_FLAG_OFFSET 0x2000

#define PQ_DEI_ME_ADDR_START 0x0e810
#define PQ_DEI_ME_ADDR_END 0x0ebe0

/* from SR_4K_HIPP_CLE_REG46 to SR_4K_HIPP_CLE_REG154 */
#define CLE_4K_PARA_REG_START 0x00F352B8UL
#define CLE_4K_PARA_REG_END   0x00F35468UL
/* from HIPP_CLE_REG46 to HIPP_CLE_REG154 */
#define CLE_8K_PARA_REG_START 0x00F342B8UL
/* 0x00F34468UL + 0xA00 : 8k reg + 8k left reg + 8k right reg. */
#define CLE_8K_PARA_REG_END   0x00F34E68UL

/* sharpen load ddr regs are from VDP_SPFLATOSHT to VDP_SPDTLYVAL */
#define SHARP_VIR_REG_START  0x00F40618UL
#define SHARP_VIR_REG_END    0x00F4072CUL

#define REG_BASE_ADDR_MASK           0xfff00000
#define REG_OFFSET_ADDR_MASK         0x000fffff
#define REGADDR_IS_ALIGN_4BYTE(addr) ((0 == ((addr)&0x3)) ? HI_TRUE : HI_FALSE)

#define PQ_VPSS_WBCREG_SIZE ((sizeof(vpss_stt_reg_type) + 15) & 0xFFFFFFF0)

/* VDP STT: DC0~6:7, HIST4HDR_BIN0~127:128, DCI_BIN:32+33+33=98, ACM_BIN:64, DIM_BIN:20738. */
#define PQ_VDP_STT_BUF_SIZE ((7 + 128 + 98 + 64 + 20738) * 4)

#define PQ_MIN(x, y)           (((x) > (y)) ? (y) : (x))
#define PQ_MAX(x, y)           (((x) > (y)) ? (x) : (y))
#define PQ_CLIP3(x, low, high) (PQ_MAX(PQ_MIN((x), PQ_MAX(high, low)), PQ_MIN(high, low)))

#define pq_kmalloc(size) osal_kmalloc(HI_ID_PQ, size, GFP_KERNEL)

#define pq_kfree_safe(ptr)            \
    do {                              \
        if (HI_NULL != (ptr)) {       \
            osal_kfree(HI_ID_PQ, ptr); \
            (ptr) = HI_NULL;          \
        }                             \
    } while (0)

#define VDP_VP_MAX 2

#define VID_MAX 5 /* in 98c equal to 8; but equal to 5 in 98m and 98m_a */

#define PQ_VP_OFFSET  0x800
#define PQ_VID_OFFSET 0x800
#define PQ_WBC_OFFSET 0x400

#define PQ_GP_MAX    2
#define PQ_GP_OFFSET 0x800

#define PQ_BIT_LEN_MAX    32

#define VDP_ALG_NUM  13
#define VPSS_ALG_NUM 14

#define VPSS_PQ_REG_SIZE(start, end)                 \
    (offsetof(vpss_reg_type, end) + sizeof(hi_u32) - \
        offsetof(vpss_reg_type, start))

#define VDP_PQ_REG_SIZE(start, end)                  \
    (offsetof(vdp_regs_type, end) + sizeof(hi_u32) - \
        offsetof(vdp_regs_type, start))

#define PQ_TRACE(level, range, fmt...) \
    do {                               \
        if (level <= range) {          \
            HI_ERR_PQ(fmt);            \
        }                              \
    } while (0)

#define PQ_CHECK_NULL_PTR_RE_FAIL(ptr)            \
    do {                                          \
        if ((ptr) == NULL) {                      \
            HI_ERR_PQ("%s ptr is NULL!\n", #ptr); \
            return HI_FAILURE;                    \
        }                                         \
    } while (0)

#define PQ_CHECK_NULL_PTR_RE_NULL(ptr)            \
    do {                                          \
        if ((ptr) == NULL) {                      \
            HI_ERR_PQ("%s ptr is NULL!\n", #ptr); \
            return;                               \
        }                                         \
    } while (0)

#define PQ_CHECK_OVER_RANGE_RE_FAIL(id, max_id)  \
    do {                                         \
        if ((id) >= (max_id)) {                  \
            HI_ERR_PQ("[%d] over range!\n", id); \
            return HI_FAILURE;                   \
        }                                        \
    } while (0)

#define PQ_CHECK_OVER_RANGE_RE_NULL(id, max_id)  \
    do {                                         \
        if ((id) >= (max_id)) {                      \
            HI_ERR_PQ("[%d] over range!\n", id); \
            return;                              \
        }                                        \
    } while (0)

#define PQ_CHECK_NUM_OVER_RANGE_RE_FAIL(num, max)     \
    do {                                              \
        if ((num) > (max)) {                              \
            HI_ERR_PQ("[%d] num over range!\n", num); \
            return HI_FAILURE;                        \
        }                                             \
    } while (0)

#define PQ_CHECK_NUM_LOW_RANGE_RE_NULL(num, min)     \
    do {                                              \
        if ((num) < (min)) {                              \
            HI_ERR_PQ("[%d] num over range!\n", num); \
            return;                        \
        }                                             \
    } while (0)

#define PQ_CHECK_NUM_LOW_RANGE_RE_FAIL(num, min)     \
    do {                                              \
        if ((num) < (min)) {                              \
            HI_ERR_PQ("[%d] num over range!\n", num); \
            return HI_FAILURE;                        \
        }                                             \
    } while (0)

#define PQ_CHECK_NUM_OVER_RANGE_RE_NULL(num, max)     \
    do {                                              \
        if ((num) > (max)) {                          \
            HI_ERR_PQ("[%d] num over [%d]!\n", num, max); \
            return;                                   \
        }                                             \
    } while (0)

#define PQ_CHECK_ZERO_RE_FAIL(num)                          \
    do {                                                    \
        if ((num) == 0) {                                   \
            HI_ERR_PQ("[%d] denominator is zero !\n", num); \
            return HI_FAILURE;                              \
        }                                                   \
    } while (0)

#define PQ_CHECK_ZERO_RE_NULL(num)                          \
    do {                                                    \
        if ((num) == 0) {                                   \
            HI_ERR_PQ("[%d] denominator is zero !\n", num); \
            return;                                         \
        }                                                   \
    } while (0)

#define PQ_DBG()                     \
    do {                             \
        HI_DEBUG_PQ("\n"); \
    } while (0)

#define PQ_CHECK_INIT_RE_FAIL(init_flag) \
    do {                                 \
        if ((init_flag) != HI_TRUE) {     \
            HI_ERR_PQ("not init!\n");   \
            return HI_FAILURE;           \
        }                                \
    } while (0)

#define pq_check_init_return_null(init_flag) \
    do {                                 \
        if ((init_flag) != HI_TRUE) {     \
            HI_ERR_PQ("not init!\n");   \
            return;           \
        }                                \
    } while (0)

#define PQ_CHECK_RETURN_SUCCESS(a)     \
    do {                               \
        if ((a) != HI_SUCCESS) {       \
            HI_ERR_PQ("error!\n"); \
            return a;                  \
        }                              \
    } while (0)

#define PQ_CHECK_SUCCESS_RETURN_NULL(a)     \
    do {                               \
        if ((a) != HI_SUCCESS) {       \
            HI_ERR_PQ("error!\n"); \
            return;                  \
        }                              \
    } while (0)

#define PQ_SAFE_MEMCPY(dst, src, size)   memcpy(dst, src, size)
#define PQ_SAFE_MEMSET(src, value, size) memset(src, value, size)

#define ALG_CLIP3(low, high, x) (MAX2(MIN2((high), (x)), (low)))

#ifdef PQ_PROC_CTRL_SUPPORT
#define PQPRINT(type, fmt, arg...) pq_hal_print_msg(type, fmt, ##arg)
#else
#define PQPRINT(type, fmt, arg...)
#endif

/* PQ bin module���� */
typedef enum {
    PQ_PRN_NOTHING = 0,   /* ����ӡ��Ϣ����ʼ��ʱʹ�� */
    PQ_PRN_FATAL = 0x1,   /* �����쳣��fatal error��������δ֪�쳣 */
    PQ_PRN_ERROR = 0x2,   /* һ���쳣��error���������﷨���� */
    PQ_PRN_WARNING = 0x4, /* �澯�쳣 */
    PQ_PRN_INFO = 0x8,    /* ֪ͨ��Ϣ */
    PQ_PRN_DBG = 0x10,    /* ������Ϣ */

    PQ_PRN_VPSS = 0x20,  /* VPSS ������Ϣ */
    PQ_PRN_VDP = 0x40,   /* VDP ������Ϣ */
    PQ_PRN_TABLE = 0x80, /* PQ table ������Ϣ��ӡ */

    PQ_PRN_DEI = 0x100,       /* DEI �㷨������Ϣ��ӡ */
    PQ_PRN_FMD_READ = 0x200,  /* FMD_READ �㷨������Ϣ��ӡ */
    PQ_PRN_FMD_CALC = 0x400,  /* FMD_CALC �㷨������Ϣ��ӡ */
    PQ_PRN_HSHARPEN = 0x800,  /* HSHARPEN �㷨������Ϣ��ӡ */
    PQ_PRN_DNR = 0x1000,      /* DNR �㷨������Ϣ��ӡ */
    PQ_PRN_DCI = 0x2000,      /* DCI �㷨������Ϣ��ӡ */
    PQ_PRN_ACM = 0x4000,      /* ACM �㷨������Ϣ��ӡ */
    PQ_PRN_SHARPEN = 0x10000, /* SHARPEN �㷨������Ϣ��ӡ */
    PQ_PRN_SR = 0x20000,      /* SR �㷨������Ϣ��ӡ */
    PQ_PRN_DB_READ = 0x40000, /* DB_READ �㷨������Ϣ��ӡ */
    PQ_PRN_DB_CALC = 0x80000, /* DB_CALC �㷨������Ϣ��ӡ */
    PQ_PRN_DM = 0x1,          /* DM �㷨������Ϣ��ӡ */
    PQ_PRN_CSC = 0x2,         /* CSC �㷨������Ϣ��ӡ */
    PQ_PRN_DC = 0x3,          /* Decontour �㷨������Ϣ��ӡ */
    PQ_PRN_COCO = 0x4,        /* Colorcoring �㷨������Ϣ��ӡ */
    PQ_PRN_ZME = 0x5,         /* ZME �㷨������Ϣ��ӡ */
    PQ_PRN_TNR = 0x6,         /* TNR �㷨������Ϣ��ӡ */
    PQ_PRN_SNR = 0x10,        /* SNR �㷨������Ϣ��ӡ */
    PQ_PRN_VPSSCSC = 0x20,    /* VPSS CSC �㷨������Ϣ��ӡ */
    PQ_PRN_VPSSGAMMA = 0x40,  /* VPSS GAMMA �㷨������Ϣ��ӡ */
    PQ_PRN_VDP4KSNR = 0x80,   /* VDP 4K SNR �㷨������Ϣ��ӡ */
    PQ_PRN_HDR = 0x100,       /* HDR �㷨������Ϣ��ӡ */
    PQ_PRN_GFXHDR = 0x200,    /* GFXHDR �㷨������Ϣ��ӡ */

    PQ_PRN_ALWS = 0xffffffff /* ���ܿش�ӡ */
} pq_prn_type;

typedef enum {
    VDP_LAYER_VP0 = 0,
    VDP_LAYER_VP1 = 1,
    VDP_LAYER_DHD0 = 2,

    VDP_LAYER_VP_BUTT

} pq_hal_layer_vp;

typedef enum {
    PQ_HAL_LAYER_VID0 = 0, /* VDP_LAYER_V0 */
    PQ_HAL_LAYER_VID1, /* VDP_LAYER_V1 */
    PQ_HAL_LAYER_VID2, /* VDP_LAYER_V2 */
    PQ_HAL_LAYER_VID3, /* VDP_LAYER_V3 */
    PQ_HAL_LAYER_VID4, /* VDP_LAYER_V4 */

    PQ_HAL_LAYER_VID_BUTT

} pq_hal_layer_vid;

/*
 * brief ��ʼ��HALģ�飬���뱾�ؼĴ����ڴ�;
 * attention
 * param[in] : NA
 * retval :HI_SUCCESS
 */
hi_s32 pq_comm_init(hi_void);

/*
 * brief ȥ��ʼ��HALģ��,�ͷű��ؼĴ����ڴ�;
 * attention
 * param[in] : NA
 * retval :HI_SUCCESS
 */
hi_s32 pq_comm_deinit(hi_void);

/*
 * brief ����VPSS�Ĵ���;
 * attention
 * param[in] handle_id  : VPSSͨ����
 * param[in] *pst_vpss_reg  : �������������ļĴ���ָ��
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_update_vpss_reg(hi_u32 handle_id, vpss_reg_type *vpss_reg);

/*
 * brief ����VDP�Ĵ���;
 * attention
 * param[in] *pst_vdp_reg  : ��������������VPSS�Ĵ���ָ��
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_update_vdp_reg(vdp_regs_type *vdp_reg);

/*
 * brief ���VPSS��ǰhandle_id��Ӧ����Ĵ����Ƿ���Ч;
 * attention
 * param[in] handle_id
 * retval ::hi_s32
 */
hi_s32 pq_hal_check_vpss_valid(hi_u32 handle_id);

/*
 * brief ��ȡVPSS��ǰ�Ĵ���;
 * attention
 * param[in] handle_id
 * retval ::VPSS�Ĵ���ָ��
 */
vpss_reg_type *pq_hal_get_vpss_reg(hi_u32 handle_id);

/*
 * brief д�Ĵ���;
 * attention
 * param[in] handle_id
 * param[in] reg_addr
 * param[in] value
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_write_register(hi_u32 handle_id, hi_u32 reg_addr, hi_u32 value);

/*
 * brief ���Ĵ���;
 * attention
 * param[in] handle_id
 * param[in] reg_addr
 * param[out] *pu32_value
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_read_register(hi_u32 handle_id, hi_u32 reg_addr, hi_u32 *value);

/*
 * brief ������ʼBITλ����U32����;
 * attention
 * param[in] src
 * param[in] src_start_bit
 * param[out] *pu32_dst
 * param[in] dst_start_bit
 * param[in] num
 * retval ::
 */
hi_void pq_hal_copy_u32_by_bit(hi_u32 src, hi_u32 src_start_bit, hi_u32 *dst, hi_u32 dst_start_bit, hi_u32 num);

/*
 * brief ����bitλ����U32����
 * attention
 * param[out] pul_data,;
 * param[in] uc_bit_no
 * retval :HI_SUCCESS
 */
hi_void pq_hal_u32_set_bit(hi_u32 *pul_data, hi_u8 bit_no);

/*
 * brief ��U32��Ӧ��bitλ����
 * attention
 * param[out] pul_data,;
 * param[in] uc_bit_no
 * retval :HI_SUCCESS
 */
hi_void pq_hal_u32_clear_bit(hi_u32 *pul_data, hi_u8 bit_no);

/*
 * brief ��U32�����������λ����ͻ�ȡ��Ӧ��ֵ
 * attention NA
 * param[in]  ul_data,  uc_max_bit,  uc_min_bit;
 * retval :HI_SUCCESS
 */
hi_u32 pq_hal_get_u32_by_bit(hi_u32 data, hi_u8 max_bit, hi_u8 min_bit);

/*
 * brief �������λ�����λ����U32������Ӧ��ֵ
 * attention NA
 * param[in] pul_data, uc_max_bit, uc_min_bit, ul_value;
 * retval :HI_SUCCESS
 */
hi_void pq_hal_set_u32_by_bit(hi_u32 *pul_data, hi_u8 max_bit, hi_u8 min_bit, hi_u32 value);

hi_s32 pq_hal_is_vpss_reg(hi_u32 reg_addr);

hi_s32 pq_hal_is_vdp_reg(hi_u32 reg_addr);

hi_s32 pq_hal_is_special_reg(hi_u32 reg_addr);

hi_u32 pq_hal_reg_read(volatile hi_u32 *reg_addr);

hi_void pq_hal_reg_write(volatile hi_u32 *reg_addr, hi_u32 value);

hi_u32 pq_new_regread(uintptr_t reg_addr);
hi_void pq_new_regwrite(uintptr_t reg_addr, hi_u32 value);

hi_void pq_hal_vpss_reg_write(volatile hi_u32 *a, hi_u32 b);
hi_u32 pq_hal_vpss_reg_read(volatile hi_u32 *a);

hi_s32 pq_hal_print_msg(hi_u32 type, const hi_s8 *format, ...);

hi_s32 pq_hal_set_print_type(hi_u32 type);

hi_void pq_hal_copy_reg_by_size(hi_u32 *dst_reg, hi_u32 *src_reg, hi_u32 reg_size);

vdp_regs_type *pq_hal_get_vdp_set_reg(hi_void);
hi_drv_pq_dbg_vpss_vir_soft *pq_hal_get_vpss_vir_soft_reg(hi_void);

/*
 * brief ��ʼ��VDP STT ����;
 * attention
 * param[in] : virtual addr and physical addr.
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_comm_vdp_stt_init(hi_u8 *vir_addr, dma_addr_t phy_addr);

/*
 * brief ����VDP STT��Ϣ;
 * attention
 * param[in] : NA
 * retval :HI_SUCCESS
 */
hi_s32 pq_hal_comm_vdp_stt_update(hi_void);

/*
 * brief ����VDP STT����Ĵ�����ַ;
 * attention
 * param[in] : virtual addr
 * retval :hi_void
 */
hi_void pq_hal_set_vdp_stt_reg_vir_addr(hi_u8 *vir_addr);

/*
 * brief ��ȡVDP STT����Ĵ�����ַ;
 * attention
 * param[in] : NA
 * retval :hi_u8*
 */
hi_u8 *pq_hal_get_vdp_stt_reg_vir_addr(hi_void);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* end of #ifndef __PQ_HAL_COMM_H__ */
