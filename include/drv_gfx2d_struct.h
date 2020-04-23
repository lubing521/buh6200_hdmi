/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: err msg
 * Author: data structure
 * Create: 2019-02-15
 */
#ifndef _DRV_GFX2D_STRUCT_H_
#define _DRV_GFX2D_STRUCT_H_

#include "hi_type.h"
#include "hi_module.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define DRV_GFX2D_MAX_SURFACE_NUM 3
#define DRV_GFX2d_FILTERPARAM_ADDR_CNT 2
#define DRV_GFX2D_MAX_ALPHASUM 17
#define DRV_GFX2D_MAX_HOLES_NUM 4

/* * \addtogroup      GFX TYPE */
/* * @{ */ /* * <!-- ��GFX TYPE�� */

typedef enum {
    DRV_GFX2D_DEV_ID_0 = 0x0,
    DRV_GFX2D_DEV_ID_BUTT
} drv_gfx2d_dev_id;

/* enum of the color format */
/* CNcomment:ͼ���ʽö�� */
typedef enum {
    DRV_GFX2D_FMT_RGB444 = 0, /* < RGB444��ʽ, Redռ4bits Greenռ4bits, Blueռ4bits, �����ʽ�������� */
    DRV_GFX2D_FMT_BGR444,     /* < BGR444��ʽ */
    DRV_GFX2D_FMT_RGB555,     /* < RGB555��ʽ */
    DRV_GFX2D_FMT_BGR555,     /* < BGR555��ʽ */
    DRV_GFX2D_FMT_RGB565,     /* < RGB565��ʽ */
    DRV_GFX2D_FMT_BGR565,     /* < BGR565��ʽ */
    DRV_GFX2D_FMT_RGB888,     /* < RGB888��ʽ */
    DRV_GFX2D_FMT_BGR888,     /* < BGR888��ʽ */
    DRV_GFX2D_FMT_KRGB888,
    DRV_GFX2D_FMT_KBGR888,
    DRV_GFX2D_FMT_ARGB4444,     /* < ARGB4444��ʽ */
    DRV_GFX2D_FMT_ABGR4444,     /* < ABGR4444��ʽ */
    DRV_GFX2D_FMT_RGBA4444,     /* < RGBA4444��ʽ */
    DRV_GFX2D_FMT_BGRA4444,     /* < BGRA4444��ʽ */
    DRV_GFX2D_FMT_ARGB1555,     /* < ARGB1555��ʽ */
    DRV_GFX2D_FMT_ABGR1555,     /* < ABGR1555��ʽ */
    DRV_GFX2D_FMT_RGBA1555,     /* < RGBA1555��ʽ */
    DRV_GFX2D_FMT_BGRA1555,     /* < BGRA1555��ʽ */
    DRV_GFX2D_FMT_ARGB8565,     /* < ARGB8565��ʽ */
    DRV_GFX2D_FMT_ABGR8565,     /* < ABGR8565��ʽ */
    DRV_GFX2D_FMT_RGBA8565,     /* < RGBA8565��ʽ */
    DRV_GFX2D_FMT_BGRA8565,     /* < BGRA8565��ʽ */
    DRV_GFX2D_FMT_ARGB8888,     /* < ARGB8888��ʽ */
    DRV_GFX2D_FMT_ABGR8888,     /* < ABGR8888��ʽ */
    DRV_GFX2D_FMT_RGBA8888,     /* < RGBA8888��ʽ */
    DRV_GFX2D_FMT_BGRA8888,     /* < BGRA8888��ʽ */
    DRV_GFX2D_FMT_ARGB2101010,  /* < ARGB2101010��ʽ */
    DRV_GFX2D_FMT_ARGB10101010, /* < ARGB10101010��ʽ */
    DRV_GFX2D_FMT_FP16,         /* < FP16��ʽ */
    DRV_GFX2D_FMT_CLUT1,        /* < ��Alpha����, ��ɫ��1bit��ʽ,ÿ������1��bit��ʾ */
    DRV_GFX2D_FMT_CLUT2,        /* < ��Alpha����, ��ɫ��2bit��ʽ,ÿ������2��bit��ʾ */
    DRV_GFX2D_FMT_CLUT4,        /* < ��Alpha����, ��ɫ��4bit��ʽ,ÿ������4��bit��ʾ */
    DRV_GFX2D_FMT_CLUT8,        /* < ��Alpha����, ��ɫ��8bit��ʽ,ÿ������8��bit��ʾ */
    DRV_GFX2D_FMT_ACLUT44,      /* < ��Alpha����, ��ɫ��1bit��ʽ,ÿ������1��bit��ʾ */
    DRV_GFX2D_FMT_ACLUT88,      /* < ��Alpha����, ��ɫ��1bit��ʽ,ÿ������1��bit��ʾ */
    DRV_GFX2D_FMT_YUV888,       /* < YUV packet��ʽ, ��alpha���� */
    DRV_GFX2D_FMT_AYUV8888,     /* < YUV packet��ʽ, ��alpha���� */
    DRV_GFX2D_FMT_YUYV422,
    /* < YUV packet422 format */ /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_YVYU422,
    /* < YUV packet422 format */ /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_UYVY422,
    /* < YUV packet422 format */ /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_YYUV422,
    /* < YUV packet422 format */ /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_VYUY422,
    /* < YUV packet422 format */ /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_VUYY422,
    /* < YUV packet422 format */     /* <CNcomment:YUV packet422��ʽ */
    DRV_GFX2D_FMT_SEMIPLANAR400,     /* < Semi-planar YUV400��ʽ, ��Ӧ��JPG���� */
    DRV_GFX2D_FMT_SEMIPLANAR420UV,   /* < Semi-planar YUV420��ʽ */
    DRV_GFX2D_FMT_SEMIPLANAR420VU,   /* < Semi-planar YUV420��ʽ */
    DRV_GFX2D_FMT_SEMIPLANAR422UV_H, /* < Semi-planar YUV422��ʽ, ˮƽ�������, ��Ӧ��JPG���� */
    DRV_GFX2D_FMT_SEMIPLANAR422VU_H, /* < Semi-planar YUV422��ʽ, ˮƽ�������, ��Ӧ��JPG���� */
    DRV_GFX2D_FMT_SEMIPLANAR422UV_V, /* < Semi-planar YUV422��ʽ, ��ֱ�������, ��Ӧ��JPG���� */
    DRV_GFX2D_FMT_SEMIPLANAR422VU_V, /* < Semi-planar YUV422��ʽ, ��ֱ�������, ��Ӧ��JPG���� */
    DRV_GFX2D_FMT_SEMIPLANAR444UV,   /* < Semi-planar YUV444��ʽ */
    DRV_GFX2D_FMT_SEMIPLANAR444VU,
    DRV_GFX2D_FMT_PLANAR400,
    DRV_GFX2D_FMT_PLANAR420,
    DRV_GFX2D_FMT_PLANAR411,
    DRV_GFX2D_FMT_PLANAR410,
    DRV_GFX2D_FMT_PLANAR422H,
    DRV_GFX2D_FMT_PLANAR422V,
    DRV_GFX2D_FMT_PLANAR444,
    DRV_GFX2D_FMT_MAX
} drv_gfx2d_compose_fmt;

/* enum of the compress type */
/* CNcomment:ͼ��ѹ������ö�� */
typedef enum {
    DRV_GFX2D_COMPRESS_NONE = 0x0,
    DRV_GFX2D_COMPRESS_HFBC,
    DRV_GFX2D_COMPRESS_AFBC,
    DRV_GFX2D_COMPRESS_MAX
} drv_gfx2d_compress_type;

/* structure of compress info */
/* CNcomment:ѹ����Ϣ�ṹ�� */
typedef struct {
    drv_gfx2d_compress_type compress_type;
} drv_gfx2d_compress_msg;

typedef enum {
    DRV_GFX2D_HDR_MODE_SDR,
    DRV_GFX2D_HDR_MODE_HDR10,
    DRV_GFX2D_HDR_MODE_HLG,
    DRV_GFX2D_HDR_MODE_MAX
} drv_gfx2d_xdr_mode;

typedef enum {
    DRV_GFX2D_COLOR_SPACE_BT709,
    DRV_GFX2D_COLOR_SPACE_BT2020,
    DRV_GFX2D_COLOR_SPACE_MAX
} drv_gfx2d_color_space;

/* enum of the surface type */
/* CNcomment:surface����ö�� */
typedef enum {
    DRV_GFX2D_SURFACE_TYPE_MEM = 0x0, /* <CNcomment:�ڴ�����surface */
    DRV_GFX2D_SURFACE_TYPE_COLOR,     /* <CNcomment:��ɫ����surface, ����Ҫ��fence֮��, ���ڴ���� */
} drv_gfx2d_compose_surface_type;

/* enum of the filter mode */
/* CNcomment:�˲�ģʽö�� */
typedef enum {
    DRV_GFX2D_FILTER_ALL = 0x0, /* <CNcomment:����ɫ��alphaͨ��ͬʱ�˲� */
    DRV_GFX2D_FILTER_COLOR,     /* <CNcomment:����ɫ�����˲�            */
    DRV_GFX2D_FILTER_ALPHA,     /* <CNcomment:��alphaͨ���˲�           */
    DRV_GFX2D_FILTER_NONE,      /* <CNcomment:�������˲�, ʹ�ø���ģʽ, �����о��, ���ĸ����˲���Ч������ */
} drv_gfx2d_compose_filter_mode;

/* enum of the clip mode */
/* CNcomment:����ģʽö�� */
typedef enum {
    DRV_GFX2D_CLIP_NONE = 0x0,
    DRV_GFX2D_CLIP_INSIDE,
    DRV_GFX2D_CLIP_OUTSIDE,
} drv_gfx2d_compose_clip_mode;

/* enum of the rop mode */
/* CNcomment:ROPģʽö�� */
typedef enum {
    DRV_GFX2D_ROP_BLACK = 0x0, /* < Blackness */
    DRV_GFX2D_ROP_NOTMERGEPEN, /* < ~(S2 | S1) */
    DRV_GFX2D_ROP_MASKNOTPEN,  /* < ~S2&S1 */
    DRV_GFX2D_ROP_NOTCOPYPEN,  /* < ~S2 */
    DRV_GFX2D_ROP_MASKPENNOT,  /* < S2&~S1 */
    DRV_GFX2D_ROP_NOT,         /* < ~S1 */
    DRV_GFX2D_ROP_XORPEN,      /* < S2^S1 */
    DRV_GFX2D_ROP_NOTMASKPEN,  /* < ~(S2 & S1) */
    DRV_GFX2D_ROP_MASKPEN,     /* < S2&S1 */
    DRV_GFX2D_ROP_NOTXORPEN,   /* < ~(S2^S1) */
    DRV_GFX2D_ROP_NOP,         /* < S1 */
    DRV_GFX2D_ROP_MERGENOTPEN, /* < ~S2|S1 */
    DRV_GFX2D_ROP_COPYPEN,     /* < S2 */
    DRV_GFX2D_ROP_MERGEPENNOT, /* < S2|~S1 */
    DRV_GFX2D_ROP_MERGEPEN,    /* < S2|S1 */
    DRV_GFX2D_ROP_WHITE,       /* < Whiteness */
} drv_gfx2d_compose_rop_mode;

/* structure of rect */
/* CNcomment:���νṹ�� */
typedef struct {
    hi_s32 x;      /* <CNcomment:���ε����ϵ������ */
    hi_s32 y;      /* <CNcomment:���ε����ϵ������� */
    hi_u32 width;  /* <CNcomment:���εĿ� */
    hi_u32 height; /* <CNcomment:���εĸ� */
} drv_gfx2d_compose_rect;

/* structure of alpha expand info */
/* CNcomment:ARGB1555��ʽalpha��չ��Ϣ�ṹ�� */
typedef struct {
    hi_u8 alpha0;         /* <CNcomment:������չalphaʱ, 0��Ӧ��alphaֵ. */
    hi_u8 alpha1;         /* <CNcomment:������չalphaʱ, 1��Ӧ��alphaֵ. */
    hi_bool alpha_ext_en; /* <CNcomment:�Ƿ������չalpha. */
} drv_gfx2d_compose_alpha_ext;

typedef struct {
    hi_u32 alpha_sum[DRV_GFX2D_MAX_ALPHASUM];
} drv_gfx2d_compose_ext_info;

/* structure of memory surface */
/* CNcomment:�ڴ�����surface��Ϣ�ṹ�� */
typedef struct {
    drv_gfx2d_compose_surface_type surface_type; /* <CNcomment:surface����                     */
    drv_gfx2d_compose_fmt format;                /* <CNcomment:���ظ�ʽ,ֻ��MEM����surface��Ч */
    hi_u32 width;                                /* <CNcomment:���                            */
    hi_u32 height;                               /* <CNcomment:�߶�                            */
    hi_u32 color_data;                           /* <CNcomment:surface��ɫֵ, ֻ��COLOR����surface��Ч */
    /* <CNcomment:�ڴ��ַ��Ϣ,ֻ��mem���͵�surface��Ч
     * package��ʽ:     phy_addr[0]��ʾ���ݵ�ַ
     * semi-planar��ʽ: phy_addr[0]��ʾY������ַ, phy_addr[1]��ʾCbCr������ַ
     * planar��ʽ:      phy_addr[0]��ʾY������ַ, phy_addr[1]��ʾCb������ַ, phy_addr[2]��ʾCr������ַ
     */
    hi_u64 phy_addr[DRV_GFX2D_MAX_SURFACE_NUM];
    hi_mem_handle mem_handle[DRV_GFX2D_MAX_SURFACE_NUM];
    /* <CNcomment:�п��,ֻ��mem���͵�surface��Ч
     * package��ʽ:     stride[0]��ʾ���ݿ��
     * semi-planar��ʽ: stride[0]��ʾY�����п��, stride[1]��ʾCbCr�����п��
     * planar��ʽ:      stride[0]��ʾY�����п��, stride[1]��ʾCb�����п��, stride[2]��ʾCr�����п��
     */
    hi_u32 stride[DRV_GFX2D_MAX_SURFACE_NUM];
    hi_u32 size[DRV_GFX2D_MAX_SURFACE_NUM];
    /* <CNcomment:��ARGB����һ��alpha(����alphaֵ), �Ƿ�ΪԤ������, ��Ԥ��������Ԥ��, Ԥ�����ݲ���Ԥ��, ��GPU����һ�� */
    hi_bool premulti_en;
    drv_gfx2d_compress_msg compress_msg; /* <CNcomment:ѹ����Ϣ, ֻ��MEM����surface��Ч */
    hi_u64 histogram_phy_addr;           /* <CNcomment:ֱ��ͼ�����ַ, ֻ��MEM����surface��Ч, ��ʱû��ʹ��         */
    hi_mem_handle histogram_mem_handle;
    hi_u64 histogram_phy_addr_size;
    drv_gfx2d_compose_alpha_ext alpha_ext; /* <CNcomment:alpha��չ��Ϣ, ֻ��MEM����surface��ARGB1555��ʽ��Ч          */
    hi_u64 palette_phy_addr;               /* <CNcomment:��ɫ���ַ,ֻ��MEM����surface�ĵ�ɫ���ʽ��Ч, HWC�߼���֧�� */
    hi_mem_handle palette_mem_handle;
    hi_u32 palette_phy_addr_size;
    hi_s32 acquire_fence_fd;
    hi_s32 release_fence_fd;
    drv_gfx2d_compose_ext_info ext_info;
    drv_gfx2d_xdr_mode xdr_mode;
    drv_gfx2d_color_space color_space;
    hi_bool is_secure;
} drv_gfx2d_compose_surface;

/* structure of surface */
/* CNcomment:RGB��ʽcolorkey��Ϣ�ṹ�� */
typedef struct {
    hi_bool alpha_en;
    hi_bool alpha_out;
    hi_u8 alpha_min;
    hi_u8 alpha_max;
    hi_u8 alpha_mask;

    hi_bool red_en;
    hi_bool red_out;
    hi_u8 red_min;
    hi_u8 red_max;
    hi_u8 red_mask;

    hi_bool green_en;
    hi_bool green_out;
    hi_u8 green_min;
    hi_u8 green_max;
    hi_u8 green_mask;

    hi_bool blue_en;
    hi_bool blue_out;
    hi_u8 blue_min;
    hi_u8 blue_max;
    hi_u8 blue_mask;
} drv_gfx2d_compose_colorkey_rgb;

/* structure of surface */
/* CNcomment:clut��ʽ colorkey��Ϣ�ṹ�� */
typedef struct {
    hi_bool alpha_en;
    hi_bool alpha_out;
    hi_u8 alpha_min;
    hi_u8 alpha_max;
    hi_u8 alpha_mask;

    hi_bool clut_en;
    hi_bool clut_out;
    hi_u8 clut_min;
    hi_u8 clut_max;
    hi_u8 clut_mask;
} drv_gfx2d_compose_colorkey_clut;

typedef union {
    drv_gfx2d_compose_colorkey_rgb colorkey_rgb;
    drv_gfx2d_compose_colorkey_clut colorkey_clut;
} drv_gfx2d_compose_colorkey_type;

/* structure of color space */
/* CNcomment:��ɫ�ռ�ת����Ϣ�ṹ�� */
typedef struct {
    hi_bool user_para_en;       /* <CNcomment:�Ƿ�ʹ���û��Զ���ϵ�� */
    hi_u32 user_para_phy_addr;  /* <CNcomment:�û��Զ���ϵ�������ַ */
    hi_u32 user_para_addr_size; /* <CNcomment:�û��Զ���ϵ�������ַ��С */
} drv_gfx2d_compose_csc;

/* structure of filter info */
/* CNcomment:�˲���Ϣ�ṹ�� */
typedef struct {
    drv_gfx2d_compose_filter_mode filter_mode;
} drv_gfx2d_compose_filter;

/* structure of clip info */
/* CNcomment:��������Ϣ�ṹ�� */
typedef struct {
    drv_gfx2d_compose_clip_mode clip_mode; /* <CNcomment:����ģʽ */
    drv_gfx2d_compose_rect clip_rect;      /* <CNcomment:���о��� */
} drv_gfx2d_compose_clip;

/* structure of resize info */
/* CNcomment:������Ϣ�ṹ�� */
typedef struct {
    hi_bool resize_en;               /* <CNcomment:�Ƿ�ʹ������. */
    drv_gfx2d_compose_filter filter; /* <CNcomment:�˲���Ϣ.     */
} drv_gfx2d_compose_resize;

/* structure of alpha blend info */
/* CNcomment:������Ϣ�ṹ�� */
typedef struct {
    hi_bool cov_blend;      /* CNcomment: ��ǰ���Ƿ����һ��������, TRUE: ��������, ��ǰ��ֱ�Ӹ�����һ��, 6�����ϲ� * */
    hi_bool pixel_alpha_en; /* CNcomment: alpha�������ص�ķ�������     */
    hi_bool global_alpha_en; /* CNcomment: ȫ��alpha�������ص�ķ������� */
    hi_u8 global_alpha;      /* CNcomment: ȫ��alphaֵ. */
} drv_gfx2d_compose_blend;

/* structure of rop info */
/* CNcomment:rop��Ϣ�ṹ�� */
typedef struct {
    hi_bool enable;
    drv_gfx2d_compose_rop_mode alpha_rop_mode;
    drv_gfx2d_compose_rop_mode rgb_rop_mode;
} drv_gfx2d_compose_rop;

/* structure of key info */
/* CNcomment:colorkey��Ϣ�ṹ�� */
typedef struct {
    hi_bool enable;
    drv_gfx2d_compose_colorkey_type colorkey_type;
} drv_gfx2d_compose_colorkey;

typedef struct {
    hi_u32 holes_cnt;
    drv_gfx2d_compose_rect holes_rect[DRV_GFX2D_MAX_HOLES_NUM];
    hi_u32 argb;
} drv_gfx2d_compose_holes;

/* structure of operation info */
/* CNcomment:����ѡ����Ϣ�ṹ�� */
typedef struct {
    drv_gfx2d_compose_blend blend;       /* <CNcomment:alpha������Ϣ.                */
    drv_gfx2d_compose_resize resize;     /* <CNcomment:������Ϣ.                     */
    drv_gfx2d_compose_clip clip;         /* <CNcomment:��������Ϣ. HWC�߼����ڲ�֧�� */
    drv_gfx2d_compose_rop rop;           /* <CNcomment:ROP��Ϣ, HWC�߼����ڲ�֧��    */
    drv_gfx2d_compose_colorkey colorkey; /* <CNcomment:key��Ϣ, HWC�߼����ڲ�֧��    */
    drv_gfx2d_compose_holes holes;
} drv_gfx2d_compose_opt;

/* structure of composed surface and operation info */
/* CNcomment:������surface������ѡ��ṹ�� */
typedef struct {
    drv_gfx2d_compose_surface compose_surface; /* <CNcomment:surface��Ϣ.  */
    drv_gfx2d_compose_rect in_rect;            /* <CNcomment:�����������. */
    drv_gfx2d_compose_rect out_rect;           /* <CNcomment:�������.     */
    drv_gfx2d_compose_opt opt;                 /* <CNcomment:����ѡ��.     */
} drv_gfx2d_compose_msg;

/* composed surface list */
typedef struct {
    hi_u32 background_color;        /* <CNcomment: ���ӱ���ɫ, ���ֻ������һ������ɫ, �����, �����²� */
    hi_u32 compose_cnt;             /* <CNcomment: ���Ӳ���������, ��compose��С���Ӧ                  */
    drv_gfx2d_compose_msg *compose; /* <CNcomment: ���Ӳ�����, �������µ��ϵ�˳������, 0��������        */
    hi_u32 compose_size;            /* <CNcomment: composeָ���С                                      */
} drv_gfx2d_compose_list;

/* * @} */ /* ! <!-- Structure Definition end */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* _DRV_GFX2D_STRUCT_H_ */
