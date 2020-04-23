/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: struct define
 * Author: pq
 * Create: 2016-01-1
 */

#ifndef _DRV_PQ_VDP_THREAD_H_
#define _DRV_PQ_VDP_THREAD_H_
#include "hi_type.h"
#include "hi_osal.h"
#include "drv_pq_comm.h"

typedef enum {
    HI_DRV_PQ_VDP_API_HDR = 0,
    HI_DRV_PQ_VDP_API_DC,

    HI_DRV_PQ_VDP_API_MAX
} drv_pq_vdp_api;

/* �����ڴ�ṹ�� */
typedef struct {
    drv_pq_mem_info mmu_buff;
    hi_bool exist;
    hi_s32 fd;
} drv_pq_buff_vdp;

typedef struct {
    drv_pq_buff_vdp vdp_in_buff[VDP_ALG_BUFFER_NUM];
    drv_pq_buff_vdp vdp_out_buff[VDP_ALG_BUFFER_NUM];
    hi_drv_pq_vdp_api_input *input_buf;
    hi_drv_pq_vdp_api_output *output_buf;
    hi_bool handle_enable;
    hi_bool is_vdp_thread_exist;
    hi_bool wake_poll_out_process;
    hi_u32 alg_lost;
    hi_u32 alg_run_count;
    wait_queue_head_t pq_poll_wait_out_queue;
} drv_pq_vdp_alg_info;

/* CNcomment:PQ ���� */
typedef struct {
    drv_pq_vdp_alg_info vdp_alg_info;
    hi_bool is_stop;
} drv_pq_vdp_context;

typedef enum {
    VDP_BUF_IN,
    VDP_BUF_OUT,
    VDP_BUF_MAX
} drv_pq_vdp_buf_type;

/* PQ��ʼ����ȥ��ʼ��ʱ���� */
hi_s32 drv_pq_init_vdp_thread(hi_void); /* �ں�̬DRV_PQʹ�� */
hi_void drv_pq_deinit_vdp_thread(hi_void); /* �ں�̬DRV_PQʹ�� */

/* init vdp ���ã����������仯ʱ������buffer�������Ӧhandle�Ѿ����룬���ظ����� */
hi_s32 drv_pq_alloc_vdp_api(hi_void); /* �ں�̬DRV_PQʹ�� */
hi_void drv_pq_free_vdp_api(hi_void); /* �ں�̬DRV_PQʹ�� */

hi_s32 drv_pq_vdp_wakeup_thread(hi_bool released);

hi_u32 drv_pq_vdp_poll(struct file *filp, struct poll_table_struct *wait);

hi_s32 drv_pq_get_vdp_alg_thread_status(hi_bool *pb_thread_exist);
hi_s32 drv_pq_set_vdp_alg_thread_status(hi_bool b_thread_exist);

/* ʹ�ô˽ӿ��ⲿҪ�������±�ǣ�
    1. timing info
    2. index�ź�ƥ�����⣬���ο�����
    3. �����㷨��ready���
    4. �汾��
    5. �����㷨��ʹ�ܱ��
    */
void *drv_pq_vdp_request_buffer(drv_pq_vdp_buf_type type);
hi_s32 drv_pq_vdp_update_buffer(drv_pq_vdp_buf_type type);

hi_s32 drv_pq_get_vdp_thread_info(hi_drv_pq_vdp_thread_info *vdp_thread_info); /* �û�̬MPI_PQʹ�� */
#endif
