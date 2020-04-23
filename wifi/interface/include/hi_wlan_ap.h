/******************************************************************************
  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_wlan_ap.h
  Version       : Initial Draft
  Author        : Hisilicon sdk software group
  Created       :
  Last Modified :
  Description   : header file for Wi-Fi SoftAP component
  Function List :
  History       :
  1.Date        :
  Author        :
  Modification  : Created file
******************************************************************************/

/**
 * \file
 * \brief describle the APIs and structs of WiFi SoftAP function. CNcomment:�ṩWiFi SoftAP���������ؽӿڡ����ݽṹ��Ϣ��CNend
 */

#ifndef __HI_WLAN_AP_H__
#define __HI_WLAN_AP_H__

#include "hi_wlan_common.h"
#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup     WLAN_AP */
/** @{ */  /** <!-- [WLAN_AP] */

/** AP's configuration */
typedef struct
{
    hi_char   ssid[MAX_SSID_LEN+1];      /**< network's SSID *//** CNcomment:SSID */
    hi_s32    channel;                   /**< network's channel *//** CNcomment:�ŵ��� */
    hi_wlan_security security;           /**< network's security mode *//** CNcomment:��ȫģʽ */
    hi_char   password[MAX_PWD_LEN+1];   /**< network's password, if not OPEN mode *//** CNcomment:���� */
    hi_bool   hidden_ssid;               /**< whether network hiddens it's SSID *//** CNcomment:�Ƿ�����SSID */
} hi_wlan_ap_config;


/** @}*/  /** <!-- ==== Structure Definition End ====*/

/******************************* API Declaration *****************************/
/** \addtogroup     WLAN_AP*/
/** @{*/  /** <!-- [WLAN_AP]*/

/**
\brief: Initialize SoftAP.CNcomment:��ʼ��SoftAP CNend
\attention \n
\param    N/A.CNcomment:�� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\see \n
::hi_wlan_ap_init
*/
hi_s32 hi_wlan_ap_init(hi_void);

/**
\brief: Deintialize SoftAP.CNcomment:ȥ��ʼ��SoftAP CNend
\attention \n
\param  N/A.CNcomment:�� CNend
\retval N/A.CNcomment:�� CNend
\see \n
::hi_wlan_ap_deinit
*/
hi_void hi_wlan_ap_deinit(hi_void);

/**
\brief: Open WiFi SoftAP device.CNcomment:��WiFi SoftAP�豸 CNend
\attention \n
\param[out] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] name_size  parameter ifname length.CNcomment:ifanme�Ĵ�С, ��: strlen(ifname)
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_DEVICE_NOT_FOUND
\retval  ::HI_WLAN_LOAD_DRIVER_FAIL
\see \n
::hi_wlan_ap_open
*/
hi_s32 hi_wlan_ap_open(hi_char *ifname, hi_u32 name_size);

/**
\brief: Close WiFi SoftAP device.CNcomment:�ر�WiFi SoftAP�豸 CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::hi_wlan_ap_close
*/
hi_s32 hi_wlan_ap_close(const hi_char *ifname);

/**
\brief: start SoftAP with configuration.CNcomment:����SoftAP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] ap_cfg  AP's configuration.CNcomment:AP�����ò��� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_START_HOSTAPD_FAIL
\see \n
::hi_wlan_ap_start
*/
hi_s32 hi_wlan_ap_start(const hi_char *ifname, hi_wlan_ap_config *ap_cfg);

/**
\brief: Stop SoftAP.CNcomment:�ر�SoftAP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::hi_wlan_ap_stop
*/
hi_s32 hi_wlan_ap_stop(const hi_char *ifname);

/**
\brief: Set SoftAP.CNcomment:����SoftAP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] ap_cfg  AP's configuration.CNcomment:AP�����ò��� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_START_HOSTAPD_FAIL
\see \n
::hi_wlan_ap_set_softap
*/
hi_s32 hi_wlan_ap_set_softap(const hi_char *ifname, hi_wlan_ap_config *ap_cfg);

/**
\brief: Get local WiFi MAC address.CNcomment:��ȡ����WiFi MAC��ַ CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[out] mac  MAC address of local WiFi.CNcomment:���汾��WiFi MAC��ַ CNend
\param[in] mac_size  parameter ifname length.CNcomment:ifname�Ĵ�С, ��Сһ��̶�Ϊ17 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::hi_wlan_ap_get_mac
*/
hi_s32 hi_wlan_ap_get_mac(const hi_char *ifname, hi_char *mac, hi_u8 mac_size);

/** @}*/  /** <!-- ==== API Declaration End ====*/

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif /*__HI_WLAN_AP_H__*/
