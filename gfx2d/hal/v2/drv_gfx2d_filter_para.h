/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Initialization of filter coefficients
 * Author: sdk
 * Create: 2019-05-13
 */

#ifndef __SOURCE_MSP_DRV_GFX2D_HAL_V2_FILTER_PARA__
#define __SOURCE_MSP_DRV_GFX2D_HAL_V2_FILTER_PARA__

/* **************************** add include here ************************************************************ */
#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/* **************************** Macro Definition ************************************************************ */
#define GFX2D_FILTER_LEVELS 7 /* filter level, divided into seven levels */
                              /* CNcomment: �˲��ȼ�,��Ϊ7�� */
#define GFX2D_FILTER_PHASE 17 /* 32 phases, requiring 17 sets of coefficients */
                              /* CNcomment: ��λ,32��λ,��Ҫ17��ϵ�� */
#define GFX2D_FILTER_HORIZON_LUM_TAP 8 /* horizontal luminance filtering order */ /* CNcomment: ˮƽ�����˲����� */
#define GFX2D_FILTER_HORIZON_CHM_TAP 8 /* horizontal chromaticity filtering order */
                                       /* CNcomment: ˮƽɫ���˲����� */
#define GFX2D_FILTER_VERTICAL_LUM_TAP 4 /* vertical luminance filtering order */    /* CNcomment: ��ֱ�����˲����� */
#define GFX2D_FILTER_VERTICAL_CHM_TAP 4 /* vertical chromaticity filtering order */ /* CNcomment:��ֱɫ���˲����� */

/* ***************************** API declaration ************************************************************ */
hi_u32 gfx2d_get_hor_filter_size(hi_void);
hi_u32 gfx2d_get_ver_filter_size(hi_void);
hi_s32 gfx2d_init_zme_v_para(hi_char *filter_buf, hi_u32 filter_buf_size);
hi_s32 gfx2d_init_zme_h_para(hi_char *filter_buf, hi_u32 filter_buf_size);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* __SOURCE_MSP_DRV_GFX2D_HAL_V2_FILTER_PARA__ */
