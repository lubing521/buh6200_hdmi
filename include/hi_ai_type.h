/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: audio input (AI) module header file
 * Author: audio
 * Create: 2019-05-26
 * Notes: NA
 * History: 2019-05-26 Initial version for Hi3796CV300
 */

#ifndef __HI_AI_TYPE_H__
#define __HI_AI_TYPE_H__

#include "hi_drv_audio.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/* audio inputport defination */
/* CNcomment: ��Ƶ����˿ڶ��� */
typedef enum {
    HI_AI_I2S0 = 0,
    HI_AI_I2S1,
    HI_AI_I2S2,
    HI_AI_I2S3,
    HI_AI_I2S4,
    HI_AI_ADC0 = 0x10,
    HI_AI_ADC1,
    HI_AI_ADC2,
    HI_AI_ADC3,
    HI_AI_ADC4,
    HI_AI_SIF0 = 0x20,
    HI_AI_HDMI0 = 0x30,
    HI_AI_HDMI1,
    HI_AI_HDMI2,
    HI_AI_HDMI3,
    HI_AI_MAX = 0xff,
} hi_ai_port;

/* defines internal audio ADC inputport attribute */
/* CNcomment: ����������ƵADC����˿����� */
typedef struct {
    hi_bool by_pass;
} hi_ai_adc_attr;

/* defines audio I2S inputport attribute */
/* CNcomment: ������ƵI2S����˿����� */
typedef struct {
    hi_i2s_attr attr; /* <I2S attribute */ /* <CNcomment: I2S���� */
} hi_ai_i2s_attr;

/* defines the HDMI RX audio data format . */
typedef enum {
    /* LPCM 2/8 channels, audio sample packet layout0 or layout1 */
    HI_AI_HDMI_FORMAT_LPCM = 0,

    /* IEC-61937 DD/DDP/DTS, audio sample packet layout0 */
    HI_AI_HDMI_FORMAT_LBR = 1,

    /* IEC-61937 DTSHD/true_hd, high-bitrate (HBR) audio stream packet */
    HI_AI_HDMI_FORMAT_HBR = 8,

    HI_AI_HDMI_FORMAT_MAX
} hi_ai_hdmi_format;

/* defines  HDMI audio inputport attribute */
/* CNcomment: ����HDMI��Ƶ����˿����� */
typedef struct {
    hi_i2s_channel channel; /* <channel number */ /* <CNcomment: ͨ���� */
    hi_i2s_bit_depth bit_depth; /* <bit depth */ /* <CNcomment: λ�� */
    hi_sample_rate sample_rate; /* <sample rate */ /* <CNcomment: ������ */
    hi_ai_hdmi_format hdmi_audio_data_format; /* <HDMI audio data format */ /* <CNcomment: HDMI��Ƶ���ݸ�ʽ */
} hi_ai_hdmi_attr;

/* defines internal SIF(audio demodulator) inputport attribute */
/* CNcomment: ����SIF����˿����� */
typedef struct {
    hi_void *para;
} hi_ai_sif_attr;

/* defines audio inputport attribute */
/* CNcomment: ������Ƶ����˿����� */
typedef struct {
    /* <samplerate, default 48000_hz */ /* <CNcomment: �豸����Ƶ�ʣ�Ĭ�� 48000_hz */
    hi_sample_rate sample_rate;

    /* <max frame of the PCM data at cast buffer, default 16 */ /* <CNcomment: ���ɻ���֡����Ĭ��16 */
    hi_u32 pcm_frame_max_num;

    /* <number of sample of the PCM data, default 960 */ /* <CNcomment: PCM���ݲ�����������Ĭ��960 */
    hi_u32 pcm_samples_per_frame;
    union {
        hi_ai_adc_attr adc_attr;   /* <ADC attribute */ /* <CNcomment: ADC���� */
        hi_ai_i2s_attr i2s_attr;   /* <I2S attribute */ /* <CNcomment: I2S���� */
        hi_ai_hdmi_attr hdmi_attr; /* <HDMI attribute */ /* <CNcomment: HDMI���� */
    } un_attr;
} hi_ai_attr;

/* defines AI delay attribute */
/* CNcomment: ����AI�ӳ����� */
typedef struct {
    /* <buffer delay compensation(ms), min value is 20, max value depends on pcm_frame_max_num, pcm_samples_per_frame and sample_rate in hi_ai_attr.
       max_value = pcm_samples_per_frame * pcm_frame_max_num * 1000 / sample_rate.
       max_value is equal to 320ms according to default hi_ai_attr */
    /* <CNcomment:�������������ӳٲ�������(ms), ��СֵΪ20ms�����ֵ����hi_ai_attr�е�pcm_frame_max_num��pcm_samples_per_frame�Լ�sample_rate
       ���㹫ʽ:max_value = pcm_samples_per_frame * pcm_frame_max_num * 1000 / sample_rate��
       ������Ĭ��hi_ai_attr�������ֵΪ320ms */
    hi_u32 delay;

    /* <if hold buffer delay compensation time automatically */
    /* <CNcomment: �Ƿ���AI_AOͨ·�Զ����ֻ����������ȶ���compensation_ms */
    hi_bool delay_auto_hold;
} hi_ai_delay;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_AI_TYPE_H__ */

