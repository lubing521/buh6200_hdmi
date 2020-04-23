/******************************************************************************
  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_wlan_sta.h
  Version       : Initial Draft
  Author        : Hisilicon sdk software group
  Created       :
  Last Modified :
  Description   : header file for Wi-Fi Station component
  Function List :
  History       :
  1.Date        :
  Author        :
  Modification  : Created file
******************************************************************************/

/**
 * \file
 * \brief describle the information about WiFi STA component. CNcomment:�ṩWiFi STA�����ؽӿڡ����ݽṹ��Ϣ��CNend
 */

#ifndef __HI_WLAN_STA_H__
#define __HI_WLAN_STA_H__

#include "hi_wlan_common.h"
#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup     WLAN_STA */
/** @{ */  /** <!-- [WLAN_STA] */

/** connection state type *//** CNcomment:��������״̬���� */
typedef enum
{
    HI_WLAN_STA_STATUS_DISCONNECTED,  /**< not connected to any network *//** CNcomment:����Ͽ�״̬ */
    HI_WLAN_STA_STATUS_CONNECTING,    /**< connecting to a network *//** CNcomment:��������AP״̬ */
    HI_WLAN_STA_STATUS_CONNECTED,     /**< connected to a network *//** CNcomment:������AP״̬ */
    HI_WLAN_STA_STATUS_MAX,
} hi_wlan_sta_connection_state;

/** access point information *//** CNcomment:AP��Ϣ�ṹ�� */
typedef struct
{
    hi_char ssid[MAX_SSID_LEN+1];      /**< AP's SSID *//** CNcomment:AP��SSID */
    hi_char bssid[BSSID_LEN+1];        /**< AP's MAC address *//** CNcomment:AP��MAC��ַ */
    hi_u32  rssi_level;                /**< AP's signal level, 0 - 100 *//** CNcomment:AP���ź�ǿ�ȣ�0 - 100 */
    hi_u32  channel;                   /**< AP's channel number *//** CNcomment:AP���ŵ� */
    hi_wlan_security security;         /**< AP's security mode *//** CNcomment:AP�İ�ȫģʽ */
} hi_wlan_sta_info;

/** access point configuration *//** CNcomment:��Ҫ���ӵ�AP���� */
typedef struct
{
    hi_char   ssid[MAX_SSID_LEN+1];      /**< AP's SSID *//** CNcomment:AP��SSID */
    hi_char   bssid[BSSID_LEN+1];        /**< AP's MAC address *//** CNcomment:AP��MAC��ַ */
    hi_wlan_security security;           /**< AP's security mode *//** CNcomment:AP�İ�ȫģʽ */
    hi_char   password[MAX_PWD_LEN+1];   /**< AP's password, if not OPEN mode *//** CNcomment:���� */
    hi_bool   hidden_ssid;               /**< whether AP hiddens it's SSID *//** CNcomment:AP�Ƿ�������SSID */
} hi_wlan_sta_config;

/** network status information *//** CNcomment:��������״̬��Ϣ */
typedef struct
{
    hi_wlan_sta_connection_state state; /**< connection state *//** CNcomment:���������״̬ */
    hi_wlan_sta_info ap;        /**< network information which connected or connecting *//** CNcomment:�����ϻ����������ӵ�AP��Ϣ */
} hi_wlan_sta_connection_status;

/** @}*/  /** <!-- ==== Structure Definition End ====*/

/******************************* API Declaration *****************************/
/** \addtogroup     WLAN_STA*/
/** @{*/  /** <!-- [WLAN_STA]*/

/**
\brief: Initialize STA.CNcomment:��ʼ��STA CNend
\attention \n
\param    N/A.CNcomment:�� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\see \n
::hi_wlan_sta_init
*/
hi_s32 hi_wlan_sta_init(hi_void);

/**
\brief: Deintialize STA.CNcomment:ȥ��ʼ��STA CNend
\attention \n
\param  N/A.CNcomment:�� CNend
\retval N/A.CNcomment:�� CNend
\see \n
::hi_wlan_sta_deinit
*/
hi_void hi_wlan_sta_deinit(hi_void);

/**
\brief: Open WiFi STA device.CNcomment:��WiFi STA�豸 CNend
\attention \n
\param[out] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] name_size  parameter ifname length.CNcomment:ifanme�Ĵ�С, ��: strlen(ifname)
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_DEVICE_NOT_FOUND
\retval  ::HI_WLAN_LOAD_DRIVER_FAIL
\see \n
::hi_wlan_sta_open
*/
hi_s32 hi_wlan_sta_open(hi_char *ifname, hi_u32 name_size);

/**
\brief: Close WiFi STA device.CNcomment:�ر�WiFi STA�豸 CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::hi_wlan_sta_close
*/
hi_s32 hi_wlan_sta_close(const hi_char *ifname);

/**
\brief: Start WiFi STA.CNcomment:����WiFi STA CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] event_cb  call back function that receives events.CNcomment:�����¼��Ļص����� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_START_SUPPLICANT_FAIL
\retval  ::HI_WLAN_CONNECT_TO_SUPPLICANT_FAIL
\see \n
::hi_wlan_sta_start
*/
hi_s32 hi_wlan_sta_start(const hi_char *ifname, hi_wlan_sta_event_callback event_cb);

/**
\brief: Stop WiFi STA.CNcomment:ͣ��WiFi STA CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::hi_wlan_sta_stop
*/
hi_s32 hi_wlan_sta_stop(const hi_char *ifname);

/**
\brief: Start to scan.CNcomment:��ʼɨ�� CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_start_scan
*/
hi_s32 hi_wlan_sta_start_scan(const hi_char *ifname);

/**
\brief: Get scan results.CNcomment:��ȡɨ�赽��AP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[out] ap_list AP list.CNcomment: ����ɨ�赽��AP�б� CNend
\param[inout] ap_num  number of APs.CNcomment: AP�б���AP������ CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_get_scan_results
*/
hi_s32 hi_wlan_sta_get_scan_results(const hi_char *ifname,hi_wlan_sta_info *ap_list, hi_u32 *ap_num);

/**
\brief: Connect to AP.CNcomment:��ʼ����AP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] sta_cfg  AP configuration try to connect.CNcomment:��Ҫ���ӵ�AP����Ϣ CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_connect
*/
hi_s32 hi_wlan_sta_connect(const hi_char *ifname, hi_wlan_sta_config *sta_cfg);

/**
\brief: Disconnect to AP.CNcomment:�Ͽ����� CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_disconnect
*/
hi_s32 hi_wlan_sta_disconnect(const hi_char *ifname);

/**
\brief: Get current network connection status.CNcomment:��õ�ǰ������״̬��Ϣ CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[out] conn_status network connection status.CNcomment:��������״̬��Ϣ CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_get_connection_status
*/
hi_s32 hi_wlan_sta_get_connection_status(const hi_char *ifname, hi_wlan_sta_connection_status *conn_status);

/**
\brief: WPS connect to AP.CNcomment:��ʼ����WPS AP CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[in] wps_method  WPS method.CNcomment:WPS���� CNend
\param[in] pin  Pin code if WPS method is PIN.CNcomment:WPS pin�� CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\retval  ::HI_WLAN_SEND_COMMAND_FAIL
\see \n
::hi_wlan_sta_start_wps
*/
hi_s32 hi_wlan_sta_start_wps(const hi_char *ifname, hi_wlan_wps_method wps_method, hi_char *pin);

/**
\brief: Get local WiFi MAC address.CNcomment:��ȡ����WiFi MAC��ַ CNend
\attention \n
\param[in] ifname  WiFi network interface name.CNcomment:WiFi����ӿ���, ��: wlan0 CNend
\param[out] pstMac  MAC address of local WiFi.CNcomment:���汾��WiFi MAC��ַ CNend
\param[in] macBufSize  parameter ifname length.CNcomment:ifname�Ĵ�С, ��Сһ��̶�Ϊ17 CNend
\retval  ::HI_SUCCESS
\retval  ::HI_FAILURE
\retval  ::HI_WLAN_INVALID_PARAMETER
\see \n
::HI_WLAN_STA_GetMacAddress
*/
hi_s32 hi_wlan_sta_get_mac(const hi_char *ifname, hi_char *mac, hi_u8 mac_size);

/** @}*/  /** <!-- ==== API Declaration End ====*/

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif /* __HI_WLAN_STA_H__ */
