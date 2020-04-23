/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: hal_vpss_wbc_nrrfr.h hander file
 * Author: zhangjunyu
 * Create: 2016/07/02
 */

#ifndef __HAL_VPSS_WBC_NRRFR_H__
#define __HAL_VPSS_WBC_NRRFR_H__

#include "vpss_comm.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define VPSS_WBC_NRRFR_MAX_NODE 5

typedef struct {
    hi_drv_vpss_video_frame wbc_frame;  // ֡��Ϣ
    list node;                     // ����ڵ�
} vpss_wbc_nrrfr_data;

typedef enum {
    VPSS_WBC_NRRFR_MODE_NORMAL = 2,  // ��д֡ģʽ����д���п���2��֡��ڵ�
    VPSS_WBC_NRRFR_MODE_3FIELD = 3,  // ��д����ģʽ����д���п���3��֡��ڵ�
    VPSS_WBC_NRRFR_MODE_4FIELD = 4,  // ��д����ģʽ����д���п���4��֡��ڵ�
    VPSS_WBC_NRRFR_MODE_5FIELD = 5,  // ��д�峡ģʽ����д���п���5��֡��ڵ�
    VPSS_WBC_NRRFR_MODE_MAX
} vpss_wbc_nrrfr_mode;

typedef enum {
    /* ��ȡ�ο�֡ʱ������д֡��������ʱ��δ��д�Ĳο�֡��ֵΪ��ʼֵ��
    ��д�Ĳο�֡������ֵ */
    VPSS_WBC_NRRFR_REF_MODE_INIT = 1,
    /* ��ȡ�ο�֡ʱ������д֡��������ʱ��δ��д�Ĳο�֡��ֵΪ��Ч��
    ��д�Ĳο�֡������ֵ */
    VPSS_WBC_NRRFR_REF_MODE_NULL = 2,
    VPSS_WBC_NRRFR_REF_MODE_MAX
} vpss_wbc_nrrfr_ref_mode;

typedef struct {
    hi_u32 width;                      // ֡��Ϣ��
    hi_u32 height;                     // ֡��Ϣ��
    hi_drv_pixel_format pixel_format;  // ֡��Ϣ���ظ�ʽ
    hi_drv_compress_info cmp_info;
    hi_drv_pixel_bitwidth bit_width;  // ֡��Ϣͼ��bitλ,10 bit or 8 bit
} vpss_wbc_nrrfr_calc;

typedef struct {
    vpss_wbc_nrrfr_mode mode;          // ��д���й���ģʽ
    vpss_wbc_nrrfr_ref_mode ref_mode;  // ģʽֵʹ��ģʽ
    hi_u32 width;                      // ֡��Ϣ��
    hi_u32 height;                     // ֡��Ϣ��
    hi_bool interlace;
    hi_drv_pixel_format pixel_format;  // ֡��Ϣ���ظ�ʽ
    hi_drv_compress_info cmp_info;
    hi_drv_pixel_bitwidth bit_width;  // ֡��Ϣͼ��bitλ,10 bit or 8 bit
    hi_u8 *mem_name;                  // �ڴ������
    hi_bool secure;
} vpss_wbc_nrrfr_attr;

typedef struct {
    hi_bool init;                                            // ��ʼ����ʶ
    hi_u32 complete_count;                                   // ��д������ת����
    vpss_wbc_nrrfr_data data_list[VPSS_WBC_NRRFR_MAX_NODE];  // ��д����ṹ
    vpss_wbc_nrrfr_attr wbc_attr;                            // ��д��������
    drv_vpss_mem_info vpss_mem;                                // ֡����Ϣ
    list *first_ref;                                         // ָ�������һ���ο�֡
} vpss_wbc_nrrfr;

hi_s32 vpss_wbc_nrrfr_init(vpss_wbc_nrrfr *wbc, vpss_wbc_nrrfr_attr *in_attr);

hi_s32 vpss_wbc_nrrfr_deinit(vpss_wbc_nrrfr *wbc);

hi_s32 vpss_wbc_nrrfr_get_ref_info(vpss_wbc_nrrfr *wbc, hi_drv_vpss_video_frame **data_list);

hi_s32 vpss_wbc_nrrfr_get_wbc_info(vpss_wbc_nrrfr *wbc, hi_drv_vpss_video_frame **data);

hi_s32 vpss_wbc_nrrfr_complete(vpss_wbc_nrrfr *wbc);

hi_s32 vpss_wbc_nrrfr_reset(vpss_wbc_nrrfr *wbc);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif





