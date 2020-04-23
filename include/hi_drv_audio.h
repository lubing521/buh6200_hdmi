/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: audio common header file
 * Author: audio
 * Create: 2019-05-26
 * Notes: NA
 * History: 2019-05-26 Initial version for Hi3796CV300
 */

#ifndef __HI_DRV_AUDIO_H__
#define __HI_DRV_AUDIO_H__

#include "hi_type.h"
#include "hi_errno.h"
#include "hi_debug.h"

#if defined(__KERNEL__)
#include "linux/hisilicon/securec.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

typedef enum {
    /* unknown *//* CNcomment: δ֪����Ƶ�� */
    HI_SAMPLE_RATE_UNKNOWN = 0,

    /* 4 kHz sampling rate *//* CNcomment: 4K����Ƶ�� */
    HI_SAMPLE_RATE_4K = 4000,

    /* 8 kHz sampling rate *//* CNcomment: 8K����Ƶ�� */
    HI_SAMPLE_RATE_8K = 8000,

    /* 11.025 kHz sampling rate *//* CNcomment: 11.025K����Ƶ�� */
    HI_SAMPLE_RATE_11K = 11025,

    /* 12 kHz sampling rate *//* CNcomment: 12K����Ƶ�� */
    HI_SAMPLE_RATE_12K = 12000,

    /* 16 kHz sampling rate *//* CNcomment: 16K����Ƶ�� */
    HI_SAMPLE_RATE_16K = 16000,

    /* 22.050 kHz sampling rate *//* CNcomment: 22.050K����Ƶ�� */
    HI_SAMPLE_RATE_22K = 22050,

    /* 24 kHz sampling rate *//* CNcomment: 24K����Ƶ�� */
    HI_SAMPLE_RATE_24K = 24000,

    /* 32 kHz sampling rate *//* CNcomment: 32K����Ƶ�� */
    HI_SAMPLE_RATE_32K = 32000,

    /* 44.1 kHz sampling rate *//* CNcomment: 44.1K����Ƶ�� */
    HI_SAMPLE_RATE_44K = 44100,

    /* 48 kHz sampling rate *//* CNcomment: 48K����Ƶ�� */
    HI_SAMPLE_RATE_48K = 48000,

    /* 88.2 kHz sampling rate *//* CNcomment: 88.2K����Ƶ�� */
    HI_SAMPLE_RATE_88K = 88200,

    /* 96 kHz sampling rate *//* CNcomment: 96K����Ƶ�� */
    HI_SAMPLE_RATE_96K = 96000,

    /* 176 kHz sampling rate *//* CNcomment: 176K����Ƶ�� */
    HI_SAMPLE_RATE_176K = 176400,

    /* 192 kHz sampling rate *//* CNcomment: 192K����Ƶ�� */
    HI_SAMPLE_RATE_192K = 192000,

    /* 288 kHz sampling rate *//* CNcomment: 288K����Ƶ�� */
    HI_SAMPLE_RATE_288K = 288000,

    HI_SAMPLE_RATE_MAX = 0xffffffff,
} hi_sample_rate;

/* defines the bit depth during audio sampling. */
/* CNcomment: ������Ƶ����λ��ö�� */
typedef enum {
    /* unknown *//* CNcomment: δ֪����λ�� */
    HI_BIT_DEPTH_UNKNOWN = 0,

    /* 8-bit depth *//* CNcomment: 8λ����λ�� */
    HI_BIT_DEPTH_8 = 8,

    /* 16-bit depth *//* CNcomment: 16λ����λ�� */
    HI_BIT_DEPTH_16 = 16,

    /* 18-bit depth *//* CNcomment: 18λ����λ�� */
    HI_BIT_DEPTH_18 = 18,

    /* 20-bit depth *//* CNcomment: 20λ����λ�� */
    HI_BIT_DEPTH_20 = 20,

    /* 24-bit depth *//* CNcomment: 24λ����λ�� */
    HI_BIT_DEPTH_24 = 24,

    /* 32-bit depth *//* CNcomment: 32λ����λ�� */
    HI_BIT_DEPTH_32 = 32,

    HI_BIT_DEPTH_MAX = 0xffffffff,
} hi_bit_depth;

/* defines the mode of audio channels. */
/* CNcomment: ������Ƶ����ģʽö�� */
typedef enum {
    /* stereo *//* CNcomment: ������ */
    HI_TRACK_MODE_STEREO = 0,

    /* data is output after being mixed in the audio-left channel and audio-right channel. */
    /* CNcomment: ����������Ϻ���� */
    HI_TRACK_MODE_DOUBLE_MONO,

    /* the audio-left channel and audio-right channel output the data of the audio-left channel. */
    /* CNcomment: ��������������������� */
    HI_TRACK_MODE_DOUBLE_LEFT,

    /* the audio-left channel and audio-right channel output the data of the audio-right channel. */
    /* CNcomment: ��������������������� */
    HI_TRACK_MODE_DOUBLE_RIGHT,

    /* data is output after being exchanged in the audio-left channel and audio-right channel. */
    /* CNcomment: �����������ݽ������ */
    HI_TRACK_MODE_EXCHANGE,

    /* only the data in the audio-right channel is output. *//* CNcomment: ֻ������������� */
    HI_TRACK_MODE_ONLY_RIGHT,

    /* only the data in the audio-left channel is output. *//* CNcomment: ֻ������������� */
    HI_TRACK_MODE_ONLY_LEFT,

    /* mute *//* CNcomment: ���� */
    HI_TRACK_MODE_MUTED,

    HI_TRACK_MODE_MAX
} hi_track_mode;

/* defines audio channels. */
/* CNcomment: ������Ƶ������ö�� */
typedef enum {
    HI_AUDIO_CH_INVALID = -1,
    HI_AUDIO_CH_MONO    = 1,
    HI_AUDIO_CH_STEREO  = 2,
    HI_AUDIO_CH_6       = 6,
    HI_AUDIO_CH_8       = 8,
    HI_AUDIO_CH_16      = 16,

    HI_AUDIO_CH_MAX     = 0xffffffff,
} hi_audio_channel;

/* supported audio channel mode */
/* CNcomment: ������Ƶ����ģʽö�� */
typedef enum {
    HI_ACMOD_INVALID    = -2,
    HI_ACMOD_RAW        = -1,
    HI_ACMOD_ONEPLUSONE =  0,
    HI_ACMOD_MONO       =  1,
    HI_ACMOD_STEREO     =  2,
    HI_ACMOD_3_0        =  3,
    HI_ACMOD_2_1        =  4,
    HI_ACMOD_3_1        =  5,
    HI_ACMOD_2_2        =  6,
    HI_ACMOD_3_2        =  7,
    HI_ACMOD_3_4        = 21,
    HI_ACMOD_3_2_2      = 28
} hi_acmod;

/* defines the I2S(inter-IC sound) mode. */
/* CNcomment: ������ƵI2S�ӿ�ģʽö�� */
typedef enum {
    /* I2S standard mode *//* CNcomment: I2S��׼ģʽ */
    HI_I2S_STD_MODE = 0,

    /* pcm mode *//* CNcomment: PCMģʽ */
    HI_I2S_PCM_MODE,

    /* TDM mode *//* CNcomment: TDMģʽ */
    HI_I2S_TDM_MODE,

    HI_I2S_MODE_MAX
} hi_i2s_mode;

/* defines the I2S(inter-IC sound) master clock. */
/* CNcomment: ������ƵI2S�ӿڹ���ʱ��ö�� */
typedef enum {
    HI_I2S_MCLK_128_FS = 0, /* mclk 128*fs */
    HI_I2S_MCLK_256_FS,     /* mclk 256*fs */
    HI_I2S_MCLK_384_FS,     /* mclk 384*fs */
    HI_I2S_MCLK_512_FS,     /* mclk 512*fs */
    HI_I2S_MCLK_768_FS,     /* mclk 768*fs */
    HI_I2S_MCLK_1024_FS,    /* mclk 1024*fs */

    HI_I2S_MCLK_MAX
} hi_i2s_mclk;

/* defines the I2S(inter-IC sound) bclk clock. */
typedef enum {
    HI_I2S_BCLK_1_DIV  = 1,   /* bclk mclk/1 */
    HI_I2S_BCLK_2_DIV  = 2,   /* bclk mclk/2 */
    HI_I2S_BCLK_3_DIV  = 3,   /* bclk mclk/3 */
    HI_I2S_BCLK_4_DIV  = 4,   /* bclk mclk/4 */
    HI_I2S_BCLK_6_DIV  = 6,   /* bclk mclk/6 */
    HI_I2S_BCLK_8_DIV  = 8,   /* bclk mclk/8 */
    HI_I2S_BCLK_12_DIV = 12,  /* bclk mclk/12 */
    HI_I2S_BCLK_24_DIV = 24,  /* bclk mclk/24 */
    HI_I2S_BCLK_32_DIV = 32,  /* bclk mclk/32 */
    HI_I2S_BCLK_48_DIV = 48,  /* bclk mclk/48 */
    HI_I2S_BCLK_64_DIV = 64,  /* bclk mclk/64 */

    HI_I2S_BCLK_MAX    = 0xffffffff,
} hi_i2s_bclk;

/* defines the I2S(inter-IC sound) channels. */
/* CNcomment: ������ƵI2S�ӿ���Ƶͨ��ö�� */
typedef enum {
    HI_I2S_CH_1   = 1,
    HI_I2S_CH_2   = 2,   /* only work for I2S mode */
    HI_I2S_CH_8   = 8,   /* only work for I2S mode */
    HI_I2S_CH_16  = 16,  /* only work for TDM mode */

    HI_I2S_CH_MAX = 0xffffffff,
} hi_i2s_channel;

/* defines the I2S(inter-IC sound) bit depth. */
typedef enum {
    HI_I2S_BIT_DEPTH_16 = 16,
    HI_I2S_BIT_DEPTH_24 = 24,
} hi_i2s_bit_depth;

/* defines the I2S(inter-IC sound) data valid after frame sync clock at PCM mode. */
/* CNcomment: ������ƵI2S�ӿڣ�������Ч�ӳ����ڣ���PCMģʽ��Ч */
typedef enum {
    HI_I2S_PCM_0_DELAY   = 0,   /* 0 bclk cycles delay */
    HI_I2S_PCM_1_DELAY   = 1,   /* 1 bclk cycles delay */
    HI_I2S_PCM_8_DELAY   = 8,   /* 8 bclk cycles delay */
    HI_I2S_PCM_16_DELAY  = 16,  /* 16 bclk cycles delay */
    HI_I2S_PCM_17_DELAY  = 17,  /* 17 bclk cycles delay */
    HI_I2S_PCM_24_DELAY  = 24,  /* 24 bclk cycles delay */
    HI_I2S_PCM_32_DELAY  = 32,  /* 32 bclk cycles delay */

    HI_I2S_PCM_DELAY_MAX = 0xffffffff,
} hi_i2s_pcm_delay;

/* EIA-CEA-861-G Table 31 */
enum hi_audio_format {
    /* Audio coding type, refer to stream header, default type*/
    /* CNcomment:��Ƶ�������ͣ��ο���������ȱʡ��ʽ */
    HI_AUDIO_FORMAT_STREAM,

    /* Audio coding PCM type */ /* CNcomment:��Ƶ����PCM��ʽ */
    HI_AUDIO_FORMAT_PCM,

    /* Audio coding dolby digital(ac3) type */
    /* CNcomment:��Ƶ����dolby digital(ac3)��ʽ */
    HI_AUDIO_FORMAT_AC3,

    /* Audio coding MPEG1 type */ /* CNcomment:��Ƶ����MPEG1��ʽ */
    HI_AUDIO_FORMAT_MPEG1,

    /* Audio coding MP3 type */ /* CNcomment:��Ƶ����MP3��ʽ */
    HI_AUDIO_FORMAT_MP3,

    /* Audio coding MPEG2 type */ /* CNcomment:��Ƶ����MPEG2��ʽ */
    HI_AUDIO_FORMAT_MPEG2,

    /* Audio coding AAC type */ /* CNcomment:��Ƶ����AAC��ʽ */
    HI_AUDIO_FORMAT_AAC_LC,

    /* Audio coding DTS type */ /* CNcomment:��Ƶ����DTS��ʽ */
    HI_AUDIO_FORMAT_DTS,

    /* Audio coding ATRAC type */ /* CNcomment:��Ƶ����ATRAC��ʽ */
    HI_AUDIO_FORMAT_ATRAC,

    /* Audio coding One Bit Audio type */
    /* CNcomment:��Ƶ����One Bit Audio��ʽ */
    HI_AUDIO_FORMAT_DSD,

    /* Audio coding dolby digital plus type */
    /* CNcomment:��Ƶ����dolby digital plus(e-ac3)��ʽ */
    HI_AUDIO_FORMAT_EAC3,

    /* Audio coding DTS HD type */ /* CNcomment:��Ƶ����DTS HD��ʽ */
    HI_AUDIO_FORMAT_DTS_HD,

    /* Audio coding MAT(DVD Forum MLP) type */
    /* CNcomment:��Ƶ����MAT(DVD Forum MLP)��ʽ */
    HI_AUDIO_FORMAT_MAT,

    /* Audio coding DST type */ /* CNcomment:��Ƶ����DST��ʽ */
    HI_AUDIO_FORMAT_DST,

    /* Audio coding WMA PRO type */ /* CNcomment:��Ƶ����WMA PRO��ʽ */
    HI_AUDIO_FORMAT_WMA_PRO,

    /* Audio coding refer to CXT */
    HI_AUDIO_FORMAT_CXT,
};

/* EIA-CEA-861-G Table 33 */
enum hi_audio_format_ext {
    /* Refer to Audio Coding Type (CT) field in Data Byte 1 */
    HI_AUDIO_FORMAT_EXT_CT = 0x0,

    /*
     * The next three CXT values are defined in CEA-861-E only.
     * They do not exist in older versions, and in CEA-861-F and CEA-861-F
     * they are defined as 'Not in use'.
     */
    HI_AUDIO_FORMAT_EXT_HE_AAC,
    HI_AUDIO_FORMAT_EXT_HE_AAC_V2,
    HI_AUDIO_FORMAT_EXT_MPEG_SURROUND,

    /* The following CXT values are only defined in CEA-861-F. */
    HI_AUDIO_FORMAT_EXT_MPEG4_HE_AAC = 0x4,
    HI_AUDIO_FORMAT_EXT_MPEG4_HE_AAC_V2,
    HI_AUDIO_FORMAT_EXT_MPEG4_AAC_LC,
    HI_AUDIO_FORMAT_EXT_DRA,

    /* MPEG-4 HE AAC + MPEG Surround */
    HI_AUDIO_FORMAT_EXT_MPEG4_HE_AAC_SURROUND,

    /* MPEG-4 AAC LC + MPEG Surround */
    HI_AUDIO_FORMAT_EXT_MPEG4_AAC_LC_SURROUND = 0xa,

    /* The following CXT values are only defined in CEA-861-G. */
    /* Audio Extension Type Code 11 (MPEG-H 3D Audio) */
    HI_AUDIO_FORMAT_EXT_MPEGH_3D,
    /* Audio Extension Type Code 12 (AC-4) */
    HI_AUDIO_FORMAT_EXT_AC4,
    /* Audio Extension Type Code 13 (L-PCM 3D Audio) */
    HI_AUDIO_FORMAT_EXT_LPCM_3D,
};

/* the type of adjust audio */
typedef enum {
    HI_AO_SPEED_NORMAL,           /* normal play speed */
    HI_AO_SPEED_SRC,              /* sample rate convert */
    HI_AO_SPEED_PITCH,            /* sola speed adjust */
    HI_AO_SPEED_MUTE,             /* add mute */
    HI_AO_SPEED_TPLAY,            /* audio speed support 0.2 to 2.0 */
    HI_AO_SPEED_MAX
} hi_ao_speed_type;

/* audio speed adjust arguments */
typedef struct {
    hi_ao_speed_type type;
    hi_s32 speed_int;
    hi_s32 speed_dec;
    hi_u32 enable_delay;
    hi_u32 restore_delay;
} hi_ao_speed;

/* defines the I2S(inter-IC sound) attribute. */
/* CNcomment: ������ƵI2S�ӿ��������� */
typedef struct {
    hi_bool master; /* HI_TRUE: master, HI_FALSE: slave */
    hi_i2s_mode i2s_mode;
    hi_i2s_mclk mclk;
    hi_i2s_bclk bclk;
    hi_i2s_channel channel;
    hi_i2s_bit_depth bit_depth;

    /* only work for PCM mode.
     * HI_TRUE: sample data at positive edge of bclk,
     * HI_FALSE: sample data at negative edge of bclk
     */
    hi_bool pcm_sample_rise_edge;
    hi_i2s_pcm_delay pcm_delay_cycle; /* only work for PCM mode. */
} hi_i2s_attr;

/* defines the information about audio frames. */
/* CNcomment: ������Ƶ֡��Ϣ�ṹ */
typedef struct {
    /* @bit_depth: (PCM) data depth, and format of storing the output data
     * if the data depth is 16 bits, 16-bit word memory is used.
     * if the data depth is greater than 16 bits, 32-bit word memory is used,
     * and data is stored as left-aligned data. that is, the valid data is at upper bits.
     */
    /* CNcomment: @bit_depth: (PCM) ����λ������. �����Ÿ�ʽ
     * ����16bit: ռ��16bit word�ڴ�
     * ����16bit: ռ��32bit word�ڴ�, ��������뷽ʽ���(��Ч�����ڸ�λ)
     */
    hi_s32  bit_depth;

    hi_bool interleaved;  /* whether the data is interleaved */ /* CNcomment: �����Ƿ�֯ */
    hi_u32  sample_rate;  /* sampling rate */ /* CNcomment: ������ */
    hi_u32  channels;     /* number of channels */ /* CNcomment: ͨ������ */

    /* presentation time stamp (PTS, unit: us) */
    /* CNcomment: ʱ���(��λ��΢��) */
    hi_s64  pts;

    /* pointer to the buffer for storing the pulse code modulation (PCM) data */
    /* CNcomment: PCM���ݻ���ָ�� */
    hi_s32 *pcm_buffer;

    /* pointer to the buffer for storing the stream data */
    /* CNcomment: �������ݻ���ָ�� */
    hi_s32 *bits_buffer;

    /* number of sampling points of the PCM data */
    /* CNcomment: PCM���ݲ��������� */
    hi_u32 pcm_samples;

    hi_u32 bits_bytes;    /* IEC61937 data size */ /* CNcomment: IEC61937���ݳ��� */
    hi_u32 frame_index;   /* frame ID */ /* CNcomment: ֡��� */

    /* IEC61937 data type */
    /* CNcomment: IEC61937�������ͱ�ʶ����8bitΪIEC�������� */
    hi_u32 iec_data_type;
} hi_ao_frame;

/* defines the audio buffer */
/* CNcomment: ������Ƶģ��buffer�ṹ�� */
typedef struct
{
    hi_void *dma_buf;    /* kernel dma buffer */ /* CNcomment: �ں˷��ص�dma buffer�ṹ�� */
    hi_u8   *virt_addr;  /* kernel virtual address */ /* CNcomment: �ں������ַ */
    hi_u64  phys_addr;   /* physic address */ /* CNcomment: �����ַ */
    hi_u32  size;        /* buffer size */ /* CNcomment: buffer��С */
    hi_bool cache;       /* buffer has cache for CPU */ /* CNcomment: CPU��дʱ�Ƿ��cache */

    /* buffer file handle, set to -1 if not support */
    /* CNcomment: buffer��Ӧ���ļ���� */
    hi_s32  fd;
} hi_audio_buffer;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_DRV_AUDIO_H__ */
