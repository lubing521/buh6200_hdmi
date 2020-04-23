/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2008-2019. All rights reserved.
 * Description: Define functions used to test function of frontend driver
 * Author: sdk
 * Create: 2008-06-05
 */

#ifndef __HI_DRV_FRONTEND_H__
#define __HI_DRV_FRONTEND_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define DRV_FRONTEND_NUM                (8)

#define HI_DRV_DISEQC_MSG_MAX_LENGTH     (6)   /** DiSEqC message length */  /** CNcomment:DiSEqC��Ϣ���� */
#define HI_DRV_DISEQC_MAX_REPEAT_TIMES   (4)   /** DiSEqC message max repeat times */ /** CNcomment:DiSEqC��Ϣ����ظ����ʹ��� */
#define HI_DRV_DISEQC_MAX_MOTOR_PISITION (255) /** DiSEqC motor max stored position */ /** CNcomment:DiSEqC������洢��λ�� */

#define HI_DRV_MAX_TS_LINE         (11)  /** The NO of ts lines that can be configured */ /** CNcomment:�����õ�ts�ź������� */

/*************************** Structure Definition ****************************/
/** \addtogroup      FRONTEND */
/** @{ */  /** <!-- [FRONTEND] */

/** Signal type of the frontend */
/** CNcomment:ǰ���ź����� */
typedef enum {
    HI_DRV_FRONTEND_SIG_TYPE_DVB_C   = 0x000001, /** <DVB-C signal */     /** <CNcomment:DVB_C�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_C2  = 0x000002, /** <DVB-C2 signal */    /** <CNcomment:DVB-C2�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ISDB_C  = 0x000004, /** <ISDB-C signal */    /** <CNcomment:ISDB-C�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_J83B    = 0x000008, /** <J83B signal */      /** <CNcomment:J83B�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_S   = 0x100001, /** <DVB-S signal */     /** <CNcomment:DVB-S2�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_S2  = 0x100002, /** <DVB-S2 signal */    /** <CNcomment:DVB-S2X�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_S2X = 0x100004, /** <DVB-S2X signal */   /** <CNcomment:�����ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ISDB_S  = 0x100008, /** <ISDB-S signal */    /** <CNcomment:ISDB-S�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ISDB_S3 = 0x100010, /** <ISDB-S3 signal */  /** <CNcomment:ISDB-S3�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ABSS    = 0x100020, /** <ABS-S signal */    /** <CNcomment: ֱ���������ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_T   = 0x200001, /** <DVB-T signal */    /** <CNcomment: DVB-T�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DVB_T2  = 0x200002, /** <DVB-T2 signal */   /** <CNcomment:DVB-T2�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ISDB_T  = 0x200004, /** <ISDB-T signal */   /** <CNcomment:ISDB-T�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ATSC_T  = 0x200008, /** <ATSC-T signal */   /** <CNcomment:ATSC-T�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_ATSC_T3 = 0x200010, /** <ATSC-T3 signal */  /** <CNcomment:ATSC-T3�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_DTMB    = 0x200020, /** <DTMB signal */     /** <CNcomment:DTMB�ź� */
    HI_DRV_FRONTEND_SIG_TYPE_MAX                 /** <Invalid value */    /** <CNcomment:�Ƿ�ֵ */
} hi_drv_frontend_sig_type;

/** type of TUNER device */
/** CNcomment:TUNER�豸���� */
typedef enum {
    HI_DRV_TUNER_DEV_TYPE_XG_3BL        = 0,    /** <XG_3BL,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_CD1616        = 1,    /** <CD1616,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_ALPS_TDAE     = 2,    /** <ALPS_TDAE,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_TDCC          = 3,    /** <TDCC,Not supported */       /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_TDA18250      = 4,    /** <TDA18250 */                 /** <CNcomment:֧��TDA18250��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_CD1616_DOUBLE = 5,    /** <CD1616 with double agc, Not supported */ /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_MT2081        = 6,    /** <MT2081,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_TMX7070X      = 7,    /** <THOMSON7070X, Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_R820C         = 8,    /** <R820C */                    /** <CNcomment:֧��R820C��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL203        = 9,    /** <MXL203 */                   /** <CNcomment:֧��MXL203��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_AV2011        = 10,   /** <AV2011 */                   /** <CNcomment:֧��AV2011��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_SHARP7903     = 11,   /** <SHARP7903,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_MXL101        = 12,   /** <MXL101,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_MXL603        = 13,   /** <MXL603 */                   /** <CNcomment:֧��MXL603��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_IT9170        = 14,   /** <IT9170,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_IT9133        = 15,   /** <IT9133,Not supported */     /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_TDA6651       = 16,   /** <TDA6651,Not supported */    /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_TDA18250B     = 17,   /** <TDA18250B */                /** <CNcomment:֧��TDA18250B��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_M88TS2022     = 18,   /** <M88TS2022,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_RDA5815       = 19,   /** <RDA5815 */                  /** <CNcomment:֧��RDA5815��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL254        = 20,   /** <MXL254 */                   /** <CNcomment:֧��MXL254��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_CXD2861       = 21,   /** <CXD2861,Not supported */    /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_SI2147        = 22,   /** <Si2147 */                   /** <CNcomment:֧��Si2147��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_RAFAEL836     = 23,   /** <Rafael836 */                /** <CNcomment:֧��Rafael836��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL608        = 24,   /** <MXL608 */                   /** <CNcomment:֧��MXL608��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL214        = 25,   /** <MXL214 */                   /** <CNcomment:֧��MXL214��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_TDA18280      = 26,   /** <TDA18280 */                 /** <CNcomment:֧��TDA18280��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_TDA182I5A     = 27,   /** <TDA182I5A */                /** <CNcomment:֧��TDA182I5AоƬ */
    HI_DRV_TUNER_DEV_TYPE_SI2144        = 28,   /** <Si2144 */                   /** <CNcomment:֧��Si2144оƬ */
    HI_DRV_TUNER_DEV_TYPE_AV2018        = 29,   /** <AV2018 */                   /** <CNcomment:֧��AV2018оƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL251        = 30,   /** <MXL251 */                   /** <CNcomment:֧��MXL251оƬ */
    HI_DRV_TUNER_DEV_TYPE_M88TC3800     = 31,   /** <M88TC3800,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_TUNER_DEV_TYPE_MXL601        = 32,   /** < MXL601 */                  /** <CNcomment:֧��MXL601��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL683        = 33,   /** <MXL683 */                   /** <CNcomment:֧��MXL683��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_AV2026        = 34,   /** <AV2026 */                   /** <CNcomment:֧��AV2026��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_R850          = 35,   /** <R850 */                     /** <CNcomment:֧��R850��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_R858          = 36,   /** <R858 */                     /** <CNcomment:֧��R858��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL541        = 37,   /** <MXL541 */                   /** <CNcomment:֧��MXL541��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL581        = 38,   /** <MXL581 */                   /** <CNcomment:֧��MXL581��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL582        = 39,   /** <MXL582 */                   /** <CNcomment:֧��MXL582��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MXL661        = 40,   /** <MXL661 */                   /** <CNcomment:֧��MXL661��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_RT720         = 41,   /** <RT720 */                    /** <CNcomment:֧��RT720��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_CXD2871       = 42,   /** <CXD2871 */                  /** <CNcomment:֧��CXD2871��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_SUT_PJ987     = 43,   /** <SUT-PJ987 */                /** <CNcomment:֧��SUT-PJ987��ƵоƬ */
    HI_DRV_TUNER_DEV_TYPE_MAX                   /** <Invalid value */            /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_tuner_dev_type;

/** Type of the demod device */
/** CNcomment:demod�豸���� */
typedef enum {
    HI_DRV_DEMOD_DEV_TYPE_NONE,                 /** <Not supported */             /** <CNcomment:��֧�� */
    HI_DRV_DEMOD_DEV_TYPE_3130I       = 0x100,  /** <Internal QAM, same as HI_DRV_DEMOD_DEV_TYPE_INTERNAL0 */
                                                /** <CNcomment:�ڲ�QAM,��HI_DRV_DEMOD_DEV_TYPE_INTERNAL0��ͬ */
    HI_DRV_DEMOD_DEV_TYPE_3130E       = 0x101,  /** <External Hi3130 */           /** <CNcomment:�ⲿQAM hi3130оƬ */
    HI_DRV_DEMOD_DEV_TYPE_J83B        = 0x102,  /** <suppoort j83b */             /** <CNcomment:֧��j83b */
    HI_DRV_DEMOD_DEV_TYPE_AVL6211     = 0x103,  /** <Avalink 6211 */              /** <CNcomment:֧��Avalink 6211 */
    HI_DRV_DEMOD_DEV_TYPE_MXL101      = 0x104,  /** <Maxlinear mxl101, Not supported */ /** <CNcomment:��֧�� */
    HI_DRV_DEMOD_DEV_TYPE_MN88472     = 0x105,  /** <PANASONIC mn88472 */         /** <CNcomment:֧��P mn88472 */
    HI_DRV_DEMOD_DEV_TYPE_IT9170      = 0x106,  /** <ITE it9170,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_DEMOD_DEV_TYPE_IT9133      = 0x107,  /** <ITE it9133,Not supported */  /** <CNcomment:��֧�� */
    HI_DRV_DEMOD_DEV_TYPE_3136        = 0x108,  /** <External Hi3136 */           /** <CNcomment:�ⲿhi3136оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL254      = 0x10A,  /** <External mxl254 */           /** <CNcomment:�ⲿMXL254оƬ */
    HI_DRV_DEMOD_DEV_TYPE_CXD2837     = 0x10B,  /** <Sony cxd2837,Not supported */   /** <CNcomment:��֧�� */
    HI_DRV_DEMOD_DEV_TYPE_3137        = 0x10C,  /** <External Hi3137 */           /** <CNcomment:֧���ⲿhi3137оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL214      = 0x10D,  /** <External mxl214 */           /** <CNcomment:�ⲿMXL214оƬ */
    HI_DRV_DEMOD_DEV_TYPE_TDA18280    = 0x10E,  /** <External tda18280 */         /** <CNcomment:�ⲿtda18280оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL251      = 0x111,  /** <External mxl251 */           /** <CNcomment:�ⲿMXL251оƬ */
    HI_DRV_DEMOD_DEV_TYPE_ATBM888X    = 0x113,  /** <External ATBM888X */         /** <CNcomment:֧���ⲿATBM888XоƬ */
    HI_DRV_DEMOD_DEV_TYPE_MN88473     = 0x114,  /** <Panasonic 88473 */           /** <CNcomment:֧��Panasonic 88473 */
    HI_DRV_DEMOD_DEV_TYPE_MXL683      = 0x115,  /** <External mxl683 */           /** <CNcomment:�ⲿmxl683оƬ */
    HI_DRV_DEMOD_DEV_TYPE_TP5001      = 0x116,  /** <External TP5001 */           /** <CNcomment:֧���ⲿTP5001оƬ */
    HI_DRV_DEMOD_DEV_TYPE_HD2501      = 0x117,  /** <External HD2501 */           /** <CNcomment:֧���ⲿHD2501оƬ */
    HI_DRV_DEMOD_DEV_TYPE_AVL6381     = 0x118,  /** <External AVL6381 */          /** <CNcomment:֧���ⲿAVL6381оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL541      = 0x119,  /** <External MXL541 */           /** <CNcomment:֧���ⲿMXL541оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL581      = 0x11A,  /** <External MXL581 */           /** <CNcomment:֧���ⲿMXL581оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MXL582      = 0x11B,  /** <External MXL582 */           /** <CNcomment:֧���ⲿMXL582оƬ */
    HI_DRV_DEMOD_DEV_TYPE_INTERNAL0   = 0x11C,  /** <Internal Demod */            /** <CNcomment:֧���ڲ����оƬ */
    HI_DRV_DEMOD_DEV_TYPE_CXD2856     = 0x11D,  /** <External CXD2856 */          /** <CNcomment:֧���ⲿCXD2856оƬ */
    HI_DRV_DEMOD_DEV_TYPE_CXD2857     = 0x11E,  /** <External CXD2857 */          /** <CNcomment:֧���ⲿCXD2857оƬ */
    HI_DRV_DEMOD_DEV_TYPE_CXD2878     = 0x11F,  /** <External CXD2878 */          /** <CNcomment:֧���ⲿCXD2878оƬ */
    HI_DRV_DEMOD_DEV_TYPE_MAX                   /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_demod_dev_type;

/** frontend attribution. */
/** CNcomment:ǰ������ */
typedef struct {
    hi_drv_frontend_sig_type  sig_type;          /** <Signal type */       /** <CNcomment:�ź����� */
    hi_drv_demod_dev_type     demod_dev_type;    /** <QAM type */          /** <CNcomment:QAM���� */
    hi_u32      demod_addr;        /* <The i2c address of demod */
    hi_u16      demod_clk;         /* <Demod clock freqency, unit:kHz */
    hi_u16      demod_i2c_channel; /** <I2C channel used by the demod */ /** <CNcomment:DEMODʹ�õ�I2Cͨ�� */
    hi_u16      ext_dem_reset_gpio_group; /** <Demod reset GPIO group NO. */ /** <CNcomment:��λʹ�õ�gpio�ܽ���� */
    hi_u16      ext_dem_reset_gpio_bit;   /** <Demod reset GPIO bit NO. */ /** <CNcomment:��λʹ�õ�gpio�ܽź� */
    hi_drv_tuner_dev_type     tuner_dev_type;    /** <Tuner type */        /** <CNcomment:TUNER���� */
    hi_u32      tuner_addr;        /* The i2c address of tuner */
    hi_u16      tuner_i2c_channel; /** <I2C channel used by the tuner */ /** <CNcomment:TUNERʹ�õ�I2Cͨ�� */

    /** <Only valid in Hi3716MV430 DVBT2, 0 is low memory mode, 1 is high memory mode.
         Low memory mode default,COMMON PLP is not supported in this mode. */
    /** <CNcomment: ����Hi3716MV430��DVB-T2��Ч�� 0��ʾ���ڴ�ģʽ��1��ʾ���ڴ�ģʽ��Ĭ��Ϊ���ڴ�ģʽ����ģʽ��֧��COMMON PLP */
    hi_u32                    memory_mode;
    hi_u8                     reserved[20];      /** <Reserved 20 byte for future use */  /* <CNcommit:����20�ֽ�δ��ʹ�� */
} hi_drv_frontend_attr;

/** Modulation mode */
/** CNcomment: ���Ʒ�ʽ */
typedef enum {
    HI_DRV_MOD_TYPE_DEFAULT,     /** <Default QAM mode. The default QAM mode is HI_DRV_MOD_TYPE_QAM_64 at present. */
                                 /** <CNcomment:Ĭ�ϵ�QAM����, ��ǰϵͳĬ��ΪHI_DRV_MOD_TYPE_QAM_64 */
    HI_DRV_MOD_TYPE_QAM_16 = 0x100,   /** <16QAM mode */          /** <CNcomment:16QAM��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QAM_32,           /** <32QAM mode */          /** <CNcomment:32QAM��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QAM_64,           /** <64QAM mode */          /** <CNcomment:64QAM��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QAM_128,          /** <128QAM mode */         /** <CNcomment:128QAM��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QAM_256,          /** <256QAM mode */         /** <CNcomment:256QAM��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QAM_512,          /** <512QAM mode */         /** <CNcomment:512QAM��Ӧ��ö��ֵ */

    HI_DRV_MOD_TYPE_BPSK = 0x200,     /** <binary phase shift keying (BPSK) mode. */     /** <CNcomment:BPSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_QPSK = 0x300,     /** <quaternary phase shift keying (QPSK) mode. */ /** <CNcomment:QPSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_DQPSK,
    HI_DRV_MOD_TYPE_8PSK,             /** <8 phase shift keying (8PSK) mode */           /** <CNcomment:8PSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_16APSK,           /** <16-Ary Amplitude and Phase Shift Keying (16APSK) mode */
                                      /** <CNcomment:16APSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_32APSK,           /** <32-Ary Amplitude and Phase Shift Keying (32APSK) mode */
                                      /** <CNcomment:32APSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_64APSK,           /** <64-Ary Amplitude and Phase Shift Keying (64APSK) mode */
                                      /** <CNcomment:64APSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_128APSK,          /** <128-Ary Amplitude and Phase Shift Keying (128APSK) mode */
                                      /** <CNcomment:128APSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_256APSK,          /** <256-Ary Amplitude and Phase Shift Keying (256APSK) mode */
                                      /** <CNcomment:256APSK��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_8VSB,             /** <(8VSB) mode */           /** <CNcomment:8VSB��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_16VSB,            /** <(16VSB) mode */          /** <CNcomment:16VSB��Ӧ��ö��ֵ */
    HI_DRV_MOD_TYPE_VLSNR_SET1,       /** <(VLSNR_SET1) mode,only used in DVB-S2X */
                                      /** <CNcomment:VLSNR_SET1��Ӧ��ö��ֵ��DVB-S2X���� */
    HI_DRV_MOD_TYPE_VLSNR_SET2,       /** <(VLSNR_SET2) mode,only used in DVB-S2X */
                                      /** <CNcomment:VLSNR_SET2��Ӧ��ö��ֵ��DVB-S2X���� */
    HI_DRV_MOD_TYPE_8APSK,    /** <(8APSK) mode,only used in DVB-S2x */  /** <CNcomment:8APSK��Ӧ��ö��ֵ��DVB-S2X���� */

    /** <Enumeration corresponding to the auto mode. For DVB-S/S2,
         if detect modulation type fail, it will return auto */
    /** <CNcomment:�����źŵ��Ʒ�ʽ�Զ���⣬������ʧ�ܷ���AUTO */
    HI_DRV_MOD_TYPE_AUTO,

    HI_DRV_MOD_TYPE_MAX              /** <Invalid Modulation mode */       /** <CNcomment:�Ƿ��ĵ�������ö��ֵ */
} hi_drv_modulation_type;

/** FEC code Rate */
/** CNcomment:FEC���� */
typedef enum {
    HI_DRV_FRONTEND_FEC_RATE_AUTO = 0,
    HI_DRV_FRONTEND_FEC_RATE_1_2,           /** <1/2 */           /** <CNcomment:1/2���� */
    HI_DRV_FRONTEND_FEC_RATE_2_3,           /** <2/3 */           /** <CNcomment:2/3���� */
    HI_DRV_FRONTEND_FEC_RATE_3_4,           /** <3/4 */           /** <CNcomment:3/4���� */
    HI_DRV_FRONTEND_FEC_RATE_4_5,           /** <4/5 */           /** <CNcomment:4/5���� */
    HI_DRV_FRONTEND_FEC_RATE_5_6,           /** <5/6 */           /** <CNcomment:5/6���� */
    HI_DRV_FRONTEND_FEC_RATE_6_7,           /** <6/7 */           /** <CNcomment:6/7���� */
    HI_DRV_FRONTEND_FEC_RATE_7_8,           /** <7/8 */           /** <CNcomment:7/8���� */
    HI_DRV_FRONTEND_FEC_RATE_8_9,           /** <8/9 */           /** <CNcomment:8/9���� */
    HI_DRV_FRONTEND_FEC_RATE_9_10,          /** <9/10 */          /** <CNcomment:9/10���� */
    HI_DRV_FRONTEND_FEC_RATE_1_4,           /** <1/4 */           /** <CNcomment:1/4���� */
    HI_DRV_FRONTEND_FEC_RATE_1_3,           /** <1/3 */           /** <CNcomment:1/3���� */
    HI_DRV_FRONTEND_FEC_RATE_2_5,           /** <2/5 */           /** <CNcomment:2/5���� */
    HI_DRV_FRONTEND_FEC_RATE_3_5,           /** <3/5 */           /** <CNcomment:3/5���� */
    HI_DRV_FRONTEND_FEC_RATE_13_45,         /** <13/45 */         /** <CNcomment:13/45���� */
    HI_DRV_FRONTEND_FEC_RATE_9_20,          /** <9/20 */          /** <CNcomment:9/20���� */
    HI_DRV_FRONTEND_FEC_RATE_11_20,         /** <11/20 */         /** <CNcomment:11/20���� */
    HI_DRV_FRONTEND_FEC_RATE_5_9_L,         /** <5/9L */          /** <CNcomment:5/9L���� */
    HI_DRV_FRONTEND_FEC_RATE_26_45_L,       /** <26/45L */        /** <CNcomment:26/45L���� */
    HI_DRV_FRONTEND_FEC_RATE_23_36,         /** <23/36 */         /** <CNcomment:23/36���� */
    HI_DRV_FRONTEND_FEC_RATE_25_36,         /** <25/36 */         /** <CNcomment:25/36���� */
    HI_DRV_FRONTEND_FEC_RATE_13_18,         /** <13/18 */         /** <CNcomment:13/18���� */
    HI_DRV_FRONTEND_FEC_RATE_1_2_L,         /** <1/2L */          /** <CNcomment:1/2L���� */
    HI_DRV_FRONTEND_FEC_RATE_8_15_L,        /** <8/15L */         /** <CNcomment:8/15L���� */
    HI_DRV_FRONTEND_FEC_RATE_26_45,         /** <26/45 */         /** <CNcomment:26/45���� */
    HI_DRV_FRONTEND_FEC_RATE_3_5_L,         /** <3/5L */          /** <CNcomment:3/5L���� */
    HI_DRV_FRONTEND_FEC_RATE_28_45,         /** <28/45 */         /** <CNcomment:28/45���� */
    HI_DRV_FRONTEND_FEC_RATE_2_3_L,         /** <2/3L */          /** <CNcomment:2/3L���� */
    HI_DRV_FRONTEND_FEC_RATE_7_9,           /** <7/9 */           /** <CNcomment:7/9���� */
    HI_DRV_FRONTEND_FEC_RATE_77_90,         /** <77/90 */         /** <CNcomment:77/90���� */
    HI_DRV_FRONTEND_FEC_RATE_32_45,         /** <32/45 */         /** <CNcomment:32/45���� */
    HI_DRV_FRONTEND_FEC_RATE_11_15,         /** <11/15 */         /** <CNcomment:11/15���� */
    HI_DRV_FRONTEND_FEC_RATE_32_45_L,       /** <32/45 */         /** <CNcomment:32/45L���� */
    HI_DRV_FRONTEND_FEC_RATE_29_45_L,       /** <29/45L */        /** <CNcomment:29/45L���� */
    HI_DRV_FRONTEND_FEC_RATE_31_45_L,       /** <31/45 */         /** <CNcomment:31/45L���� */
    HI_DRV_FRONTEND_FEC_RATE_11_15_L,       /** <11/15L */        /** <CNcomment:11/15L���� */
    HI_DRV_FRONTEND_FEC_RATE_11_45,         /** <11/45 */         /** <CNcomment:11/45���� */
    HI_DRV_FRONTEND_FEC_RATE_4_15,          /** <4/15 */          /** <CNcomment:4/15���� */
    HI_DRV_FRONTEND_FEC_RATE_14_45,         /** <14/45 */         /** <CNcomment:14/45���� */
    HI_DRV_FRONTEND_FEC_RATE_7_15,          /** <7/15 */          /** <CNcomment:7/15���� */
    HI_DRV_FRONTEND_FEC_RATE_8_15,          /** <8/15 */          /** <CNcomment:8/15���� */
    HI_DRV_FRONTEND_FEC_RATE_2_9,           /** <2/9 */           /** <CNcomment:2/9���� */
    HI_DRV_FRONTEND_FEC_RATE_1_5,           /** <2/9 */           /** <CNcomment:2/9���� */
    HI_DRV_FRONTEND_FEC_RATE_MAX       /** <Invalid value */ /** <CNcomment:�Ƿ��߽�ֵ */
}  hi_drv_frontend_fec_rate;

/** Demod ADC port select */
/** CNcomment:Demod ADC�˿�ѡ�� */
typedef enum {
    HI_DRV_DEMOD_ADC_0,          /** <ADC0 */   /** <CNcomment:ADC0�˿� */
    HI_DRV_DEMOD_ADC_1,          /** <ADC1 */   /** <CNcomment:ADC1�˿� */
    HI_DRV_DEMOD_ADC_MAX
} hi_drv_demod_adc;

/** Tuner RF AGC mode */
/** CNcomment:agc����ģʽ */
typedef enum {
    /** < Inverted polarization, default.This setting is used for a tuner whose
          gain decreases with increased AGC voltage */
    /** <CNcomment:agc�������ģʽ */
    HI_DRV_TUNER_RF_AGC_MODE_INVERT,

    /** < Normal polarization. This setting is used for a tuner whose gain increases with increased AGC voltage */
    /** <CNcomment:agc�������ģʽ */
    HI_DRV_TUNER_RF_AGC_MODE_NORMAL,
    HI_DRV_TUNER_RF_AGC_MODE_MAX          /** <Invalid value */    /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_tuner_rf_agc_mode;

/** Tuner IQ spectrum mode */
/** CNcomment:IQģʽ */
typedef enum {
    HI_DRV_TUNER_IQ_SPECTRUM_MODE_NORMAL, /** <The received signal spectrum is not inverted */ /** <CNcomment:IQ����ת */
    HI_DRV_TUNER_IQ_SPECTRUM_MODE_INVERT, /** <The received signal spectrum is inverted */     /** <CNcomment:IQ��ת */
    HI_DRV_TUNER_IQ_SPECTRUM_MODE_MAX     /** <Invalid value */                           /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_tuner_iq_spectrum_mode;

/** Output mode of the demod */
/** CNcomment:Demod���ģʽ */
typedef enum {
    HI_DRV_DEMOD_TS_MODE_DEFAULT               = 0,   /** <Default mode */
                                                             /** <CNcomment:Ĭ��ģʽ */
    HI_DRV_DEMOD_TS_MODE_PARALLEL_MODE_A       = 1,   /** <Parallel mode A */
                                                             /** <CNcomment:����ģʽA */
    HI_DRV_DEMOD_TS_MODE_PARALLEL_MODE_B       = 2,   /** <Parallel mode B */
                                                             /** <CNcomment:����ģʽB */
    HI_DRV_DEMOD_TS_MODE_SERIAL                = 3,   /** <Serial mode 74.25M */
                                                             /** <CNcomment:����ģ74.25M */
    HI_DRV_DEMOD_TS_MODE_SERIAL_50             = 4,   /** <Serial mode 50M */
                                                             /** <CNcomment:����ģ50M */
    HI_DRV_DEMOD_TS_MODE_SERIAL_2BIT           = 5,   /** <Serial mode witch 2 bit data line */
                                                             /** <CNcomment:2bit���� */
    HI_DRV_DEMOD_TS_MODE_FULLBAND_PARALLEL     = 6,   /** <FULLBAND Parallel mode */
                                                             /** <CNcomment:FULLBAND ����ģʽ */
    HI_DRV_DEMOD_TS_MODE_FULLBAND_SERIAL_3WIRE = 7,   /** <FULLBAND SERIAL three wire mode */
                                                             /** <CNcomment:FULLBAND ��������ģʽ */
    HI_DRV_DEMOD_TS_MODE_FULLBAND_SERIAL_4WIRE = 8,   /** <FULLBAND SERIAL four wire mode */
                                                             /** <CNcomment:FULLBAND ��������ģʽ */
    HI_DRV_DEMOD_TS_MODE_MAX  /** <Invalid value */  /** <CNcomment:�Ƿ�ֵ */
} hi_drv_demod_ts_mode;

/** TS sync head length */
/** CNcomment: TS sync ͷ���� */
typedef enum {
    HI_DRV_DEMOD_TS_SYNC_HEAD_AUTO,
    HI_DRV_DEMOD_TS_SYNC_HEAD_8BIT,
    HI_DRV_DEMOD_TS_SYNC_HEAD_MAX
} hi_drv_demod_ts_sync_head;

/** TS clock polarization */
/** CNcomment:TSʱ�Ӽ��� */
typedef enum {
    HI_DRV_DEMOD_TS_CLK_POLAR_FALLING,       /** <Falling edge */      /** <CNcomment:�½��� */
    HI_DRV_DEMOD_TS_CLK_POLAR_RISING,        /** <Rising edge */       /** <CNcomment:������ */
    HI_DRV_DEMOD_TS_CLK_POLAR_MAX           /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_demod_ts_clk_polar;

/** TS clock edge mode */
/** CNcomment:TSʱ�ӱ���ģʽ */
typedef enum {
    HI_DRV_DEMOD_TSCLK_EDGE_SINGLE,     /** <signal edge */       /** <CNcomment:���� */
    HI_DRV_DEMOD_TSCLK_EDGE_DOUBLE,     /** <double edge */       /** <CNcomment:˫�� */
    HI_DRV_DEMOD_TSCLK_EDGE_MAX        /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_demod_ts_clk_edge;

/** TS format */
/** CNcomment:TS��ʽ */
typedef enum {
    HI_DRV_DEMOD_TS_FORMAT_TS,              /** <188 */               /** <CNcomment:188�ֽڸ�ʽ */
    HI_DRV_DEMOD_TS_FORMAT_TSP,             /** <204 */               /** <CNcomment:204�ֽڸ�ʽ */
    HI_DRV_DEMOD_TS_FORMAT_MAX             /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_demod_ts_format;

/** TS Output order */
/** CNcomment:TS������� */
typedef enum {
    HI_DRV_DEMOD_TS_PIN_DAT0,        /** <data0 */                       /** <CNcomment:������0bit */
    HI_DRV_DEMOD_TS_PIN_DAT1,        /** <data1 */                       /** <CNcomment:������1bit */
    HI_DRV_DEMOD_TS_PIN_DAT2,        /** <data2 */                       /** <CNcomment:������2bit */
    HI_DRV_DEMOD_TS_PIN_DAT3,        /** <data3 */                       /** <CNcomment:������3bit */
    HI_DRV_DEMOD_TS_PIN_DAT4,        /** <data4 */                       /** <CNcomment:������4bit */
    HI_DRV_DEMOD_TS_PIN_DAT5,        /** <data5 */                       /** <CNcomment:������5bit */
    HI_DRV_DEMOD_TS_PIN_DAT6,        /** <data6 */                       /** <CNcomment:������6bit */
    HI_DRV_DEMOD_TS_PIN_DAT7,        /** <data7 */                       /** <CNcomment:������7bit */
    HI_DRV_DEMOD_TS_PIN_SYNC,        /** <sync */                        /** <CNcomment:sync�ź��� */
    HI_DRV_DEMOD_TS_PIN_VLD,         /** <valid */                       /** <CNcomment:valid�ź��� */
    HI_DRV_DEMOD_TS_PIN_ERR,         /** <err */                         /** <CNcomment:err�ź��� */
    HI_DRV_DEMOD_TS_PIN_MAX          /** <Invalid value */               /** <CNcomment:�Ƿ�ֵ */
} hi_drv_demod_ts_pin;

/** ts output port order */
/** CNcomment:ts�ӿ�������� */
typedef struct {
    hi_drv_demod_ts_mode       ts_mode;   /** <Output mode of transport streams (TSs) */
                                               /** <CNcomment:TS�����ģʽ */
    hi_drv_demod_ts_clk_polar  ts_clk_polar;  /** <TS clock polar */     /** <TS ʱ�Ӽ��� */
    hi_drv_demod_ts_clk_edge   ts_clk_edge;   /** <TS clock edge mode */ /** <TS ʱ�ӱ���ģʽ */
    hi_drv_demod_ts_format     ts_format;     /** <TS format */          /** <TS ��ʽ */
    hi_drv_demod_ts_pin        ts_pin[HI_DRV_MAX_TS_LINE];  /** <ts output port order */    /** <CNcomment:ts�ӿ�������� */
} hi_drv_demod_ts_out;

/** Frequency locking status of the tuner */
/** CNcomment:�ź���Ƶ״̬ */
typedef enum {
    HI_DRV_FRONTEND_LOCK_STATUS_DROPPED = 0,       /** <The signal is not locked. */  /** <CNcomment:�ź�δ���� */
    HI_DRV_FRONTEND_LOCK_STATUS_LOCKED,            /** <The signal is locked. */      /** <CNcomment:�ź������� */
    HI_DRV_FRONTEND_LOCK_STATUS_MAX               /** <Invalid value */              /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_lock_status;

typedef enum {
    HI_DRV_FRONTEND_STREAM_ID_TYPE_STREAM_ID = 0,          /** <Stream ID */     /** <CNcomment:��ID */
    HI_DRV_FRONTEND_STREAM_ID_TYPE_RELATIVE_STREAM_INDEX, /** <Relative stream number */ /** <CNcomment:����������� */
    HI_DRV_FRONTEND_STREAM_ID_TYPE_MAX                   /** <Invalid value */  /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_stream_id_type;


/** BER and PER expressed scientific notation */
/** CNcomment:�����ʺ�����ʣ���ѧ��������ʾ */
typedef struct {
    hi_u16 integer_val;  /** <Integer part */                    /** <CNcomment:�������� */
    hi_u16 decimal_val;  /** <Decimal part multiplied by 1000 */ /** <CNcomment:С�����ֳ���1000 */
    hi_s32 power;        /** <power value */                     /** <CNcomment:ָ������ */
} hi_drv_frontend_scientific_num;

/** SNR interger part and decimar part multiplied by 100 */
/** CNcomment: ������������ֺ�С�����ֳ���100 */
typedef struct {
    hi_s16 integer_val;  /** <Integer part */                   /** <CNcomment:�������� */
    hi_s16 decimal_val;  /** <Decimal part multiplied by 100 */ /** <CNcomment:С�����ֳ���100 */
} hi_drv_frontend_integer_decimal;

/** Sample data, complex format */
/** CNcomment: �ɼ�����, ����ʽ */
typedef struct {
    hi_s32 data_ip;   /* sample data, i component */    /** <CNcomment:�ɼ����ݵ�I���� */
    hi_s32 data_qp;   /* sample data, q component */    /** <CNcomment:�ɼ����ݵ�Q���� */
} hi_drv_frontend_sample_data;

/** Sample data length */
/** CNcomment: �������� */
typedef enum {
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_32,         /** <sample 32 pts */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_64,         /** <sample 64 pts */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_128,        /** <sample 128 pts */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_256,        /** <sample 256 pts */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_512,        /** <sample 512 pts */  /** <CNcomment:�ɼ�512�� */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_1024,       /** <sample 1024 pts */ /** <CNcomment:�ɼ�1024�� */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_2048,       /** <sample 2048 pts */ /** <CNcomment:�ɼ�2048�� */
    HI_DRV_FRONTEND_SAMPLE_DATA_LEN_MAX        /** <Invalid value */   /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_sample_data_len;

/** Tuner spectrum parameters */
/** CNcomment: Tuner Ƶ�ײ��� */
typedef struct {
    hi_u32  freq_start_in_hz;    /** <start frequency */   /** <CNcomment:��ʼƵ�� */
    hi_u32  freq_step_in_hz;     /** <step frequency */    /** <CNcomment:����Ƶ�� */
    hi_u32  num_of_freq_steps;   /** <number of steps */   /** <CNcomment:Ƶ�׵��� */
    hi_s16* power_data;          /** <spectrum data */     /** <CNcomment:Ƶ������ */
} hi_drv_tuner_spectrum_para;

/** Defines the cable transmission signal. */
/** CNcomment:����CABLE�����ź� */
typedef struct {
    hi_u32                  freq;            /** <Frequency, in kHz */         /** <CNcomment:Ƶ�ʣ���λ��kHz */
    hi_u32                  symbol_rate;     /** <Symbol rate, in bit/s */     /** <CNcomment:�����ʣ���λbps */
    hi_drv_modulation_type  mod_type;        /** <QAM mode */                  /** <CNcomment:QAM���Ʒ�ʽ */
    hi_bool                 reverse;         /** <Spectrum reverse mode */     /** <CNcomment:Ƶ�׵��ô���ʽ */
    hi_u32                  band_width;      /** <bandwidth in KHz */          /** <CNcomment:������λkHz */
} hi_drv_cab_connect_para;

/** Guard interval of OFDM */
/** CNcomment:���ز������µı������ */
typedef enum {
    HI_DRV_FRONTEND_GUARD_INTV_DEFALUT = 0,     /** <default guard interval mode */   /** <CNcomment:�������Ĭ��ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_1_128,           /** <1/128 */                         /** <CNcomment:�������1/128ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_1_32,            /** <1/32 */                          /** <CNcomment:�������1/32ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_1_16,            /** <1/16 */                          /** <CNcomment:�������1/16ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_1_8,             /** <1/8 */                           /** <CNcomment:�������1/8ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_1_4,             /** <1/4 */                           /** <CNcomment:�������1/4ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_19_128,          /** <19/128 */                        /** <CNcomment:�������19/128ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_19_256,          /** <19/256 */                        /** <CNcomment:�������19/256ģʽ */
    HI_DRV_FRONTEND_GUARD_INTV_MAX             /** <Invalid value */                 /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_guard_intv;

/** OFDM Mode, used in multi-carrier modulation */
/** CNcomment:OFDMģʽ�����ڶ��ز�����ģʽ�� */
typedef enum {
    HI_DRV_FRONTEND_FFT_DEFAULT = 0,   /** <default mode */     /** <CNcomment:Ĭ��ģʽ */
    HI_DRV_FRONTEND_FFT_1K,            /** <1k mode */          /** <CNcomment:1kģʽ */
    HI_DRV_FRONTEND_FFT_2K,            /** <2k mode */          /** <CNcomment:2kģʽ */
    HI_DRV_FRONTEND_FFT_4K,            /** <4k mode */          /** <CNcomment:4kģʽ */
    HI_DRV_FRONTEND_FFT_8K,            /** <8k mode */          /** <CNcomment:8kģʽ */
    HI_DRV_FRONTEND_FFT_16K,           /** <16k mode */         /** <CNcomment:16kģʽ */
    HI_DRV_FRONTEND_FFT_32K,           /** <32k mode */         /** <CNcomment:32kģʽ */
    HI_DRV_FRONTEND_FFT_64K,           /** <64k mode */         /** <CNcomment:64kģʽ */
    HI_DRV_FRONTEND_FFT_MAX           /** <Invalid value */    /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_fft;

/** TS Priority, only used in DVB-T */
/** CNcomment:������DVB-T */
typedef enum {
    HI_DRV_FRONTEND_DVBT_TS_PRIORITY_NONE = 0,      /** <no priority mode */          /** <CNcomment:�����ȼ�ģʽ */
    HI_DRV_FRONTEND_DVBT_TS_PRIORITY_HP,            /** <high priority mode */        /** <CNcomment:�����ȼ�ģʽ */
    HI_DRV_FRONTEND_DVBT_TS_PRIORITY_LP,            /** <low priority mode */         /** <CNcomment:�����ȼ�ģʽ */
    HI_DRV_FRONTEND_DVBT_TS_PRIORITY_MAX           /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt_ts_priority;

/** Hierarchical modulation mode, only used in DVB-T */
/** CNcomment:������DVB-T */
typedef enum {
    HI_DRV_FRONTEND_DVBT_HIERARCHY_DEFAULT = 0, /** <hierarchical modulation default mode */ /** <CNcomment:Ĭ��ģʽ */
    HI_DRV_FRONTEND_DVBT_HIERARCHY_NO,      /** <no hierarchical modulation mode */ /** <CNcomment:���ּ���ģʽ */
    HI_DRV_FRONTEND_DVBT_HIERARCHY_ALHPA1,  /** <hierarchical mode, alpha = 1 */    /** <CNcomment:�ּ���ģʽ, alpha = 1 */
    HI_DRV_FRONTEND_DVBT_HIERARCHY_ALHPA2,  /** <hierarchical mode, alpha = 2 */    /** <CNcomment:�ּ���ģʽ, alpha = 2 */
    HI_DRV_FRONTEND_DVBT_HIERARCHY_ALHPA4,  /** <hierarchical mode, alpha = 4 */    /** <CNcomment:�ּ���ģʽ, alpha = 4 */
    HI_DRV_FRONTEND_DVBT_HIERARCHY_MAX     /** <Invalid value */                   /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt_hierarchy;

/** base channel or lite channel, only used in DVB-T2 */
/** CNcomment:������DVB-T2 */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_MODE_BASE = 0,     /** < the channel is base mode */  /** <CNcomment:ͨ���н�֧��base�ź� */
    HI_DRV_FRONTEND_DVBT2_MODE_LITE,         /** < the channel is lite mode */  /** <CNcomment:ͨ������Ҫ֧��lite�ź� */
    HI_DRV_FRONTEND_DVBT2_MODE_MAX          /** <Invalid value */              /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_mode;

/** pilot pattern */
/** CNcomment:��Ƶģʽ */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP1 = 0,  /** < pilot pattern pp1 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP2,      /** < pilot pattern pp2 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP3,      /** < pilot pattern pp3 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP4,      /** < pilot pattern pp4 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP5,      /** < pilot pattern pp5 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP6,      /** < pilot pattern pp6 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP7,      /** < pilot pattern pp7 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_PP8,      /** < pilot pattern pp8 */
    HI_DRV_FRONTEND_DVBT2_PILOT_PATTERN_MAX
} hi_drv_frontend_dvbt2_pilot_pattern;

/** information for carrier mode */
/** CNcomment:�ز�ģʽ��Ϣ */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_CARRIER_EXTEND = 0,    /** < extend carrier */   /** <CNcomment:��չ�ز� */
    HI_DRV_FRONTEND_DVBT2_CARRIER_NORMAL,        /** < normal carrier */   /** <CNcomment:�����ز� */
    HI_DRV_FRONTEND_DVBT2_CARRIER_MAX      /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_carrier;

/** information for constellation mode */
/** CNcomment:�����Ƿ���ת */
typedef enum {
    HI_DRV_FRONTEND_CONSTELLATION_STANDARD = 0,    /** < standard constellation */   /** <CNcomment:����ת���� */
    HI_DRV_FRONTEND_CONSTELLATION_ROTATION,        /** < rotation constellation */   /** <CNcomment:��ת���� */
    HI_DRV_FRONTEND_CONSTELLATION_MAX        /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_constellation;

/** FEC frame length */
/** CNcomment:FEC֡�� */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_FEC_FRAME_NORMAL = 0,      /** < normal fec frame */ /** <CNcomment:��ͨ���ȵ�fec֡ */
    HI_DRV_FRONTEND_DVBT2_FEC_FRAME_SHORT,           /** < short fec frame */  /** <CNcomment:fec��֡ */
    HI_DRV_FRONTEND_DVBT2_FEC_FRAME_MAX        /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_fec_frame;

/** DVB-T2 data PLP's ISSY type */
/** CNcomment:������DVB-T2 */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_ISSY_NO = 0,   /** < No Input Stream SYnchronizer */        /** <CNcomment:��ISSY */
    HI_DRV_FRONTEND_DVBT2_ISSY_SHORT,    /** < Short Input Stream SYnchronizer */     /** <CNcomment:��ISSY */
    HI_DRV_FRONTEND_DVBT2_ISSY_LONG,     /** < Long Input Stream SYnchronizer */      /** <CNcomment:��ISSY */
    HI_DRV_FRONTEND_DVBT2_ISSY_MAX      /** < Invalid value */                       /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_issy;

/** Stream type */
/** CNcomment:������ */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_GFPS = 0, /** < Generic Fixed Packet size Stream */ /** <CNcomment:ͨ�ù̶����������� */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_GCS,      /** < Generic Continuous Stream */        /** <CNcomment:ͨ������������ */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_GSE,      /** < Generic Stream Encapsulated */      /** <CNcomment:GSE������ */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_TS,       /** < Trasport Stream */                  /** <CNcomment:TS������ */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_GSE_HEM,  /** < GSE in High Efficiency Mode */      /** <CNcomment:GSE��HEMģʽ */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_TS_HEM,   /** < TS in High Efficiency Mode */       /** <CNcomment:TS��HEMģʽ */
    HI_DRV_FRONTEND_DVBT2_STREAM_TYPE_MAX      /** < Invalid value */                    /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_stream_type;

/** PLP type of DVB-T2. */
/** CNcomment:T2�������ܵ����� */
typedef enum {
    HI_DRV_FRONTEND_DVBT2_PLP_TYPE_COM = 0,       /** <common type */              /** <CNcomment:��ͨ */
    HI_DRV_FRONTEND_DVBT2_PLP_TYPE_DAT1,          /** <data1 type */               /** <CNcomment:����1 */
    HI_DRV_FRONTEND_DVBT2_PLP_TYPE_DAT2,          /** <data2 type */               /** <CNcomment:����2 */
    HI_DRV_FRONTEND_DVBT2_PLP_TYPE_MAX           /** <Invalid value */            /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_dvbt2_plp_type;

/** Antenna power control */
/** CNcomment:���߹������ */
typedef enum {
    HI_DRV_FRONTEND_TER_ANTENNA_POWER_OFF,     /** <Antenna power off */          /** <CNcomment:���ߵ�Դ�ض� */
    HI_DRV_FRONTEND_TER_ANTENNA_POWER_ON,      /** <Antenna power on */           /** <CNcomment:���ߵ�Դ�� */
    HI_DRV_FRONTEND_TER_ANTENNA_POWER_MAX     /** <Invalid value */              /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_ter_antenna_power;

/** configure lock tp PLP parameter,only in DVB-T2 */
/** CNcomment:��DVB-T2ʱ������Ҫ��Ƶ��������ܵ����� */
typedef struct {
    hi_u8    plp_id;           /** <PLP id */                /** <CNcomment:�����ܵ�ID */
    hi_u8    comm_plp_id;      /** <common PLP id */         /** <CNcomment:���������ܵ�ID */
    hi_u8    combination;      /** <PLP combination */       /** <CNcomment:���������ܵ��͹��������ܵ��Ƿ���ϱ�־ */
} hi_drv_frontend_dvbt2_plp_para;

/** PLP information */
/** CNcomment:�����ܵ���Ϣ */
typedef struct {
    hi_u8                          plp_id;       /** <PLP id */                /** <CNcomment:�����ܵ�ID */
    hi_u8                          plp_grp_id;   /** <PLP group id */          /** <CNcomment:�����ܵ���ID */
    hi_drv_frontend_dvbt2_plp_type plp_type;     /** <PLP type */              /** <CNcomment:�����ܵ����� */
} hi_drv_frontend_dvbt2_plp_info;

/** Terestrial connect param */
/** CNcomment:�����ź���̨���� */
typedef struct {
    hi_u32                       freq;            /** <freq in KHz */               /** <CNcomment:Ƶ�ʣ���λkHz */
    hi_u32                       band_width;      /** <bandwidth in KHz */          /** <CNcomment:������λkHz */
    hi_drv_modulation_type       mod_type;        /** <modulation type */           /** <CNcomment:���Ʒ�ʽ */
    hi_bool                      reverse;         /** <Spectrum reverse mode */     /** <CNcomment:Ƶ�׷�ת����ʽ */
    hi_drv_frontend_dvbt2_mode   channel_mode;    /** <dvb-t2 channel mode */       /** <CNcomment:dvb-t2�ŵ�����ģʽ */
    hi_drv_frontend_dvbt_ts_priority dvbt_prio;   /** <dvb-t TS priority */         /** <CNcomment:dvb-t�������ȼ� */
    hi_drv_frontend_dvbt2_plp_para   plp_param;   /** < PLP parameter */            /** <CNcomment:�����ܵ����� */
} hi_drv_ter_connect_para;

/** Structure of the DVB-T transmission signal's detailed information. */
/** CNcomment:DVB-T�ź���ϸ��Ϣ */
typedef struct {
    hi_u32                             freq;              /** <Frequency, in kHz */       /** <CNcomment:Ƶ�ʣ���λ��kHz */
    hi_u32                             band_width;        /** <Band width, in KHz */      /** <CNcomment:������λKHz */
    hi_drv_modulation_type             mod_type;          /** <Modulation type */         /** <CNcomment:���Ʒ�ʽ */
    hi_drv_frontend_fec_rate           fec_rate;          /** <FEC rate */                /** <CNcomment:ǰ��������� */
    hi_drv_frontend_fec_rate           low_pri_fec_rate;  /** <Low priority FEC rate */   /** <CNcomment:�����ȼ�ǰ��������� */
    hi_drv_frontend_guard_intv         guard_intv;        /** <GI mode */                 /** <CNcomment:�������ģʽ */
    hi_drv_frontend_fft                fft_mode;          /** <FFT mode */                /** <CNcomment:FFTģʽ */
    hi_drv_frontend_dvbt_hierarchy     hier_mod;          /** <Hierarchical Modulation and alpha, only used in DVB-T */
                                                          /** <CNcomment:hierachicalģʽ��alphaֵ */
    hi_drv_frontend_dvbt_ts_priority   ts_priority;       /** <The TS priority, only used in DVB-T */
                                                          /** <CNcomment:ts priority, ������DVB-Tģʽ�� */
    hi_u16                             cell_id;           /** < Cell ID */                /** <CNcomment:��ԪID */
} hi_drv_frontend_dvbt_signal_info;

/** Structure of the DVB-T2 transmission signal's detailed information. */
/** CNcomment:DVB-T2�ź���ϸ��Ϣ */
typedef struct {
    hi_u32                             freq;                /** <Frequency, in kHz */    /** <CNcomment:Ƶ�ʣ���λ��kHz */
    hi_u32                             band_width;          /** <Band width, in KHz */   /** <CNcomment:������λKHz */
    hi_drv_modulation_type             mod_type;            /** <Modulation type */      /** <CNcomment:���Ʒ�ʽ */
    hi_drv_frontend_fec_rate           fec_rate;            /** <FEC rate */             /** <CNcomment:ǰ��������� */
    hi_drv_frontend_guard_intv         guard_intv;          /** <GI mode */              /** <CNcomment:�������ģʽ */
    hi_drv_frontend_fft                fft_mode;            /** <FFT mode */             /** <CNcomment:FFTģʽ */
    hi_drv_frontend_dvbt2_plp_type     plp_type;           /** <PLP type */             /** <CNcomment:�����ܵ����� */
    hi_drv_frontend_dvbt2_pilot_pattern pilot_pattern;      /** <pilot pattern */        /** <CNcomment:��Ƶģʽ */
    hi_drv_frontend_dvbt2_carrier      carrier_mode;       /** <carrier mode */         /** <CNcomment:�ز�ģʽ */
    hi_drv_frontend_constellation      constellation;  /** <constellation mode */   /** <CNcomment:�����Ƿ���ת */
    hi_drv_frontend_dvbt2_fec_frame    fec_frame;      /** <FEC frame length */     /** <CNcomment:FEC֡�� */
    hi_drv_frontend_dvbt2_mode         channel_mode;        /** <Base channel or Lite channel */
                                                            /** <CNcomment:Base��Liteģʽ */
    hi_drv_frontend_dvbt2_issy         dvbt2_issy;          /** <DVB-T2 ISSY type */     /** <CNcomment:ISSY���� */
    hi_drv_frontend_dvbt2_stream_type  stream_type;         /** <Stream type */          /** <CNcomment:������ */
    hi_u16                             cell_id;             /** < Cell ID */             /** <CNcomment:��ԪID */
    hi_u16                             network_id;          /** < NetWork ID */          /** <CNcomment:����ID */
    hi_u16                             system_id;           /** < System ID */           /** <CNcomment:ϵͳID */
} hi_drv_frontend_dvbt2_signal_info;

/** ISDBT layer information,each layer can be received indepent */
/** CNcomment:ISDBT����Ϣ��ÿ�㶼���Զ������� */
typedef enum {
    HI_DRV_FRONTEND_ISDBT_LAYER_ALL,
    HI_DRV_FRONTEND_ISDBT_LAYER_A,
    HI_DRV_FRONTEND_ISDBT_LAYER_B,
    HI_DRV_FRONTEND_ISDBT_LAYER_C,
    HI_DRV_FRONTEND_ISDBT_LAYER_MAX
} hi_drv_frontend_isdbt_layer;

/** ISDB-T time interleaver type, only used in ISDB-T. */
/** CNcomment:ISDB-T ʱ��֯���ͣ�������ISDB-T */
typedef enum {
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_0,      /** <time interleaver type 1 */   /** <CNcomment:ʱ��֯����0 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_1,      /** <time interleaver type 1 */   /** <CNcomment:ʱ��֯����1 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_2,      /** <time interleaver type 2 */   /** <CNcomment:ʱ��֯����2 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_4,      /** <time interleaver type 4 */   /** <CNcomment:ʱ��֯����4 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_8,      /** <time interleaver type 8 */   /** <CNcomment:ʱ��֯����8 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_16,     /** <time interleaver type 16 */  /** <CNcomment:ʱ��֯����16 */
    HI_DRV_FRONTEND_ISDBT_TIME_INTERLEAVER_MAX,   /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_isdbt_time_interleaver;

/** Parameter for ISDB-T layer exist or not */
/** CNcomment:ISDB-Tģʽ�£����Ƿ������Ϣ */
typedef union {
    struct {
        hi_u8 layer_a_exist:1;  /* [0] */
        hi_u8 layer_b_exist:1;  /* [1] */
        hi_u8 layer_c_exist:1;  /* [2] */
        hi_u8 reserved:5;       /* [7:3] */
    } bits;

    hi_u8 existance_flag;
} hi_drv_frontend_isdbt_layers_identify;

/** Parameter for ISDB-T layer configuration */
/** CNcomment:ISDB-Tģʽ�£���������Ϣ */
typedef struct {
    hi_drv_frontend_isdbt_layer isdbt_layer;  /** <ISDB-T layer */ /** <CNcomment:ISDB-T����Ϣ */
} hi_drv_frontend_isdbt_receive_config;

/** Parameter for ISDB-T layer information */
/** CNcomment:ISDB-Tģʽ�£��� �ź�������Ϣ */
typedef struct {
    hi_u8 layer_seg_num;            /** <layer segment number */            /** <CNcomment:��segment���� */
    hi_u8 layer_reserved[3];        /** <reserved 3 bytes */
    hi_drv_frontend_isdbt_time_interleaver layer_time_interleaver; /** <layer hierarchy mode */
                                                                   /** <CNcomment:��ʱ�佻֯ģʽ */
    hi_drv_frontend_fec_rate  layer_fec_rate; /** <layer FEC rate */        /** <CNcomment:������ */
    hi_drv_modulation_type    layer_mod_type; /** <layer modulation type */ /** <CNcomment:�����ģʽ */
} hi_drv_frontend_isdbt_layers_info;

/** Parameter for ISDB-T TMCC information */
/** CNcomment:ISDB-Tģʽ�£�TMCC ��Ϣ */
typedef struct {
    hi_u8 emergency_flag;   /** <the start flag for emergency alarm broadcasting */   /** <CNcomment:��������������ʼ��־ */
    hi_u8 partial_flag;     /** <partial reception flag */                            /** <CNcomment:���ֽ��ձ�־ */
    hi_u8 phase_shift_corr; /** <phase shift correction value for connected segment transmission */
                            /** <CNcomment:��λƫ��ֵ */
    hi_u8 isdbt_system_id;  /** <system identification[0 = ISDB_T,1 = ISDB_T_SB] */   /** <CNcomment:ϵͳ��ʶ */

    hi_drv_frontend_isdbt_layers_info isdbt_layers_a_info_bits;
    hi_drv_frontend_isdbt_layers_info isdbt_layers_b_info_bits;
    hi_drv_frontend_isdbt_layers_info isdbt_layers_c_info_bits;

    hi_u8 tmcc_reserved[4];    /** <Reserved 4 bytes */                               /** <CNcomment:��������4�ֽ� */
} hi_drv_frontend_isdbt_tmcc_info;

/** Structure of the ISDB-T terrestrial transmission signal's detailed information. */
/** CNcomment:����ISDB-T�ź���ϸ��Ϣ */
typedef struct {
    hi_u32                            freq;         /** <Frequency, in kHz */    /** <CNcomment:Ƶ�ʣ���λ: kHz */
    hi_u32                            band_width;   /** <Band width, in KHz */   /** <CNcomment:������λKHz */
    hi_drv_frontend_isdbt_layers_identify  isdbt_layers; /** <the transmission and used information of ISDBT layer */
                                                          /** <CNcomment:ISDBT�����ڴ���ʹ����Ϣ */
    hi_drv_frontend_isdbt_tmcc_info   isdbt_tmcc_info; /** <the para of ISDBT layer */ /** <CNcomment:ISDBT�������Ϣ */
    hi_drv_frontend_guard_intv        guard_intv;      /** <GI mode */            /** <CNcomment:�������ģʽ */
    hi_drv_frontend_fft               fft_mode;        /** <FFT mode */            /** <CNcomment:FFTģʽ */
} hi_drv_frontend_isdbt_signal_info;

/** DTMB carrier type. */
/** CNcomment:DTMB �ز����� */
typedef enum {
    HI_DRV_FRONTEND_DTMB_CARRIER_UNKNOWN = 0,  /** <unknown type */            /** <CNcomment:δ֪���� */
    HI_DRV_FRONTEND_DTMB_CARRIER_SINGLE,       /** <single type */             /** <CNcomment:���ز� */
    HI_DRV_FRONTEND_DTMB_CARRIER_MULTI         /** <multi type */              /** <CNcomment:���ز� */
} hi_drv_frontend_dtmb_carrier;

/** DTMB QAM type. */
/** CNcomment:DTMB �������� */
typedef enum {
    HI_DRV_FRONTEND_DTMB_QAM_UNKNOWN = 0, /** <unknown type */      /** <CNcomment:δ֪���� */
    HI_DRV_FRONTEND_DTMB_QAM_4QAM_NR,     /** <4QAM_NR type */      /** <CNcomment:4QAM_NR ���� */
    HI_DRV_FRONTEND_DTMB_QAM_4QAM,        /** <single type */       /** <CNcomment:4QAM ���� */
    HI_DRV_FRONTEND_DTMB_QAM_16QAM,       /** <single type */       /** <CNcomment:16QAM ���� */
    HI_DRV_FRONTEND_DTMB_QAM_32QAM,       /** <single type */       /** <CNcomment:32QAM ���� */
    HI_DRV_FRONTEND_DTMB_QAM_64QAM        /** <single type */       /** <CNcomment:64QAM ���� */
} hi_drv_frontend_dtmb_qam;

/** DTMB code rate type. */
/** CNcomment:DTMB �������� */
typedef enum {
    HI_DRV_FRONTEND_DTMB_CODE_RATE_UNKNOWN = 0, /** <unknown type */  /** <CNcomment:δ֪���� */
    HI_DRV_FRONTEND_DTMB_CODE_RATE_0_DOT_4,     /** <0.4 type */      /** <CNcomment:0.4 ���� */
    HI_DRV_FRONTEND_DTMB_CODE_RATE_0_DOT_6,     /** <0.6 type */      /** <CNcomment:0.6 ���� */
    HI_DRV_FRONTEND_DTMB_CODE_RATE_0_DOT_8      /** <0.8 type */      /** <CNcomment:0.8 ���� */
} hi_drv_frontend_dtmb_code_rate;

/** DTMB time interleaving type. */
/** CNcomment:DTMB ʱ��֯���� */
typedef enum {
    HI_DRV_FRONTEND_DTMB_TIME_INTERLEAVER_UNKNOWN = 0, /** <unknown type */  /** <CNcomment:δ֪���� */
    HI_DRV_FRONTEND_DTMB_TIME_INTERLEAVER_240,         /** <240 type */      /** <CNcomment:240 ���� */
    HI_DRV_FRONTEND_DTMB_TIME_INTERLEAVER_720          /** <720 type */      /** <CNcomment:720 ���� */
} hi_drv_frontend_dtmb_time_interleave;

/** DTMB guard interval type. */
/** CNcomment:DTMB ����������� */
typedef enum {
    HI_DRV_FRONTEND_DTMB_GI_UNKNOWN = 0,   /** <unknown type */      /** <CNcomment:δ֪���� */
    HI_DRV_FRONTEND_DTMB_GI_420,           /** <420 type */          /** <CNcomment:420 ���� */
    HI_DRV_FRONTEND_DTMB_GI_595,           /** <595 type */          /** <CNcomment:595 ���� */
    HI_DRV_FRONTEND_DTMB_GI_945            /** <945 type */          /** <CNcomment:945 ���� */
} hi_drv_frontend_dtmb_guard_interval;

/** DTMB signal information. */
/** CNcomment:DTMB�ź���Ϣ */
typedef struct {
    hi_drv_frontend_dtmb_carrier    carrier_mode;    /** <Carrier type */          /** <CNcomment:�ز����� */
    hi_drv_frontend_dtmb_qam       qam_index;       /** <QAM type */              /** <CNcomment:�������� */
    hi_drv_frontend_dtmb_code_rate       code_rate;       /** <Code rate type */        /** <CNcomment:�������� */
    hi_drv_frontend_dtmb_time_interleave time_interleave; /** <Time interleave type */  /** <CNcomment:ʱ��֯���� */
    hi_drv_frontend_dtmb_guard_interval  guard_interval;  /** <Guard interval type */   /** <CNcomment:����ʱ������ */
} hi_drv_frontend_dtmb_signal_info;

/** DiSEqC Wave Mode */
/** CNcomment:DiSEqCģʽ */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_WAVE_NORMAL,   /** <Waveform produced by demod */              /** <CNcomment:������demod���� */
    HI_DRV_FRONTEND_DISEQC_WAVE_ENVELOPE, /** <Waveform produced by LNB control device */ /** <CNcomment:�����ɿ���оƬ���� */
    HI_DRV_FRONTEND_DISEQC_WAVE_MAX      /** <Invalid value */                           /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_wave;

/** LNB power supply and control device */
/** CNcomment:LNB����Ϳ���оƬ */
typedef enum {
    HI_DRV_LNB_CTRL_DEV_TYPE_NONE,           /** <No LNB control device */      /** <CNcomment:�޿���оƬ */
    HI_DRV_LNB_CTRL_DEV_TYPE_MPS8125,        /** <MPS8125 */                    /** <CNcomment:MPS8125 */
    HI_DRV_LNB_CTRL_DEV_TYPE_ISL9492,        /** <ISL9492 */                    /** <CNcomment:ISL9492 */
    HI_DRV_LNB_CTRL_DEV_TYPE_A8300,          /** <A8300 */                      /** <CNcomment:A8300 */
    HI_DRV_LNB_CTRL_DEV_TYPE_A8297,          /** <A8297 */                      /** <CNcomment:A8297 */
    HI_DRV_LNB_CTRL_DEV_TYPE_TPS65233,       /** <TPS65233 */                   /** <CNcomment:TPS65233 */
    HI_DRV_LNB_CTRL_DEV_TYPE_LNBH30,         /** <LNBH30 */                     /** <CNcomment:LNBH30 */
    HI_DRV_LNB_CTRL_DEV_TYPE_MAX            /** <Invalid value */              /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_lnb_ctrl_dev_type;

/** Polarization type */
/** CNcomment:������ʽ */
typedef enum {
    HI_DRV_FRONTEND_POLARIZATION_H,     /** <Horizontal Polarization */           /** <CNcomment:ˮƽ���� */
    HI_DRV_FRONTEND_POLARIZATION_V,     /** <Vertical Polarization */             /** <CNcomment:��ֱ���� */
    HI_DRV_FRONTEND_POLARIZATION_L,     /** <Left-hand circular Polarization */   /** <CNcomment:����Բ���� */
    HI_DRV_FRONTEND_POLARIZATION_R,     /** <Right-hand circular Polarization */  /** <CNcomment:����Բ���� */
    HI_DRV_FRONTEND_POLARIZATION_MAX,  /** <Invalid value */                     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_polarization;

/** code and modulation mode */
/** CNcomment:code and modulation ģʽ */
typedef enum {
    HI_DRV_FRONTEND_CODE_MODULATION_VCM_ACM,       /** < VCM/ACM */      /** <CNcomment:�ɱ����ʺ͵���/����Ӧ���ʺ͵���ģʽ */
    HI_DRV_FRONTEND_CODE_MODULATION_CCM,           /** < CCM */          /** <CNcomment:�̶����ʺ͵���ģʽ */
    HI_DRV_FRONTEND_CODE_MODULATION_MULTISTREAM,   /** < MultiStream */  /** <CNcomment:�������ģʽ�µĶ��� */
    HI_DRV_FRONTEND_CODE_MODULATION_MAX           /** <Invalid value */ /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_code_modulation;

/** Roll off */
/** CNcomment:����ϵ�� */
typedef enum {
    HI_DRV_FRONTEND_ROLL_OFF_35,        /** <Roll off 0.35 */           /** <CNcomment:����ϵ��0.35 */
    HI_DRV_FRONTEND_ROLL_OFF_25,        /** <Roll off 0.25 */           /** <CNcomment:����ϵ��0.25 */
    HI_DRV_FRONTEND_ROLL_OFF_20,        /** <Roll off 0.20 */           /** <CNcomment:����ϵ��0.20 */
    HI_DRV_FRONTEND_ROLL_OFF_15,        /** <Roll off 0.15 */           /** <CNcomment:����ϵ��0.15 */
    HI_DRV_FRONTEND_ROLL_OFF_10,        /** <Roll off 0.10 */           /** <CNcomment:����ϵ��0.10 */
    HI_DRV_FRONTEND_ROLL_OFF_05,        /** <Roll off 0.05 */           /** <CNcomment:����ϵ��0.05 */
    HI_DRV_FRONTEND_ROLL_OFF_MAX       /** <Invalid value */           /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_roll_off;

/** Pilot type */
/** CNcomment:��Ƶ */
typedef enum {
    HI_DRV_FRONTEND_PILOT_OFF,         /** <Pilot off */               /** <CNcomment:��Ƶ�ر� */
    HI_DRV_FRONTEND_PILOT_ON,          /** <Pilot on */                /** <CNcomment:��Ƶ�� */
    HI_DRV_FRONTEND_PILOT_MAX         /** <Invalid value */           /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_pilot;

/** FEC length */
/** CNcomment:FEC֡ ���� */
typedef enum {
    HI_DRV_FRONTEND_SAT_FEC_FRAME_NORMAL,  /** <nomal FEC Frame */       /** <CNcomment:��ͨ����FEC֡��������DVB-S/S2/S2X */
    HI_DRV_FRONTEND_SAT_FEC_FRAME_SHORT,   /** <short FEC Frame */       /** <CNcomment:��FEC֡��������DVB-S2X */
    HI_DRV_FRONTEND_SAT_FEC_FRAME_MEDIUM,  /** <medium FEC Fream */      /** <CNcomment:�е�FEC֡��������DVB-S2X */
    HI_DRV_FRONTEND_SAT_FEC_FRAME_MAX     /** <Invalid value */         /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_sat_fec_frame;

/** Stream typef */
/** CNcomment:������ */
typedef enum {
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_GENERIC_PACKETIZED,  /** < Generic Packetized Stream */  /** <CNcomment:ͨ�ô�������� */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_GENERIC_CONTINUOUS,  /** < Generic Continuous Stream */  /** <CNcomment:ͨ������������ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_GSE_HEM,        /** < GSE in High Efficiency Mode */ /** <CNcomment:GSE������HEMģʽ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_TRANSPORT,      /** < Trensport Stream */            /** <CNcomment:TS������ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_GSE_LITE,       /** < GSE-Lite */                    /** <CNcomment:GSE-Lite������ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_GSE_LITE_HEM,   /** < GSE-Lite in High Efficiency Mode */
                                                    /** <CNcomment:GSE-Lite��HEMģʽ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_T2MI,           /** < T2MI Stream */                  /** <CNcomment:T2MI������ */
    HI_DRV_FRONTEND_SAT_STREAM_TYPE_MAX            /** < Invalid value */                /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_sat_stream_type;

/** Satellite extended attribution */
/** CNcomment:���ǻ��������� */
typedef struct {
    hi_u16                    tuner_max_lpf;   /** <Tuner max LPF, MHz */  /** <CNcomment:tuner��ͨ�˲���ͨ��Ƶ�ʣ���λMHz */
    hi_drv_tuner_rf_agc_mode  rf_agc;          /** <Tuner RF AGC mode */   /** <CNcomment:agcģʽ */
    hi_drv_tuner_iq_spectrum_mode    iq_spectrum;   /** <Tuner IQ spectrum mode */     /** <CNcomment:IQģʽ */
    hi_drv_frontend_diseqc_wave diseqc_wave;   /** <DiSEqC Wave Mode */           /** <CNcomment:DiSEqCģʽ */
    hi_drv_lnb_ctrl_dev_type  lnb_ctrl_dev;  /** <LNB power supply and control device */ /** <CNcomment:LNB����оƬ */
    hi_u16                    lnb_i2c_channel;
    hi_u16                    lnb_dev_address; /** <LNB control device address */ /** <CNcomment:LNB����оƬi2c��ַ */
} hi_drv_frontend_sat_attr;

/** Structure of the satellite transmission signal. */
/** CNcomment:����Satellite�����ź� */
typedef struct {
    hi_u32                         freq;           /** <Downlink frequency, in kHz */ /** <CNcomment:����Ƶ�ʣ���λ��kHz */
    hi_u32                         symbol_rate;    /** <Symbol rate, in Symb/s */     /** <CNcomment:�����ʣ���λ��Symb/s */
    hi_drv_frontend_polarization   polar;          /** <Polarization type */          /** <CNcomment:������ʽ */

    /** <Physical layer initial scrambling code, range 0~262141, the default value must be 0,when signal sender
         config some TP using not 0, then receiver must modify this value the same as sender, if not, signal will
         be unlock, the modified value maybe told by signal sender. */
    /** <CNcomment:����������ʼֵ����Χ0~262141.��ֵ��Ĭ������ֵΪ0,����Ƶ�㷢��û��ʹ��Ĭ��ֵ0��
         �ն˽���ʱ���޸ĸ�ֵ�ͷ���һ�£�����������ź�ʧ������ֵ���ɷ��˸�֪�� */
    hi_u32                         scramble_value;

    hi_drv_frontend_stream_id_type stream_id_type; /** <Stream ID type, only for ISDB-S/S3 */
                                                   /** <CNcomment:��ID ���ͣ�ֻ����ISDB-S/S3 */
    hi_u16                         stream_id; /** <Stream ID, only for ISDB-S/S3 */ /** <CNcomment:��ID��ֻ����ISDB-S/S3 */
} hi_drv_sat_connect_para;


/** Structure of the satellite transmission signal's detailed information. */
/** CNcomment:�����ź���ϸ��Ϣ */
typedef struct {
    hi_u32                             freq;         /** <Downlink frequency, in kHz */ /** <CNcomment:����Ƶ�ʣ���λ��kHz */
    hi_u32                             symbol_rate;  /** <Symbol rate, in Symb/s */     /** <CNcomment:�����ʣ���λSymb/s */
    hi_drv_modulation_type             mod_type;     /** <Modulation type */            /** <CNcomment:���Ʒ�ʽ */
    hi_drv_frontend_polarization       polar;        /** <Polarization type */          /** <CNcomment:������ʽ */
    hi_drv_frontend_fec_rate           fec_rate;     /** <FEC rate */                   /** <CNcomment:ǰ��������� */
    hi_drv_frontend_code_modulation    code_modulation;
    hi_drv_frontend_roll_off           roll_off;     /** <Rolloff */                    /** <CNcomment:����ϵ�� */
    hi_drv_frontend_pilot              pilot;        /** <Pilot */                      /** <CNcomment:��Ƶ */
    hi_drv_frontend_sat_fec_frame fec_frame_mode;  /** <FEC fream mode */          /** <CNcomment:FEC֡���� */
    hi_drv_frontend_sat_stream_type    stream_type;  /** <Stream type */                /** <CNcomment:������ */
} hi_drv_frontend_dvbs2x_signal_info;

/** LNB type */
/** CNcomment:LNB���� */
typedef enum {
    HI_DRV_FRONTEND_LNB_TYPE_SINGLE_FREQUENCY,   /** <Single LO frequency */       /** <CNcomment:������ */
    HI_DRV_FRONTEND_LNB_TYPE_DUAL_FREQUENCY,     /** <Dual LO frequency */         /** <CNcomment:˫���� */
    HI_DRV_FRONTEND_LNB_TYPE_UNICABLE,           /** <Unicable LNB */             /** <CNcomment:unicable��Ƶͷ */
    HI_DRV_FRONTEND_LNB_TYPE_TRIPLE_FREQUENCY,   /** <Triple LO frequency */       /** <CNcomment:������ */
    HI_DRV_FRONTEND_LNB_TYPE_UNICABLE2,          /** <Unicable2 LNB */             /** <CNcomment:unicable2��Ƶͷ */
    HI_DRV_FRONTEND_LNB_TYPE_MAX           /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_lnb_type;

/** LNB band type */
/** CNcomment:�����ź�Ƶ�� */
typedef enum {
    HI_DRV_FRONTEND_LNB_BAND_C,             /** <C */                        /** <CNcomment:C���� */
    HI_DRV_FRONTEND_LNB_BAND_KU,            /** <Ku */                       /** <CNcomment:Ku���� */
    HI_DRV_FRONTEND_LNB_BAND_KA,            /** <Ka */                       /** <CNcomment:Ka���� */
    HI_DRV_FRONTEND_LNB_BAND_MAX           /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_lnb_band;

/** LNB power control */
/** CNcomment:��Ƶͷ������� */
typedef enum {
    HI_DRV_FRONTEND_LNB_POWER_OFF,          /** <LNB power off */                     /** <CNcomment:�ض� */
    HI_DRV_FRONTEND_LNB_POWER_ON,           /** <LNB power auto, 13V/18V, default */  /** <CNcomment:Ĭ�ϵ�13/18V���� */
    HI_DRV_FRONTEND_LNB_POWER_ENHANCED,     /** <LNB power auto, 14V/19V, some LNB control device can support. */
                                            /** <CNcomment:��ǿ���磬����LNBоƬ֧�� */
    HI_DRV_FRONTEND_LNB_POWER_MAX          /** <Invalid value */                     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_lnb_power;

/** LNB 22K tone status, for Ku band LNB */
/** CNcomment:22k�ź�״̬������Ku˫���� */
typedef enum {
    HI_DRV_FRONTEND_LNB_22K_OFF,            /** <22k off */                    /** <CNcomment:22k�źŹأ�ѡ��ͱ��� */
    HI_DRV_FRONTEND_LNB_22K_ON,             /** <22k on */                     /** <CNcomment:22k�źſ���ѡ��߱��� */
    HI_DRV_FRONTEND_LNB_22K_MAX            /** <Invalid value */              /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_lnb_22k;

/** unicable multi-switch port. */
/** CNcomment:unicable���ض˿�ö�� */
typedef enum {
    HI_DRV_FRONTEND_SAT_POSN_A,    /** <unicable switch port A */    /** <CNcomment:�˿�A */
    HI_DRV_FRONTEND_SAT_POSN_B,    /** <unicable switch port B */    /** <CNcomment:�˿�B */
    HI_DRV_FRONTEND_SAT_POSN_MAX   /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_sat_posn;

/** LNB configurating parameters */
/** CNcomment:LNB���ò��� */
typedef struct {
    hi_drv_frontend_lnb_type  lnb_type;    /** <LNB type */                              /** <CNcomment:LNB���� */
    hi_u32           low_lo;      /** < Low Local Oscillator Frequency, MHz */ /** <CNcomment:LNB�ͱ���Ƶ�ʣ���λMHz */
    hi_u32           medium_lo;   /** < Medium Local Oscillator Frequency, MHz */ /** <CNcomment:LNB�б���Ƶ�ʣ���λMHz */
    hi_u32           high_lo;     /** < High Local Oscillator Frequency, MHz */ /** <CNcomment:LNB�߱���Ƶ�ʣ���λMHz */
    hi_drv_frontend_lnb_band  lnb_band;    /** < LNB band, C or Ku */                   /** <CNcomment:LNB���Σ�C��Ku */

    /** Structure of the unicable device attribute. */
    /** CNcomment:����Unicable�豸���� */
    hi_u8 ub_num;                          /** < SCR number, 0-31 */             /** <CNcomment:SCR��ţ�ȡֵΪ0-31 */
    hi_u32 ub_freq;                        /** < SCR IF frequency, unit MHz */   /** <CNcomment:SCR��ƵƵ�ʣ� ��λMHz */
    hi_drv_frontend_sat_posn sat_posn;  /** < unicable multi-switch port */   /** <CNcomment:unicable���ض˿ں� */
    hi_bool ub_bin_protect;                /** < UB with pin protect */          /** <CNcomment:�û�Ƶ��pin�뱣�� */
} hi_drv_frontend_lnb_config;

/** Tuner blind scan type */
/** CNcomment:TUNERäɨ��ʽ */
typedef enum {
    HI_DRV_FRONTEND_BLIND_SCAN_MODE_AUTO = 0,       /** <Blind scan automatically */  /** <CNcomment:�Զ�ɨ�� */
    HI_DRV_FRONTEND_BLIND_SCAN_MODE_MANUAL,         /** <Blind scan manually */       /** <CNcomment:�ֶ�ɨ�� */
    HI_DRV_FRONTEND_BLIND_SCAN_MODE_MAX            /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_blind_scan_mode;

/** Definition of blind scan event type */
/** CNcomment:TUNERäɨ�¼� */
typedef enum {
    HI_DRV_FRONTEND_BLIND_SCAN_EVT_STATUS,          /** <New status */        /** <CNcomment:״̬�仯 */
    HI_DRV_FRONTEND_BLIND_SCAN_EVT_PROGRESS,        /** <New Porgress */     /** <CNcomment:���ȱ仯 */
    HI_DRV_FRONTEND_BLIND_SCAN_EVT_NEWRESULT,       /** <Find new channel */  /** <CNcomment:��Ƶ�� */
    HI_DRV_FRONTEND_BLIND_SCAN_EVT_MAX             /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_blind_scan_evt;

/** Definition of tuner blind scan status */
/** CNcomment:TUNERäɨ״̬ */
typedef enum {
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_IDLE,         /** <Idel */              /** <CNcomment:���� */
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_SCANNING,     /** <Scanning */          /** <CNcomment:ɨ���� */
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_FINISH,       /** <Finish */            /** <CNcomment:�ɹ���� */
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_QUIT,         /** <User quit */         /** <CNcomment:�û��˳� */
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_FAIL,         /** <Scan fail */         /** <CNcomment:ɨ��ʧ�� */
    HI_DRV_FRONTEND_BLIND_SCAN_STATUS_MAX          /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_blind_scan_status;

/** Definition of Unicable user band scan status */
/** CNcomment:Unicable �û�Ƶ��äɨ״̬ */
typedef enum {
    HI_DRV_UNICABLE_SCAN_STATUS_IDLE,         /** <Idel */              /** <CNcomment:���� */
    HI_DRV_UNICABLE_SCAN_STATUS_SCANNING,     /** <Scanning */          /** <CNcomment:ɨ���� */
    HI_DRV_UNICABLE_SCAN_STATUS_FINISH,       /** <Finish */            /** <CNcomment:�ɹ���� */
    HI_DRV_UNICABLE_SCAN_STATUS_QUIT,         /** <User quit */         /** <CNcomment:�û��˳� */
    HI_DRV_UNICABLE_SCAN_STATUS_FAIL,         /** <Scan fail */         /** <CNcomment:ɨ��ʧ�� */
    HI_DRV_UNICABLE_SCAN_STATUS_MAX          /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_unicable_scan_status;

/** Structure of satellite TP */
/** CNcomment:TUNERɨ��TP��Ϣ */
typedef struct {
    hi_u32                        freq;            /** <Downlink frequency, in kHz */    /** <CNcomment:����Ƶ�ʣ���λ��kHz */
    hi_u32                        symbol_rate;     /** <Symbol rate, in bit/s */         /** <CNcomment:�����ʣ���λbps */
    hi_drv_frontend_polarization  ploar;           /** <Polarization type */             /** <CNcomment:������ʽ */
    hi_u8                         cbs_reliablity;  /** <TP reliability */                /** <CNcomment:TP�Ŀɿ��� */
} hi_drv_frontend_sat_tp_info;

/** Notify structure of tuner blind scan */
/** CNcomment:TUNERäɨ֪ͨ��Ϣ */
typedef union {
    hi_drv_frontend_blind_scan_status* status;             /** <Scanning status */            /** <CNcomment:äɨ״̬ */
    hi_u16*                            progress_percent;   /** <Scanning progress */          /** <CNcomment:äɨ���� */
    hi_drv_frontend_sat_tp_info*       result;           /** <Scanning result */            /** <CNcomment:äɨ��� */
} hi_drv_frontend_blind_scan_notify;

/** Parameter of the satellite tuner blind scan */
/** CNcomment:����TUNERäɨ���� */
typedef struct {
    /** <LNB Polarization type, only take effect in manual blind scan mode */
    /** <CNcomment:LNB������ʽ���Զ�ɨ��ģʽ������Ч */
    hi_drv_frontend_polarization ploar;

    /** <LNB 22K signal status, for Ku band LNB which has dual LO, 22K ON will select high LO and 22K off select low LO,
        only take effect in manual blind scan mode*/
    /** <CNcomment:LNB 22K״̬������Ku����˫����LNB��ONѡ��߱���OFFѡ��ͱ����Զ�ɨ��ģʽ������Ч */
    hi_drv_frontend_lnb_22k      lnb_22k;

    /** <Blind scan start IF, in kHz, only take effect in manual blind scan mode */
    /** <CNcomment:äɨ��ʼƵ��(��Ƶ)����λ��kHz���Զ�ɨ��ģʽ������Ч */
    hi_u32                         start_freq;

    /** <Blind scan stop IF, in kHz, only take effect in manual blind scan mode */
    /** <CNcomment:äɨ����Ƶ��(��Ƶ)����λ��kHz���Զ�ɨ��ģʽ������Ч */
    hi_u32                         stop_freq;

    /** <The execution of the blind scan may change the 13/18V or 22K status.
        If you use any DiSEqC device which need send command when 13/18V or 22K status change,
        you should registe a callback here. Otherwise, you can set NULL here.*/
    /** <CNcomment:äɨ���̿��ܻ��л�������ʽ��22K�����������ĳЩDiSEqC�豸��Ҫ����13/18V��22K�ģ�
        ��ע������ص������û���ã���ɴ�NULL */
    hi_void (*diseqc_set)(hi_u32 port, hi_drv_frontend_polarization ploar,
                            hi_drv_frontend_lnb_22k lnb_22k);

    /** <Callback when scan status change, scan progress change or find new channel. */
    /** <CNcomment:ɨ��״̬����Ȱٷֱȷ����仯ʱ�������µ�Ƶ��ʱ�ص� */
    hi_void (*evt_notify)(hi_u32 port, hi_drv_frontend_blind_scan_evt ent, hi_drv_frontend_blind_scan_notify *notify);
} hi_drv_frontend_sat_blind_scan_para;

typedef enum {
    HI_DRV_UNICABLE_SCAN_EVT_STATUS,          /** <New status */        /** <CNcomment:״̬�仯 */
    HI_DRV_UNICABLE_SCAN_EVT_PROGRESS,        /** <New Porgress */     /** <CNcomment:���ȱ仯 */
    HI_DRV_UNICABLE_SCAN_EVT_MAX             /** <Invalid value */     /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_unicable_scan_user_band_evt;

typedef union {
    hi_drv_unicable_scan_status* status;           /** <Scanning status */   /** <CNcomment:äɨ״̬ */
    hi_u16*                      progress_percent; /** <Scanning progress */ /** <CNcomment:äɨ���� */
} hi_drv_unicable_scan_user_band_notify;

/** Structure of terrestrial scan */
/** CNcomment:����TUNERɨ��DVB-T/T2�ź� */
typedef struct {
    hi_void (*evt_notify)(hi_u32 port, hi_drv_unicable_scan_user_band_evt evt,
        hi_drv_unicable_scan_user_band_notify *notify);
} hi_drv_unicable_scan_para;

/** Parameter of the tuner blind scan */
/** CNcomment:TUNERäɨ���� */
typedef struct {
    hi_drv_frontend_blind_scan_mode mode;            /** <Scanning mode */            /** <CNcomment:äɨģʽ */
    union {
        hi_drv_frontend_sat_blind_scan_para sat;    /** <Scanning parameter */        /** <CNcomment:äɨ���� */
    } scan_para;
} hi_drv_frontend_blind_scan_para;

/** 0/12V switch */
/** CNcomment:0/12V���� */
typedef enum {
    HI_DRV_FRONTEND_SWITCH_0_12V_NONE,         /** < None, default */            /** <CNcomment:���ӿ���״̬ */
    HI_DRV_FRONTEND_SWITCH_0_12V_0,            /** < 0V */                       /** <CNcomment:0V״̬ */
    HI_DRV_FRONTEND_SWITCH_0_12V_12,           /** < 12V */                      /** <CNcomment:12V״̬ */
    HI_DRV_FRONTEND_SWITCH_0_12V_MAX          /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_switch_0_12v_sta;

/** 22KHz switch */
/** CNcomment:22K���� */
typedef enum {
    HI_DRV_FRONTEND_SWITCH_22K_NONE,           /** < None, default */            /** <CNcomment:���ӿ���״̬ */
    HI_DRV_FRONTEND_SWITCH_22K_0,              /** < 0 */                        /** <CNcomment:0kHz�˿� */
    HI_DRV_FRONTEND_SWITCH_22K_22,             /** < 22KHz */                    /** <CNcomment:22kHz�˿� */
    HI_DRV_FRONTEND_SWITCH_22K_MAX            /** <Invalid value */             /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_switch_22k_sta;

/** Tone burst switch */
/** CNcomment:Tone burst���� */
typedef enum {
    HI_DRV_FRONTEND_SWITCH_TONEBURST_NONE,     /** < Don't send tone burst, default */ /** <CNcomment:���ӿ���״̬ */
    HI_DRV_FRONTEND_SWITCH_TONEBURST_0,        /** < Tone burst 0 */                   /** <CNcomment:0 port */
    HI_DRV_FRONTEND_SWITCH_TONEBURST_1,        /** < Tone burst 1 */                   /** <CNcomment:1 port */
    HI_DRV_FRONTEND_SWITCH_TONEBURST_MAX      /** <Invalid value */                   /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_switch_tone_burst_sta;

/** DiSEqC Level */
/** CNcomment:DiSEqC�豸�汾 */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_LEVEL_1_X,      /** <1.x, one way */                  /** <CNcomment:1.x������ */
    HI_DRV_FRONTEND_DISEQC_LEVEL_2_X,      /** <2.x, two way, support reply */   /** <CNcomment:2.x��˫��֧��Reply */
    HI_DRV_FRONTEND_DISEQC_LEVEL_MAX      /** <Invalid value */                 /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_level;

/** Receive status of DiSEqC reply massage */
/** CNcomment:DiSEqC��Ϣ����״̬ */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_RECV_STATUS_OK,        /** <Receive successfully */          /** <CNcomment:���ճɹ� */
    HI_DRV_FRONTEND_DISEQC_RECV_STATUS_UNSUPPORT, /** <Device don't support reply */  /** <CNcomment:�豸��֧�ֻش� */
    HI_DRV_FRONTEND_DISEQC_RECV_STATUS_TIMEOUT,   /** <Receive timeout */             /** <CNcomment:���ճ�ʱ */
    HI_DRV_FRONTEND_DISEQC_RECV_STATUS_ERROR,     /** <Receive fail */                  /** <CNcomment:���ճ��� */
    HI_DRV_FRONTEND_DISEQC_RECV_STATUS_MAX       /** <Invalid value */                 /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_recv_status;

/** Structure of the DiSEqC send massage */
/** CNcomment:DiSEqC������Ϣ�ṹ */
typedef struct {
    hi_drv_frontend_diseqc_level    level;       /** <Device level */                     /** <CNcomment:�����汾 */
    hi_drv_frontend_switch_tone_burst_sta tone_burst;  /** <Tone Burst */                 /** <CNcomment:tone�ź�״̬ */
    hi_u8                           msg[HI_DRV_DISEQC_MSG_MAX_LENGTH]; /** <Message data */ /** <CNcomment:��Ϣ�� */
    hi_u8                           length;       /** <Message length */                    /** <CNcomment:��Ϣ���� */
    hi_u8                           repeat_times; /** <Message repeat times */             /** <CNcomment:�ش����� */
} hi_drv_frontend_diseqc_send_msg;

/** Structure of the DiSEqC reply massage */
/** CNcomment:DiSEqC������Ϣ�ṹ */
typedef struct {
    hi_drv_frontend_diseqc_recv_status status;     /** <Recieve status */         /** <CNcomment:����״̬ */
    hi_u8       msg[HI_DRV_DISEQC_MSG_MAX_LENGTH]; /** <Recieve message data */   /** <CNcomment:�������ݻ��� */
    hi_u8       length;                            /** <Recieve message length */ /** <CNcomment:�������ݳ��� */
} hi_drv_frontend_diseqc_recv_msg;

/** DiSEqC Switch port */
/** CNcomment:DiSEqC���ض˿�ö�� */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_SWITCH_NONE = 0,         /** <none */                /** <CNcomment:���ӿ��� */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_1,           /** <port1 */               /** <CNcomment:�˿�1 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_2,           /** <port2 */               /** <CNcomment:�˿�2 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_3,           /** <port3 */               /** <CNcomment:�˿�3 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_4,           /** <port4 */               /** <CNcomment:�˿�4 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_5,           /** <port5 */               /** <CNcomment:�˿�5 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_6,           /** <port6 */               /** <CNcomment:�˿�6 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_7,           /** <port7 */               /** <CNcomment:�˿�7 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_8,           /** <port8 */               /** <CNcomment:�˿�8 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_9,           /** <port9 */               /** <CNcomment:�˿�9 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_10,          /** <port10 */              /** <CNcomment:�˿�10 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_11,          /** <port11 */              /** <CNcomment:�˿�11 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_12,          /** <port12 */              /** <CNcomment:�˿�12 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_13,          /** <port13 */              /** <CNcomment:�˿�13 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_14,          /** <port14 */              /** <CNcomment:�˿�14 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_15,          /** <port15 */              /** <CNcomment:�˿�15 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_16,          /** <port16 */              /** <CNcomment:�˿�16 */
    HI_DRV_FRONTEND_DISEQC_SWITCH_PORT_MAX         /** <Invalid value */       /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_switch_port;

/** Parameter for DiSEqC 1.0/2.0 switch
   Some DiSEqC device need set polarization(13/18V) and 22K, you can set them here. */
/** CNcomment:DiSEqC 1.0/2.0 ���ز���
   ��ЩDiSEqC�豸��Ҫ���ü�����ʽ��22K�ģ�������������豸����Ҫ���������� */
typedef struct {
    hi_drv_frontend_diseqc_level       level;   /** <DiSEqC device level */           /** <CNcomment:�����汾 */
    hi_drv_frontend_diseqc_switch_port port;    /** <DiSEqC switch port */            /** <CNcomment:ѡͨ�˿ں� */
    hi_drv_frontend_polarization       ploar;   /** <Polarization type */            /** <CNcomment:������ʽ */
    hi_drv_frontend_lnb_22k            lnb_22k; /** <22K status */                    /** <CNcomment:22k״̬ */
} hi_drv_frontend_diseqc_switch_4_port_para;

/** Parameter for DiSEqC 1.1/2.1 switch */
/** CNcomment:DiSEqC 1.1/2.1 ���ز��� */
typedef struct {
    hi_drv_frontend_diseqc_level       level;  /** <DiSEqC device level */            /** <CNcomment:�����汾 */
    hi_drv_frontend_diseqc_switch_port port;   /** <DiSEqC switch port */             /** <CNcomment:ѡͨ�˿ں� */
} hi_drv_frontend_diseqc_switch_16_port_para;

/** DiSEqC motor limit setting */
/** CNcomment:DiSEqC��Ｋ������ */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_LIMIT_OFF,              /** <Disable Limits */                /** <CNcomment:������ */
    HI_DRV_FRONTEND_DISEQC_LIMIT_EAST,             /** <Set East Limit */                /** <CNcomment:�������� */
    HI_DRV_FRONTEND_DISEQC_LIMIT_WEST,             /** <Set West Limit */                /** <CNcomment:�������� */
    HI_DRV_FRONTEND_DISEQC_LIMIT_MAX              /** <Invalid value */                 /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_limit;

/** Difinition of DiSEqC motor move direction */
/** CNcomment:DiSEqC����ƶ����� */
typedef enum {
    HI_DRV_FRONTEND_DISEQC_MOVE_DIR_EAST,          /** <Move east */                     /** <CNcomment:���ƶ� */
    HI_DRV_FRONTEND_DISEQC_MOVE_DIR_WEST,          /** <Move west */                     /** <CNcomment:�����ƶ� */
    HI_DRV_FRONTEND_DISEQC_MOVE_DIR_MAX           /** <Invalid value */                 /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_diseqc_move_dir;

/** Parameter for DiSEqC motor store position */
/** CNcomment:���ߴ洢λ�ò��� */
typedef struct {
    hi_drv_frontend_diseqc_level level;        /** <DiSEqC device level */               /** <CNcomment:�����汾 */
    hi_u32                        pos;         /** <Index of position, 0-255 */          /** <CNcomment:λ����� */
} hi_drv_frontend_diseqc_position;

/** Parameter for DiSEqC motor limit setting */
/** CNcomment:����Limit���ò��� */
typedef struct {
    hi_drv_frontend_diseqc_level level;        /** <DiSEqC device level */               /** <CNcomment:�����汾 */
    hi_drv_frontend_diseqc_limit limit;        /** <Limit setting */                     /** <CNcomment:�����趨 */
} hi_drv_frontend_diseqc_limit_para;

/** Parameter for DiSEqC motor running */
/** CNcomment:DiSEqC���ת������ */
typedef struct {
    hi_drv_frontend_diseqc_level    level;    /** <DiSEqC device level */           /** <CNcomment:�����汾 */
    hi_drv_frontend_diseqc_move_dir dir;      /** <Moving direction */              /** <CNcomment:ת������ */
    hi_u32                    running_steps;  /** <0 mean running continus;1~128 mean running steps every time. */
                                              /** <CNcomment:0��ʾ����ת����1~128֮���ʾÿ��ת��step���� */
} hi_drv_frontend_diseqc_run;

/** Parameter for DiSEqC motor recalculate */
/** CNcomment:DiSEqC�����ؼ������ */
typedef struct {
    hi_drv_frontend_diseqc_level level;        /** <DiSEqC device level */           /** <CNcomment:�����汾 */
    hi_u8                        para1;        /** <Parameter 1 */                   /** <CNcomment:����1 */
    hi_u8                        para2;        /** <Parameter 2 */                   /** <CNcomment:����2 */
    hi_u8                        para3;        /** <Parameter 3 */                   /** <CNcomment:����3 */
    hi_u8                        reserve;      /** <Reserve */                       /** <CNcomment:�������� */
} hi_drv_frontend_diseqc_recalculation;

/** Parameter for USALS */
/** CNcomment:USALS ���� */
typedef struct {
    hi_u16 local_longitude;   /** <local longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude) */
                              /** <CNcomment:���ؾ��ȣ���λ0.1�ȣ�����ȡֵ��Χ0-1800������ȡֵ��Χ1800-3600��ֵΪ3600-����ֵ */
    hi_u16 local_latitude;    /** <local latitude, is 10*latitude, in param N:0-900, S:900-1800(1800-latitude) */
                              /** <CNcomment:����γ�ȣ���λ0.1�ȣ���γȡֵ��Χ0-900����γȡֵ��Χ900-1800��ֵΪ1800-γ��ֵ */
    hi_u16 sat_longitude;     /** <sat longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude) */
                              /** <CNcomment:���Ǿ��ȣ���λ0.1�ȣ�����ȡֵ��Χ0-1800������ȡֵ��Χ1800-3600��ֵΪ3600-����ֵ */
    hi_u16 angular;           /** <calculate result, out param */
                              /** <CNcomment:��������������� */
} hi_drv_frontend_diseqc_usals_para;

/** Parameter for USALS goto angular */
/** CNcomment:USALS�ǶȲ��� */
typedef struct {
    hi_drv_frontend_diseqc_level level;      /** <DiSEqC device level */   /** <CNcomment:�����汾 */
    hi_u16                      angular;     /** <Angular, calculated by hi_drv_frontend_diseqc_calc_angular() */
                                             /** <CNcomment:�Ƕ�ֵ����ͨ������hi_drv_frontend_diseqc_calc_angular����õ� */
} hi_drv_frontend_diseqc_usals_angular;

/** Unicable user band */
/** CNcomment:Unicable �û�Ƶ�� */
typedef struct {
    hi_u32          scr_no;       /** <Unicable user band number */   /** <CNcomment:Unicable �û�Ƶ�κ� */
    hi_s32          center_freq;  /** <Unicable user band center frequency, Unit MHz */
                                  /** <CNcomment:Unicable �û�Ƶ������Ƶ�ʣ���λMHz */
} hi_drv_unicable_scr_ub;

/** Unicable channel change parameter */
/** CNcomment:Unicable ͨ���л����� */
typedef struct {
    hi_u8 ub_num;     /** <Unicable user band number */   /** <CNcomment:Unicable �û�Ƶ�κ� */
    hi_u8 bank;       /** <the signal bank which carries the desired channel */ /** <CNcomment:�ź�bank����������ŵ� */
    hi_u16 t_val;     /** <the tuning word calculated by the receive */ /** <CNcomment:���ն˼���ĵ���ֵ */
} hi_drv_unicable_channel_para;

/** Unicable2 channel change parameter */
/** CNcomment:Unicable2 ͨ���л����� */
typedef struct {
    hi_u8 ub_num;     /** <Unicable user band number */   /** <CNcomment:Unicable �û�Ƶ�κ� */
    hi_u16 t_val;     /** <the tuning word calculated by the receive */ /** <CNcomment:���ն˼���ĵ���ֵ */
    hi_u8 uncommit_switch; /** <uncommit switch */
    hi_u8 commit_switch; /** <commit switch */
} hi_drv_unicable2_channel_para;

/** Unicable2 channel change parameter with pin protection */
/** CNcomment:Unicable2 ��pin�뱣����ͨ���л����� */
typedef struct {
    hi_u8 ub_num;          /** <Unicable user band number */   /** <CNcomment:Unicable �û�Ƶ�κ� */
    hi_u16 t_val;        /** <the tuning word calculated by the receive */ /** <CNcomment:���ն˼���ĵ���ֵ */
    hi_u8 uncommit_switch; /** <uncommit switch */
    hi_u8 commit_switch;   /** <commit switch */
    hi_u8 pin;             /** <pin protection */       /** <CNcomment:pin�뱣�� */
} hi_drv_unicable2_channel_pin_para;

/** Unicable2 switch user band */
/** CNcomment:Unicable2 �л��û�Ƶ�� */
typedef struct {
    hi_u8 ub_num;          /** <Unicable user band number */   /** <CNcomment:Unicable �û�Ƶ�κ� */
    hi_u8 uncommit_switch; /** <uncommit switch */
    hi_u8 commit_switch;   /** <commit switch */
} hi_drv_unicable2_switch_para;

/** tuner attribution */
/** CNcomment:ATV��ʽ��Ϣ */
typedef enum {
    HI_DRV_ATV_SYSTEM_PAL_BG = 0,       /** <PAL BG TV sytem */  /** <CNcomment:PAL BG������ʽ */
    HI_DRV_ATV_SYSTEM_PAL_DK,           /** <PAL DK TV sytem */  /** <CNcomment:PAL DK������ʽ */
    HI_DRV_ATV_SYSTEM_PAL_I,            /** <PAL I TV sytem */   /** <CNcomment:PAL I������ʽ */
    HI_DRV_ATV_SYSTEM_PAL_M,            /** <PAL M TV sytem */   /** <CNcomment:PAL M������ʽ */
    HI_DRV_ATV_SYSTEM_PAL_N,            /** <PAL N TV sytem */   /** <CNcomment:PAL N������ʽ */
    HI_DRV_ATV_SYSTEM_SECAM_BG,         /** <SECAM BG TV sytem */  /** <CNcomment:SECAM BG������ʽ */
    HI_DRV_ATV_SYSTEM_SECAM_DK,         /** <SECAM DK TV sytem */  /** <CNcomment:SECAM DK������ʽ */
    HI_DRV_ATV_SYSTEM_SECAM_L_PRIME,    /** <SECAM L PRIME TV sytem */  /** <CNcomment:SECAM L PRIME������ʽ */
    HI_DRV_ATV_SYSTEM_SECAM_LL,         /** <SECAM LL TV sytem */  /** <CNcomment:SECAM LL������ʽ */
    HI_DRV_ATV_SYSTEM_NTSC_M,           /** <NTSC M TV sytem */    /** <CNcomment:NTSC M������ʽ */
    HI_DRV_ATV_SYSTEM_NTSC_I,           /** <NTSC I TV sytem */    /** <CNcomment:NTSC I ������ʽ */
    HI_DRV_ATV_SYSTEM_NTSC_DK,          /** <NTSC DK TV sytem */    /** <CNcomment:NTSC DK������ʽ */
    HI_DRV_ATV_SYSTEM_MAX              /** <Invalid value */      /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_atv_system;

typedef enum {
    HI_DRV_ATV_SIF_BW_WIDE = 0,  /** <For Auto Scan Mode */  /** <CNcomment:�Զ�äɨģʽ */
    HI_DRV_ATV_SIF_BW_NORMAL,    /** <For Normal Play Mode */ /** <CNcomment:��������ģʽ */
    HI_DRV_ATV_SIF_BW_NARROW,    /** <Not Recommended */  /** <CNcomment:���Ƽ� */
    HI_DRV_ATV_SIF_BW_MAX        /** <Invalid value */ /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_atv_sif_bw;

typedef enum {
    HI_DRV_ATV_CONNECT_WORK_MODE_NORMAL = 0, /** <TVD work mode normal */ /** <CNcomment:connect ��������ģʽ */
    HI_DRV_ATV_CONNECT_WORK_MODE_CHAN_SCAN,  /** <TVD RF channel scan mode */ /** <CNcomment:connect RF��̨ģʽ */
    HI_DRV_ATV_CONNECT_WORK_MODE_MAX,        /** <Invalid value */ /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_atv_connect_work_mode;

/** Tuner step for ATV */
/** CNcomment:TUNER ������ATV�� */
typedef enum {
    HI_DRV_FRONTEDN_ATV_STEP_50KHZ = 0, /** <Frequency step is 50KHz */      /** <CNcomment:50KHz���� */
    HI_DRV_FRONTEDN_ATV_STEP_62_5KHZ,   /** <Frequency step is 62.5KHz */    /** <CNcomment:62.5KHz���� */
    HI_DRV_FRONTEDN_ATV_STEP_31_25KHZ,  /** <Frequency step is 31.25KHz */   /** <CNcomment:31.25Hz���� */
    HI_DRV_FRONTEDN_ATV_STEP_MAX,      /** <Invalid value */                /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_atv_step;

/** Band for ATV */
/** CNcomment:ATV���� */
typedef enum {
    HI_DRV_FRONTEND_ATV_BAND_VHF_LOW = 0,   /** <Low VHF band */             /** <CNcomment: ������Ƶ�� */
    HI_DRV_FRONTEND_ATV_BAND_VHF_HIGH,      /** <High VHF band */            /** <CNcomment: ������Ƶ�� */
    HI_DRV_FRONTEND_ATV_BAND_UHF,           /** <UHF band */                 /** <CNcomment: ����Ƶ�� */
    HI_DRV_FRONTEND_ATV_BAND_ALL,           /** <Include all three bands */  /** <CNcomment: ����������������� */

    HI_DRV_FRONTEND_ATV_BAND_MAX,   /** <Invalid value */                   /** <CNcomment:�Ƿ��߽�ֵ */
} hi_drv_frontend_atv_band;

/** The frequency range */
/** CNcomment: ATV����Ƶ�ʷ�Χ */
typedef struct {
    hi_u32 start_freq;    /** <Start frequency(KHz) */      /** <CNcomment:��ʼƵ�� KHz */
    hi_u32 end_freq;      /** <End frequency(KHz) */        /** <CNcomment:����Ƶ�� KHz */
} hi_drv_frontend_atv_band_range;

typedef struct {
    hi_u32                      freq;    /* Ƶ�ʣ���λkhz */
    hi_drv_atv_system         system;   /* ATV��ʽ */
    hi_drv_atv_sif_bw         sif_bw;    /* Atv sif bandwidth */
    hi_drv_atv_connect_work_mode   connect_work_mode; /* connect mode :scan or switch */
} hi_drv_atv_connect_para;

/** ATV signal information. */
/** CNcomment:ATV�ź���Ϣ */
typedef struct {
    hi_bool vif_lock;           /** < IF locked information or not */       /* ��Ƶ�Ƿ����� */
    hi_bool afc_win;            /** < In the AFC window or not */           /* �Ƿ���AFC�������� */
    hi_bool carr_det;           /** < Detected the audio carrier or not */  /* ��Ƶ�����ز���� */
    hi_s32  afc_freq;         /** < AFC frequency information */          /* AFCƵ��ֵ����λKhz */
} hi_drv_frontend_atv_signal_info;

/** Frequency locking parameters of the tuner */
/** CNcomment:TUNER��Ƶ���� */
typedef struct {
    hi_drv_frontend_sig_type sig_type;    /** <Signal type */                       /** <CNcomment:�ź����� */

    union {
        hi_drv_cab_connect_para cab;      /** <Cable transmission signal */         /** <CNcomment:CABLE�����ź� */
        hi_drv_ter_connect_para ter;      /** <Terrestrial transmission signal */   /** <CNcomment:���洫���ź� */
        hi_drv_sat_connect_para sat;      /** <Satellite transmission signal */     /** <CNcomment:���Ǵ����ź� */
        hi_drv_atv_connect_para atv;      /** <ATV transmission signal */     /** <CNcomment:ģ����Ӵ����ź� */
    } connect_para;
} hi_drv_frontend_connect_para;

/** signal information. */
/** CNcomment:TUNER�ź����� */
typedef struct {
    hi_drv_frontend_sig_type sig_type;              /** <Signal transmission type */    /** <CNcomment:�ź����� */

    union {
        hi_drv_frontend_dvbs2x_signal_info dvbs2x;  /** <Signal info of satellite */ /** <CNcomment:�����ź���Ϣ */
        hi_drv_frontend_dvbt_signal_info   dvbt;    /** <Signal info of DVB-T */     /** <CNcomment:����dvbt�ź���Ϣ */
        hi_drv_frontend_dvbt2_signal_info  dvbt2;   /** <Signal info of DVB-T2 */    /** <CNcomment:����dvbt2�ź���Ϣ */
        hi_drv_frontend_isdbt_signal_info  isdbt;   /** <Signal info of ISDB-T  */   /** <CNcomment:����ISDB-T�ź���Ϣ */
        hi_drv_frontend_dtmb_signal_info   dtmb;    /** <Signal info of dtmb */      /** <CNcomment:����dtmb�ź���Ϣ */
        hi_drv_frontend_atv_signal_info    atv;
    } signal_info;
} hi_drv_frontend_signal_info;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_DRV_ECS_TYPE_H__ */

