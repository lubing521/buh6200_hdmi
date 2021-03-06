#ifndef __MXL_HRCLS_CAL_CTRL_H__
#define __MXL_HRCLS_CAL_CTRL_H__

#define MXL_HRCLS_TEMP_COMP_COEFF_CA002 (SINT16) 387
#define MXL_HRCLS_TEMP_COMP_COEFF_CA001 (SINT16) 11
#define MXL_HRCLS_TEMP_COMP_COEFF_CA000 (SINT16) 477

#define MXL_HRCLS_TEMP_COMP_COEFF_CB002 (SINT16) 5965
#define MXL_HRCLS_TEMP_COMP_COEFF_CB001 (SINT16) -8260
#define MXL_HRCLS_TEMP_COMP_COEFF_CB000 (SINT16) 3525

#define MXL_HRCLS_TEMP_COMP_COEFF_CA102 (SINT16) -384
#define MXL_HRCLS_TEMP_COMP_COEFF_CA101 (SINT16) -46
#define MXL_HRCLS_TEMP_COMP_COEFF_CA100 (SINT16) -786

#define MXL_HRCLS_TEMP_COMP_COEFF_CB102 (SINT16) -12921
#define MXL_HRCLS_TEMP_COMP_COEFF_CB101 (SINT16) 18516
#define MXL_HRCLS_TEMP_COMP_COEFF_CB100 (SINT16) -7616

#define MXL_HRCLS_TEMP_COMP_COEFF_CA112 (SINT16) -1861
#define MXL_HRCLS_TEMP_COMP_COEFF_CA111 (SINT16) 1090
#define MXL_HRCLS_TEMP_COMP_COEFF_CA110 (SINT16) -802

#define MXL_HRCLS_TEMP_COMP_COEFF_CB112 (SINT16) -11238
#define MXL_HRCLS_TEMP_COMP_COEFF_CB111 (SINT16) 16173
#define MXL_HRCLS_TEMP_COMP_COEFF_CB110 (SINT16) -6730

#define MXL_HRCLS_TEMP_COMP_COEFF_CA012 (SINT16) 93
#define MXL_HRCLS_TEMP_COMP_COEFF_CA011 (SINT16) 145
#define MXL_HRCLS_TEMP_COMP_COEFF_CA010 (SINT16) 385

#define MXL_HRCLS_TEMP_COMP_COEFF_CB012 (SINT16) 4230
#define MXL_HRCLS_TEMP_COMP_COEFF_CB011 (SINT16) -5440
#define MXL_HRCLS_TEMP_COMP_COEFF_CB010 (SINT16) 2277

#define MXL_HRCLS_TEMP_COMP_COEFF_CA022 (SINT16) 571
#define MXL_HRCLS_TEMP_COMP_COEFF_CA021 (SINT16) -71
#define MXL_HRCLS_TEMP_COMP_COEFF_CA020 (SINT16) 396

#define MXL_HRCLS_TEMP_COMP_COEFF_CB022 (SINT16) 4080
#define MXL_HRCLS_TEMP_COMP_COEFF_CB021 (SINT16) -5128
#define MXL_HRCLS_TEMP_COMP_COEFF_CB020 (SINT16) 2213

#define MXL_HRCLS_TEMP_COMP_COEFF_CA122 (SINT16) -602
#define MXL_HRCLS_TEMP_COMP_COEFF_CA121 (SINT16) 94
#define MXL_HRCLS_TEMP_COMP_COEFF_CA120 (SINT16) -654

#define MXL_HRCLS_TEMP_COMP_COEFF_CB122 (SINT16) -13134
#define MXL_HRCLS_TEMP_COMP_COEFF_CB121 (SINT16) 19026
#define MXL_HRCLS_TEMP_COMP_COEFF_CB120 (SINT16) -7739

#define notMXL_HRCLS_DS_CAL_TEST

MXL_STATUS_E MxL_HRCLS_Ctrl_CalReadReferencePower(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr, MXL_HRCLS_CAL_DATA_T * calData);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalUpdateRefPowerAtFreqPoints(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr,
                                    UINT16 freqPointsCnt,
                                    UINT16 * freqMHzPtr,
                                    UINT16 * refPowerdBuVPtr,
                                    MXL_HRCLS_CAL_DATA_T * calData);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalUpdateFreqPoints(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr,
                                    UINT16 firstFreqMHz,
                                    /*@out@*/ MXL_HRCLS_CAL_DATA_T * calData);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalProduceCoeffs(UINT8 segmentId, MXL_HRCLS_CAL_DATA_T * calData, /*@out@*/ MXL_HRCLS_CAL_COEFF_T * coeff);

#ifdef MXL_HRCLS_DS_CAL_TEST
MXL_STATUS_E MxL_HRCLS_Ctrl_CalProduceCoeffsFloat(UINT8 segmentId, MXL_HRCLS_CAL_DATA_T * calData, MXL_HRCLS_CAL_COEFF_T * coeff);
#endif

MXL_STATUS_E MxL_HRCLS_Ctrl_CalSaveCoeffsToFile(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalReadCoeffsFromFile(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalGetCorrected(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr,
                                      UINT16 freqMHz,
                                      UINT16 rawPower,
                                      /*@out@*/ UINT16 * correctedPower);
MXL_STATUS_E MxL_HRCLS_Ctrl_CalGetCorrectedPSM(MXL_HRCLS_DEV_CONTEXT_T * devContextPtr,
                                        UINT16 freqMHz,
                                        UINT16 rawPower,
                                        /*@out@*/ UINT16 * correctedPower);

MXL_STATUS_E mxl_lockDemod(MXL_HRCLS_CHAN_ID_E chanId, MXL_HRCLS_DMD_ID_E demodId,
                                  UINT32 freqkHz, UINT8 bwMHz, MXL_HRCLS_ANNEX_TYPE_E annexType,
                                  MXL_HRCLS_QAM_TYPE_E qamType, UINT16 symbolRatekSps, MXL_HRCLS_IQ_FLIP_E iqFlip, MXL_BOOL_E xptSupported);

MXL_STATUS_E mxl_checkVersion(/*@out@*/ MXL_HRCLS_DEV_VER_T* verInfoPtr);
MXL_STATUS_E mxl_downloadFirmware(MXL_BOOL_E * xptSupported);
MXL_STATUS_E mxl_enableFbTuner(void);

#endif

