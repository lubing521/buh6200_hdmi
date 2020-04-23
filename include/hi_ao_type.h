/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: audio common codec layer.
 * Author: audio
 * Create: 2019-05-26
 * Notes:
 * History: 2019-05-26 audio common for Hi3796CV300
 */

#ifndef __HI_AO_TYPE_H__
#define __HI_AO_TYPE_H__

#include "hi_drv_audio.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/********************************macro definition*****************************/
/* maximum sound outputport */
/* CNcomment: ���sound����˿� */
#define HI_AO_OUTPUT_PORT_MAX (16)
#define HI_AO_EQ_BAND_NUM_MAX (10)

/*************************** structure definition ****************************/
/* defines the ID of the audio output (AO) device. */
/* CNcomment: ������Ƶ����豸�� */
typedef enum {
    /* AO device 0 */ /* CNcomment: ��Ƶ����豸0. */
    AO_SND_0,

    /* AO device 1 */ /* CNcomment: ��Ƶ����豸1. */
    AO_SND_1,

    /* AO device 2 */ /* CNcomment: ��Ƶ����豸2. */
    AO_SND_2,

    AO_SND_MAX
} ao_snd_id;

/* audio volume attribute */
/* CNcomment: ��Ƶ�������� */
typedef struct {
    hi_bool linear_mode; /* gain type of volume */ /* CNcomment: ����ģʽ */
    hi_s32 gain;         /* linear gain(linear_mode is HI_TRUE), ranging from 0 to 100 */
                         /* CNcomment: ��������: 0~100 */
                         /* decibel gain(linear_mode is HI_FALSE), ranging from -70db to 0db */
                         /* CNcomment: db����:-70~0 */
} hi_ao_gain;

/* audio L/R channel volume attribute */
/* CNcomment: ��Ƶ���������������� */
typedef struct {
    hi_bool linear_mode; /* gain type */ /* CNcomment:����ģʽ */
    hi_s32 gain_l;       /* linear left ch gain(linear_mode is HI_TRUE), ranging from 0 to 100 */
                         /* CNcomment: ��������������: 0~100 */
                         /* decibel left ch gain(linear_mode is HI_FALSE), ranging from -81db to 18db */
                         /* CNcomment: ������d_b����:-81~+18 */
    hi_s32 gain_r;       /* linear right ch gain(linear_mode is HI_TRUE), ranging from 0 to 100 */
                         /* CNcomment: ��������������: 0~100 */
                         /* decibel right ch gain(linear_mode is HI_FALSE), ranging from -81db to 18db */
                         /* CNcomment: ������db����:-81~+18 */
} hi_ao_abs_gain;

/* high precision gain, ranging from -81db to 18db, step 0.125db */
/* CNcomment:�߾������棬��Χ��-81db��18db������Ϊ0.125db */
typedef struct {
    /* interger part of high precision gain */ /* CNcomment: �߾���������������� */
    hi_s32 integer;

    /* decimal part of high precision gain, if -0.125db, value is -125 */
    /* CNcomment: �߾��������С������ ��0.125����ֵΪ125 */
    hi_s32 decimal;
} hi_ao_preci_gain;

/* audio track type: master, slave, virtual channel,low_latency channel */
/* CNcomment: ��Ƶtrack����: ��ͨ�� ��ͨ�� ����ͨ�� ����ʱͨ�� */
/* low_latency channel not support attach avplay and the data only support 48K,stereo,16_bit.
 * only support one low latency track in a sound
 */
/* CNcomment: ����ʱͨ����֧��AVPLAY�󶨣���ͨ��ֻ֧�ֲ�����Ϊ48K,˫����,16λλ�����Ƶ����,��֧�ִ���һ������ʱͨ�� */
typedef enum {
    HI_AO_TRACK_TYPE_MASTER = 0,
    HI_AO_TRACK_TYPE_SLAVE,
    HI_AO_TRACK_TYPE_VIRTUAL,
    HI_AO_TRACK_TYPE_LOW_LATENCY,
    HI_AO_TRACK_TYPE_OTT_SOUND,    /* ott sound(PCM) MS12 ONLY. such as app ui audio */
    HI_AO_TRACK_TYPE_SYSTEM_AUDIO, /* system sound(PCM) MS12 ONLY. */
    HI_AO_TRACK_TYPE_APP_AUDIO,    /* app audio(PCM) MS12 ONLY. such as tts audio */
    HI_AO_TRACK_TYPE_MAX
} hi_ao_track_type;

/* audio output attribute */
/* CNcomment:��Ƶ������� */
typedef struct {
    /* track type */ /* CNcomment: track���� */
    hi_ao_track_type track_type;

    /* fade in time(unit:ms) */ /* CNcomment: ����ʱ��(��λ: ms) */
    hi_u32 fade_in;

    /* fade out time(unit:ms) */ /* CNcomment: ����ʱ��(��λ: ms) */
    hi_u32 fade_out;

    /* track output buffer size */ /* CNcomment: track��������С */
    hi_u32 output_buf_size;

    /* output buffer data size control(ms),default 400ms */
    /* CNcomment: �������������������(ms),Ĭ��400ms */
    hi_u32 buf_level;

    /* track start threshold (ms), default value is 50ms,
       max value is equal to buf_level_ms, only valid for master track */
    /* CNcomment: track�������ޣ�Ĭ��ֵ��50ms�����ֵΪbuf_level_ms��������ֻ��master track��Ч */
    hi_u32 start_threshold;
} hi_ao_track_attr;

/* audiotrack config parameter */
/* CNcomment: ��Ƶ track���ò��� */
typedef struct {
    hi_u32  type; /* track config type */ /* CNcomment: track�������� */
    hi_void *data; /* track config data */ /* CNcomment: track�������� */
} hi_ao_track_config;

/* audio outputport: DAC0,I2S0,SPDIF0,HDMI0,ARC0 */
/* CNcomment: ��Ƶ����˿�:DAC0,I2S0,SPDIF0,HDMI0,ARC0 */
typedef enum {
    HI_AO_PORT_DAC0 = 0,
    HI_AO_PORT_DAC1,
    HI_AO_PORT_DAC2,
    HI_AO_PORT_DAC3,

    HI_AO_PORT_I2S0 = 0x10,
    HI_AO_PORT_I2S1,
    HI_AO_PORT_I2S2,
    HI_AO_PORT_I2S3,
    HI_AO_PORT_I2S4,

    HI_AO_PORT_SPDIF0 = 0x20,

    HI_AO_PORT_HDMI0 = 0x30,
    HI_AO_PORT_HDMI1,

    HI_AO_PORT_ARC0 = 0x40,
    HI_AO_PORT_ARC1,

    HI_AO_PORT_ALL = 0x7fff,

    HI_AO_PORT_MAX,
} hi_ao_port;

/* defines internal audio DAC outport attribute */
/* CNcomment: ����������ƵDAC����˿����� */
typedef struct {
    hi_u32 reserved;
} hi_ao_dac_attr;

/* defines  audio I2S outport attribute */
/* CNcomment: ������ƵI2S����˿����� */
typedef struct {
    hi_i2s_attr attr;
} hi_ao_i2s_attr;

/* defines  S/PDIF outport attribute */
/* CNcomment: ����S/PDIF����˿����� */
typedef struct {
    hi_u32 reserved;
} hi_ao_spdif_attr;

/* defines  HDMI audio outport attribute */
/* CNcomment: ����HDMI��Ƶ����˿����� */
typedef struct {
    hi_u32 reserved;
} hi_ao_hdmi_attr;

/* defines  HDMI ARC outport attribute */
/* CNcomment: ����HDMI��Ƶ�ش�ͨ���˿����� */
typedef struct {
    hi_u32 reserved;
} hi_ao_arc_attr;

/* defines ARC audio capbilities */
/* CNcomment: ARC��Ƶ���� */
typedef struct {
    /* < Audio capability,reference EIA-CEA-861-D,table 37,HI_TRUE:support this Audio type;
    HI_FALSE,nonsupport this Audio type */
    /* < CNcomment: ��Ƶ������, ��ο�EIA-CEA-861-D ��37;HI_TRUE��ʾ֧��������ʾ��ʽ��HI_FALSE��ʾ��֧�� */
    hi_bool audio_fmt_supported[HI_AUDIO_FORMAT_CXT];
} hi_ao_arc_audio_cap;

/* defines  audio outport attribute */
/* CNcomment: ������Ƶ����˿����� */
typedef struct {
    hi_ao_port port;
    union {
        hi_ao_dac_attr   dac_attr;
        hi_ao_i2s_attr   i2s_attr;
        hi_ao_spdif_attr spdif_attr;
        hi_ao_hdmi_attr  hdmi_attr;
        hi_ao_arc_attr   arc_attr;
    } un_attr;
} hi_ao_port_attr;

/* defines audio sound device attribute */
/* CNcomment: ����sound�豸���� */
typedef struct {
    /* outport number attached sound */ /* CNcomment: �󶨵�sound�豸������˿��� */
    hi_u32 port_num;

    /* outports attached sound */ /* CNcomment: �󶨵�sound�豸������˿� */
    hi_ao_port_attr outport[HI_AO_OUTPUT_PORT_MAX];

    /* sound samplerate */ /* CNcomment: sound�豸��������� */
    hi_sample_rate sample_rate;

    /* sound master channel buffer size */ /* CNcomment: sound�豸�����ͨ�������С */
    hi_u32 master_output_buf_size;

    /* sound slave channel buffer size */ /* CNcomment: sound�豸�����ͨ�������С */
    hi_u32 slave_output_buf_size;
} hi_ao_attr;

/* defines  render attribute */
/* CNcomment: ����render�������� */
typedef struct {
    hi_char *comm_path;
} hi_ao_render_attr;

/* define SND CAST config  struct */
/* CNcomment: ���������������ýṹ�� */
typedef struct {
    /* Max frame of the PCM data at cast buffer */
    /* CNcomment: ���ɻ���֡�� */
    hi_u32 pcm_frame_max_num;

    /* Number of sample of the PCM data */
    /* CNcomment: PCM���ݲ��������� */
    hi_u32 pcm_samples;

    /* Cast Output samplerate */
    /* CNcomment:Cast��������� */
    hi_sample_rate sample_rate;

    /* Cast Output bitdepth */
    /* CNcomment:Cast���λ�� */
    hi_bit_depth bit_depth;

    /* Add mute frame in cast or not */
    /* CNcomment: cast�Ƿ���뾲��֡ */
    hi_bool add_mute;

    /* Cast Output channels */
    /* CNcomment:Cast��������� */
    hi_u32 channels;
} hi_ao_cast_attr;

/* HDMI MODE: AUTO,LPCM,RAW,HBR2LBR */
/* CNcomment: HDMI ģʽ:AUTO,LPCM,RAW,HBR2LBR */
typedef enum {
    /* LCPM2.0 */ /* CNcomment: ������pcm */
    HI_AO_OUTPUT_MODE_LPCM = 0,

    /* pass-through. */ /* CNcomment: ͸�� */
    HI_AO_OUTPUT_MODE_RAW,

    /* pass-through force high-bitrate to low-bitrate. */ /* CNcomment: �����������Ƶ�������� */
    HI_AO_OUTPUT_MODE_HBR2LBR,

    /* automatically match according to the EDID of HDMI */ /* CNcomment: ����HDMI EDID�����Զ�ƥ�� */
    HI_AO_OUTPUT_MODE_AUTO,

    HI_AO_OUTPUT_MODE_MAX
} hi_ao_ouput_mode;

/* SPDIF category code setting */
/* CNcomment: ����SPDIF category code���� */
typedef enum {
    /* broadcast reception of digitally encoded audio
       with/without video signals */
    /* general */ /* CNcomment: ͨ�� */
    HI_AO_SPDIF_CATEGORY_GENERAL = 0x00,

    /* japan */ /* CNcomment:�ձ� */
    HI_AO_SPDIF_CATEGORY_BROADCAST_JP = 0x10,

    /* united states */ /* CNcomment:���� */
    HI_AO_SPDIF_CATEGORY_BROADCAST_USA,

    /* digital converter & signal-processing products */
    /* europe */ /* CNcomment:ŷ�� */
    HI_AO_SPDIF_CATEGORY_BROADCAST_EU,

    /* PCM encoder/decoder */ /* CNcomment: PCM����� */
    HI_AO_SPDIF_CATEGORY_PCM_CODEC = 0x20,

    /* digital sound sampler */ /* CNcomment: ������Ƶ������ */
    HI_AO_SPDIF_CATEGORY_DIGITAL_SNDSAMPLER,

    /* digital signal mixer */ /* CNcomment: �����źŻ����� */
    HI_AO_SPDIF_CATEGORY_DIGITAL_MIXER,

    /* digital sound processor */ /* CNcomment: ������Ƶ������ */
    HI_AO_SPDIF_CATEGORY_DIGITAL_SNDPROCESSOR,

    /* laser optical products */
    /* sample rate converter */ /* CNcomment: ������ת���� */
    HI_AO_SPDIF_CATEGORY_SRC,

    /* mini_disc */ /* CNcomment: ����Ź��� */
    HI_AO_SPDIF_CATEGORY_MD = 0x30,

    /* musical instruments, microphones and other sources
       that create original sound */
    /* digital versatile disc */ /* CNcomment: ���ֶ๦�ܹ��� */
    HI_AO_SPDIF_CATEGORY_DVD,

    /* synthesiser */ /* CNcomment: �ϳ��� */
    HI_AO_SPDIF_CATEGORY_SYNTHESISER = 0x40,

    /* magnetic tape or magnetic disc based products */
    /* microphone */ /* CNcomment: ��˷� */
    HI_AO_SPDIF_CATEGORY_MIC,

    /* digital audio tape */ /* CNcomment: ����¼���� */
    HI_AO_SPDIF_CATEGORY_DAT = 0x50,

    /* digital compact cassette */ /* CNcomment: ���ֺ�ʽ�Ŵ�¼���� */
    HI_AO_SPDIF_CATEGORY_DCC,

    /* video cassette recorder */ /* CNcomment: ��ʽ�Ŵ�¼��� */
    HI_AO_SPDIF_CATEGORY_VCR,

    HI_AO_SPDIF_CATEGORY_MAX
} hi_ao_spdif_category_code;

/* SPDIF SCMS mode setting */
/* CNcomment: ����SPDIF SCMSģʽ */
typedef enum {
    /* copy allow */ /* CNcomment: ������ */
    HI_AO_SPDIF_SCMS_MODE_COPY_ALLOW,

    /* copy once */ /* CNcomment: �ɸ���һ�� */
    HI_AO_SPDIF_SCMS_MODE_COPY_ONCE,

    /* copy no_more */ /* CNcomment: ���ɸ��� */
    HI_AO_SPDIF_SCMS_MODE_COPY_NOMORE,

    /* copy prohibited */ /* CNcomment: ��ֹ���� */
    HI_AO_SPDIF_SCMS_MODE_COPY_PROHIBITED,

    HI_AO_SPDIF_SCMS_MODE_MAX
} hi_ao_spdif_scms_mode;

/* audio effect type, ha_audio_effect_type keep consistent with effect type of ARM/DSP */
/* CNcomment: ��Ч���ͣ�ha_audio_effect_type ���� ARM/DSP ����Ψһֵ */
typedef enum {
    /* dolby audio effect */ /* CNcomment: dolby��Ч */
    HI_AO_AEF_TYPE_DOLBY = 0x000,

    /* SRS audio effect */ /* CNcomment: SRS��Ч */
    HI_AO_AEF_TYPE_SRS3D = 0x010,

    /* base audio effect */ /* CNcomment: ������Ч */
    HI_AO_AEF_TYPE_BASE = 0x080,
} hi_ao_aef_type;

typedef enum {
    /* high-pass filter */ /* CNcomment: ��ͨ�˲��� */
    HI_AO_PEQ_FILTER_TYPE_HP = 0,

    /* low-shelving filte r */ /* CNcomment: ��Ƶ����˲��� */
    HI_AO_PEQ_FILTER_TYPE_LS = 1,

    /* peaking filter */ /* CNcomment: ��ֵ�˲��� */
    HI_AO_PEQ_FILTER_TYPE_PK = 2,

    /* high-shelving filter */ /* CNcomment: ��Ƶ����˲��� */
    HI_AO_PEQ_FILTER_TYPE_HS = 3,

    /* low-pass filter */ /* CNcomment: ��ͨ�˲��� */
    HI_AO_PEQ_FILTER_TYPE_LP = 4,

    HI_AO_PEQ_FILTER_TYPE_MAX
} hi_ao_peq_filter_type;

/* defines PEQ band attribute */
/* CNcomment: PEQ Ƶ������ */
typedef struct {
    /* filter type of the band */ /* CNcomment: ĳһƵ�����˲������� */
    hi_ao_peq_filter_type type;

    /* center frequency of the band, HP and LS[20, 4000], PK[20, 22000], HS[4000, 22000], LP[50, 22000] */
    /* CNcomment: ĳһƵ��������Ƶ��,��Χ: HP and LS[20, 4000], PK[20, 22000], HS[4000, 22000], LP[50, 22000] */
    hi_u32 freq;

    /* Q value of the band, if 2.5, value is 25, range:HS and LS[0.7, 1], PK[0.5, 10],HP and LP is fix to be 0.7 */
    /* CNcomment: ĳһƵ����qֵ,��ֵΪ2.5,����ֵΪ25,��Χ: HS and LS[0.7, 1], PK[0.5, 10], �ߵ�ͨ�ڲ��̶�Ϊ0.7 */
    hi_u32 q;

    /* gain of the band, if -2.125, value is -2125,gain ranging from -15 to 15 step by 0.125db */
    /* CNcomment: ĳһƵ��������,��ֵΪ-2.125,����ֵΪ-2125,��Χ:[-15, 15],����0.125 */
    hi_s32 gain;
} hi_ao_peq_band_attr;

/* defines PEQ attribute */
/* CNcomment: PEQ���� */
typedef struct {
    /* the PEQ band number,band_num ranging from 5 to 10 */
    /* CNcomment: PEQƵ������,��Χ:[5,10] */
    hi_u32 band_num;

    /* PEQ band attribute */ /* CNcomment: PEQƵ������ */
    hi_ao_peq_band_attr param[HI_AO_EQ_BAND_NUM_MAX];
} hi_ao_peq_attr;

/* defines GEQ band attribute */
/* CNcomment: GEQ Ƶ������ */
typedef struct {
    /* < center frequency of the band */ /* < CNcomment: ĳһƵ��������Ƶ�� */
    hi_u32 freq;

    /* < gain of the band, if -2.125, value is -2125,Gain ranging from -15 to 15 step by 0.125dB */
    /* < CNcomment: ĳһƵ��������,��ֵΪ-2.125,����ֵΪ-2125, ��ΧΪ-15��15 */
    hi_u32 gain;
} hi_ao_geq_band_attr;

/* defines GEQ attribute */
/* CNcomment: GEQ���� */
typedef struct {
    /* < the GEQ band number, ranging from 5 to 10 */ /* < CNcomment: GEQƵ������,��ΧΪ5��10 */
    hi_u32 band_num;

    /* < GEQ band attribute */ /* < CNcomment: GEQƵ������ */
    hi_ao_geq_band_attr param[HI_AO_EQ_BAND_NUM_MAX];
} hi_ao_geq_attr;

/* defines DRC attribute */
/* CNcomment: DRC���� */
typedef struct {
    /* the attack time(unit:ms),ranging from 20 to 2000 */ /* CNcomment: ��ʼ��Чʱ��(��λ:ms),��Χ:[20, 2000] */
    hi_u32 attack_time;

    /* the release time(unit:ms),ranging from 20 to 2000 */ /* CNcomment: ��ʼʧЧʱ��(��λ:ms),��Χ:[20, 2000] */
    hi_u32 release_time;

    /* the threshold value, if -2.125, value is -2125, threshold ranging from -80db to -1db step by 0.125db */
    /* CNcomment: ��ʼ�޷���ֵ,��ֵΪ-2.125,����ֵΪ-2125,����Ϊ0.125db,��Χ:[-80db, -1db) */
    hi_s32 threshold;

    /* the maximum value, if -2.125, value is -2125, threshold ranging from -80db to -1db step by 0.125db */
    /* CNcomment: ����޷���ֵ,��ֵΪ-2.125,����ֵΪ-2125,����Ϊ0.125db,��Χ:[-80db, -1db) */
    hi_s32 limit;

    /* refmode(0: process both channel together mode, 1: process each channel independently mode) */
    /* CNcomment: 0, ԭʼ�汾Ч��; 1������������; ����������Ч */
    hi_u32 ref_mode;

    /* speedctrlmode(0:normal mode, 1:fast mode) */ /* CNcomment: 0, ԭʼ�汾Ч��; 1, �Ͽ��ٿ���; ����������Ч */
    hi_u32 speed_ctrl_mode;
} hi_ao_drc_attr;

/* defines  AVC attribute */
/* CNcomment: AVC���� */
typedef struct {
    /* the threshold value, if -32.125, value is -32125, ranging from -40db to -16db step by 0.125db */
    /* CNcomment: �ﵽ���̧�������ת�۵�ƽ,��ֵΪ-32.125,����ֵΪ-32125,����Ϊ0.125db,��Χ(-40db, -16db) */
    hi_s32 threshold;

    /* the gain value, if 2.125, value is 2125,ranging from 0db to 8db step by 0.125db */
    /* CNcomment: ̧������,��ֵΪ2.125,����ֵΪ2125,����Ϊ0.125db,��Χ:[0db, 8db] */
    hi_s32 gain;

    /* the target level value, if -2.125, value is -2125, ranging from -40db to 0db step by 0.125db */
    /* CNcomment:Ŀ��ֵ,��ֵΪ-2.125,����ֵΪ-2125,����Ϊ0.125db,��Χ:(-40db, 0db] */
    hi_s32 limit;

    /* the attack time(unit:ms),ranging from 20 to 2000,default value 50(recommended) */
    /* CNcomment: ��ʼ��Чʱ��(��λ:ms),��Χ:[20, 2000]��Ĭ��ֵ50���������޸� */
    hi_u32 attack_time;

    /* the release time(unit:ms),ranging from 20 to 2000,default value 100(recommended) */
    /* CNcomment: ��ʼʧЧʱ��(��λ:ms),��Χ:[20, 2000]��Ĭ��ֵ100���������޸� */
    hi_u32 release_time;
} hi_ao_avc_attr;

/* audio output latency mode */
/* CNcomment: ��Ƶ���ʱ��ģʽ */
typedef enum {
    /* normal latency MS12 ONLY. */ /* CNcomment: ͨ��ʱ�� */
    HI_AO_OUTPUT_LATENCY_NORMAL = 0,

    /* low latency MS12 ONLY */ /* CNcomment: ��ʱ�� */
    HI_AO_OUTPUT_LATENCY_LOW,

    HI_AO_OUTPUT_LATENCY_MAX,
} hi_ao_output_latency;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_AO_TYPE_H__ */

