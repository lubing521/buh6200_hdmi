/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: pq mng fod alg define
 * Author: pq
 * Create: 2016-01-1
 */
 
#ifndef __PQ_MNG_FOD_ALG_H__
#define __PQ_MNG_FOD_ALG_H__

#include "hi_type.h"
#include "hi_vpss_register.h"
#include "pq_mng_ifmd_alg.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* fod param */
typedef struct {
    reg_stillblk_stat still_blk_info;
    reg_lasi_stat lasi_stat_1;
    reg_lasi_stat lasi_stat_2;
} hi_drv_pq_vpss_fod_sw_in_para;

typedef struct {
    hi_s32 field_order;
} hi_drv_pq_vpss_fod_sw_out_para;

typedef struct {
    /* ��ʾ����ͳ����Ϣʱ, �ο����Ƿ�Ϊ�ڶ��� */
    hi_bool is_snd_fld;
    /* ��ʾ������һ�����ø��߼��Ĳο����Ƿ�Ϊ�ڶ��� */
    hi_bool nxt_is2nd_fld;
    /* ��ʾ����ͳ����Ϣʱ, ���ø��߼��ĳ��� */
    hi_bool bt_mode;
    /* ��ʾ����ͳ����Ϣʱ, ���ø��߼��Ĳο���,
    �㷨��Ա�����Ĳο���Ҳ���߼���Ա�ĵ�ǰ�� */
    hi_bool ref_fld;
    hi_s32 sad_buf[16]; /* 16: num */
    hi_s32 sad_diff_acc;
    hi_s32 field_order;
    hi_s32 sad_reg[16][3]; /* 16/3: num */
    hi_s32 arr_fac_frm_sdtv[8]; /* 8: num */
    hi_s32 fac_pos_cnt;
    hi_s32 fac_neg_cnt;
} fod_ctrl_para;

typedef struct {
    hi_u32 init_flag;
    hi_u32 still_blk_thd;
    fod_ctrl_para fod_ctrl_para;
    hi_drv_pq_vpss_fod_sw_out_para rtl_out_para_bak;
} hi_drv_pq_vpss_fod_sw_stat_para;

hi_s32 pq_mng_fod_init_param(hi_u32 handle_no);

hi_s32 pq_mng_field_order_dect(hi_drv_pq_vpss_stt_info *p_fod_calc, hi_s32 *p_field_order);

hi_s32 pq_mng_get_fod_detect_info(hi_u32 *field_order);

hi_s32 pq_mng_set_fod_mode(hi_u32 field_order);

hi_s32 pq_mng_get_fod_mode(hi_u32 *field_order);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
