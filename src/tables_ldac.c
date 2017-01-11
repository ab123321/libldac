/*
 * Copyright (C) 2003 - 2016 Sony Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ldac.h"

/***************************************************************************************************
    Tables related to Sampling Rate Indices
***************************************************************************************************/
DECLFUNC const unsigned int ga_smplrate_ldac[LDAC_NSUPSMPLRATEID] = {
    44100, 48000, 88200, 96000,
};

DECLFUNC const unsigned short ga_framesmpls_ldac[LDAC_NSUPSMPLRATEID] = {
    LDAC_1FSLSU, LDAC_1FSLSU, LDAC_2FSLSU, LDAC_2FSLSU,
};

DECLFUNC const unsigned char ga_ln_framesmpls_ldac[LDAC_NSUPSMPLRATEID] = {
    LDAC_1FSLNN, LDAC_1FSLNN, LDAC_2FSLNN, LDAC_2FSLNN,
};

DECLFUNC const unsigned char ga_max_nbands_ldac[LDAC_NSUPSMPLRATEID] = {
    LDAC_1FSNBANDS, LDAC_1FSNBANDS, LDAC_2FSNBANDS, LDAC_2FSNBANDS,
};

DECLFUNC const char gaa_nlnn_shift_ldac[LDAC_NSUPSMPLRATEID][LDAC_NSFTSTEP] = {
    {-1, -1,  0,  0, -1},
    {-1, -1,  0,  0, -1},
    {-1,  0,  0, -1, -1},
    {-1,  0,  0, -1, -1},
};

/***************************************************************************************************
    Tables related to Channel Config Indices
***************************************************************************************************/
DECLFUNC const unsigned char ga_ch_ldac[LDAC_NCHCONFIGID] = {
    LDAC_CHANNEL_1CH, LDAC_CHANNEL_2CH, LDAC_CHANNEL_2CH, 0, 0, 0, 0, 0
};

DECLFUNC const unsigned char ga_chconfig_id_ldac[LDAC_MAXNCH+1] = {
    0, LDAC_CHCONFIGID_MN, LDAC_CHCONFIGID_ST
};

DECLFUNC const char gaa_block_setting_ldac[LDAC_NCHCONFIGID][LDAC_MAXNCH+2]=
{
    {LDAC_CHANNEL_1CH, 1, LDAC_BLKID_MONO},
    {LDAC_CHANNEL_2CH, 2, LDAC_BLKID_MONO, LDAC_BLKID_MONO},
    {LDAC_CHANNEL_2CH, 1, LDAC_BLKID_STEREO},
    {0, 0, 0},
};

DECLFUNC int get_block_nchs_ldac(
int blk_type)
{
    int blk_nchs;

    if (blk_type == LDAC_BLKID_MONO) {
        blk_nchs = 1;
    }
    else if (blk_type == LDAC_BLKID_STEREO) {
        blk_nchs = 2;
    }
    else {
        blk_nchs = -1;
    }

    return blk_nchs;
}

/***************************************************************************************************
    Tables related to Quantization Units
***************************************************************************************************/
DECLFUNC const unsigned char ga_idsp_ldac[LDAC_MAXNQUS] = {
      0,  0,  0,  0,  0,  0,  0,  0,
      1,  1,  1,  1,
      1,  1,  1,  1,
      1,  1,  1,  1,
      2,  2,
      2,  2,
      3,  3,
      3,  3,
      3,  3,
      3,  3,
      3,  3,
};

DECLFUNC const unsigned char ga_nsps_ldac[LDAC_MAXNQUS] = {
      2,  2,  2,  2,  2,  2,  2,  2,
      4,  4,  4,  4,
      4,  4,  4,  4,
      4,  4,  4,  4,
      8,  8,
      8,  8,
     16, 16,
     16, 16,
     16, 16,
     16, 16,
     16, 16,
};

DECLFUNC const unsigned short ga_isp_ldac[LDAC_MAXNQUS+1] = {
      0,  2,  4,  6,  8, 10, 12, 14,
     16, 20, 24, 28,
     32, 36, 40, 44,
     48, 52, 56, 60,
     64, 72,
     80, 88,
     96,112,
    128,144,
    160,176,
    192,208,
    224,240,
    256,
};

DECLFUNC const unsigned char ga_nqus_ldac[LDAC_MAXNBANDS+1] = {
    0,  4,  8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 26, 28, 30, 32, 34,
};

/***************************************************************************************************
    Encoding/Decoding Tables for Spectrum Data
***************************************************************************************************/
DECLFUNC const unsigned char ga_wl_ldac[LDAC_NIDWL] = {
    0,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
};

DECLFUNC const short gaa_ndim_wls_ldac[4][LDAC_NIDWL] = {
    {0,  3,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32},
    {0,  7, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64},
    {0, 14, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128},
    {0, 28, 48, 64, 80, 96,112,128,144,160,176,192,208,224,240,256},
};

DECLFUNC const int ga_2dimenc_spec_ldac[LDAC_N2DIMSPECENCTBL] = {
    0,  1,  2,  0,  3,  0,  4,  0,  5,  6,  7,  0,  0,  0,  0,  0,
};

DECLFUNC const int ga_4dimenc_spec_ldac[LDAC_N4DIMSPECENCTBL] = {
     0,  1,  2,  0,  3,  4,  5,  0,  6,  7,  8,  0,  0,  0,  0,  0,
     9, 10, 11,  0, 12, 13, 14,  0, 15, 16, 17,  0,  0,  0,  0,  0,
    18, 19, 20,  0, 21, 22, 23,  0, 24, 25, 26,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    27, 28, 29,  0, 30, 31, 32,  0, 33, 34, 35,  0,  0,  0,  0,  0,
    36, 37, 38,  0, 39, 40, 41,  0, 42, 43, 44,  0,  0,  0,  0,  0,
    45, 46, 47,  0, 48, 49, 50,  0, 51, 52, 53,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    54, 55, 56,  0, 57, 58, 59,  0, 60, 61, 62,  0,  0,  0,  0,  0,
    63, 64, 65,  0, 66, 67, 68,  0, 69, 70, 71,  0,  0,  0,  0,  0,
    72, 73, 74,  0, 75, 76, 77,  0, 78, 79, 80,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};


/***************************************************************************************************
    Resampled Gradient Table
***************************************************************************************************/
DECLFUNC const unsigned char gaa_resamp_grad_ldac[LDAC_MAXGRADQU][LDAC_MAXGRADQU] = {
{
128,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
 31,225,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
 17,128,239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
 12, 69,187,244,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
 10, 43,128,213,246,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  9, 31, 87,169,225,247,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  8, 24, 62,128,194,232,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  8, 19, 47, 97,159,209,237,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  7, 17, 37, 75,128,181,219,239,249,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  7, 15, 31, 59,103,153,197,225,241,249,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  7, 13, 26, 48, 83,128,173,208,230,243,249,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6, 12, 23, 41, 69,107,149,187,215,233,244,250,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6, 11, 20, 35, 58, 90,128,166,198,221,236,245,250,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6, 11, 18, 31, 49, 76,110,146,180,207,225,238,245,250,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6, 10, 17, 27, 43, 66, 95,128,161,190,213,229,239,246,250,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6, 10, 15, 24, 38, 57, 82,112,144,174,199,218,232,241,246,250,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  9, 14, 22, 34, 50, 72, 98,128,158,184,206,222,234,242,247,250,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  9, 13, 20, 31, 45, 63, 87,114,142,169,193,211,225,236,243,247,250,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  9, 13, 19, 28, 40, 56, 77,101,128,155,179,200,216,228,237,243,247,250,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  8, 12, 18, 26, 36, 51, 69, 91,115,141,165,187,205,220,230,238,244,248,250,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  8, 12, 17, 24, 33, 46, 62, 81,104,128,152,175,194,210,223,232,239,244,248,250,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  6,  8, 11, 16, 22, 31, 42, 56, 74, 94,116,140,162,182,200,214,225,234,240,245,248,250,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  8, 11, 15, 21, 28, 38, 51, 67, 85,106,128,150,171,189,205,218,228,235,241,245,248,251,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  8, 10, 14, 19, 26, 35, 47, 61, 78, 97,117,139,159,178,195,209,221,230,237,242,246,248,251,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7, 10, 14, 18, 25, 33, 43, 56, 71, 88,108,128,148,168,185,200,213,223,231,238,242,246,249,251,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7, 10, 13, 17, 23, 31, 40, 51, 65, 81, 99,118,138,157,175,191,205,216,225,233,239,243,246,249,
251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  9, 13, 17, 22, 29, 37, 47, 60, 75, 91,109,128,147,165,181,196,209,219,227,234,239,243,247,
249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  9, 12, 16, 21, 27, 35, 44, 55, 69, 84,101,119,137,155,172,187,201,212,221,229,235,240,244,
247,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  9, 12, 15, 20, 25, 32, 41, 51, 64, 78, 94,110,128,146,162,178,192,205,215,224,231,236,241,
244,247,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  9, 11, 15, 19, 24, 31, 38, 48, 59, 72, 87,103,119,137,153,169,184,197,208,218,225,232,237,
241,245,247,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  9, 11, 14, 18, 23, 29, 36, 45, 55, 67, 81, 96,112,128,144,160,175,189,201,211,220,227,233,
238,242,245,247,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  8, 11, 14, 17, 22, 27, 34, 42, 52, 63, 75, 89,104,120,136,152,167,181,193,204,214,222,229,
234,239,242,245,248,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  8, 11, 13, 17, 21, 26, 32, 40, 48, 59, 70, 83, 98,113,128,143,158,173,186,197,208,216,224,
230,235,239,243,245,248,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  7,  8, 10, 13, 16, 20, 25, 31, 37, 46, 55, 66, 78, 91,106,120,136,150,165,178,190,201,210,219,
225,231,236,240,243,246,248,249,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8, 10, 12, 15, 19, 24, 29, 35, 43, 52, 62, 73, 86, 99,113,128,143,157,170,183,194,204,213,
221,227,232,237,241,244,246,248,250,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8, 10, 12, 15, 18, 23, 28, 34, 41, 49, 58, 69, 81, 93,107,121,135,149,163,175,187,198,207,
215,222,228,233,238,241,244,246,248,250,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8, 10, 12, 15, 18, 22, 26, 32, 39, 46, 55, 65, 76, 88,101,114,128,142,155,168,180,191,201,
210,217,224,230,234,238,241,244,246,248,250,251,255,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8,  9, 12, 14, 17, 21, 25, 31, 37, 44, 52, 61, 72, 83, 95,108,121,135,148,161,173,184,195,
204,212,219,225,231,235,239,242,244,247,248,250,251,255,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8,  9, 11, 14, 17, 20, 24, 29, 35, 42, 49, 58, 68, 78, 90,102,115,128,141,154,166,178,188,
198,207,214,221,227,232,236,239,242,245,247,248,250,251,255,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  8,  9, 11, 13, 16, 19, 23, 28, 33, 40, 47, 55, 64, 74, 85, 97,109,122,134,147,159,171,182,
192,201,209,216,223,228,233,237,240,243,245,247,248,250,251,255,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  7,  9, 11, 13, 16, 19, 22, 27, 32, 38, 44, 52, 61, 70, 80, 92,103,116,128,140,153,164,176,
186,195,204,212,218,224,229,234,237,240,243,245,247,249,250,251,255,255,255,255,255,255,255,255,255,
},
{
  5,  6,  7,  9, 11, 13, 15, 18, 22, 26, 31, 36, 42, 49, 58, 66, 76, 87, 98,110,122,134,146,158,169,
180,190,198,207,214,220,225,230,234,238,241,243,245,247,249,250,251,255,255,255,255,255,255,255,255,
},
{
  5,  6,  7,  9, 10, 12, 15, 18, 21, 25, 29, 34, 40, 47, 55, 63, 72, 82, 93,104,116,128,140,152,163,
174,184,193,201,209,216,222,227,231,235,238,241,244,246,247,249,250,251,255,255,255,255,255,255,255,
},
{
  5,  6,  7,  9, 10, 12, 14, 17, 20, 24, 28, 33, 39, 45, 52, 60, 69, 78, 89, 99,111,122,134,145,157,
167,178,187,196,204,211,217,223,228,232,236,239,242,244,246,247,249,250,251,255,255,255,255,255,255,
},
{
  5,  6,  7,  8, 10, 12, 14, 17, 20, 23, 27, 32, 37, 43, 50, 57, 66, 75, 84, 95,105,117,128,139,151,
161,172,181,190,199,206,213,219,224,229,233,236,239,242,244,246,248,249,250,251,255,255,255,255,255,
},
{
  5,  6,  7,  8, 10, 12, 14, 16, 19, 22, 26, 31, 36, 41, 48, 55, 62, 71, 80, 90,101,111,122,134,145,
155,166,176,185,194,201,208,215,220,225,230,234,237,240,242,244,246,248,249,250,251,255,255,255,255,
},
{
  5,  6,  7,  8, 10, 11, 13, 16, 18, 22, 25, 29, 34, 39, 45, 52, 60, 68, 77, 86, 96,106,117,128,139,
150,160,170,179,188,196,204,211,217,222,227,231,234,238,240,243,245,246,248,249,250,251,255,255,255,
},
{
  5,  6,  7,  8, 10, 11, 13, 15, 18, 21, 24, 28, 33, 38, 44, 50, 57, 65, 73, 82, 92,102,112,123,133,
144,154,164,174,183,191,199,206,212,218,223,228,232,235,238,241,243,245,246,248,249,250,251,255,255,
},
{
  5,  6,  7,  8,  9, 11, 13, 15, 17, 20, 24, 27, 32, 36, 42, 48, 55, 62, 70, 78, 88, 97,107,118,128,
138,149,159,168,178,186,194,201,208,214,220,224,229,232,236,239,241,243,245,247,248,249,250,251,255,
},
{
  5,  6,  7,  8,  9, 11, 13, 15, 17, 20, 23, 26, 31, 35, 40, 46, 52, 59, 67, 75, 84, 93,103,113,123,
133,143,153,163,172,181,189,197,204,210,216,221,225,230,233,236,239,241,243,245,247,248,249,250,251,
},
};

/***************************************************************************************************
    Weighting Tables for Scale Factor Data
***************************************************************************************************/
DECLFUNC const unsigned char gaa_sfcwgt_ldac[LDAC_NSFCWTBL][LDAC_MAXNQUS] = {
{
     1,  0,  0,  1,  1,  1,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,
     3,  3,  3,  3,  3,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  8,
},
{
     0,  1,  1,  2,  3,  4,  4,  4,  4,  5,  6,  6,  6,  6,  6,  7,
     7,  7,  7,  7,  7,  7,  8,  8,  8,  9, 10, 10, 11, 11, 12, 12, 12, 12,
},
{
     0,  1,  1,  2,  3,  3,  3,  3,  3,  4,  4,  5,  5,  5,  5,  5,
     5,  5,  5,  5,  5,  5,  6,  6,  6,  7,  8,  9,  9, 10, 10, 11, 11, 11,
},
{
     0,  1,  3,  4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,
     7,  7,  7,  7,  7,  7,  7,  8,  8,  8,  8,  9,  9,  9, 10, 10, 10, 10,
},
{
     0,  1,  3,  4,  5,  5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 10,
    10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13,
},
{
     1,  0,  1,  2,  2,  3,  3,  4,  4,  5,  6,  7,  7,  8,  8,  8,
     9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11,
},
{
     0,  0,  1,  1,  2,  2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  5,  5,  6,  7,  7,  7,  8,  9,  9,  9,  9,
},
{
     0,  0,  1,  2,  3,  4,  4,  5,  5,  6,  7,  7,  8,  8,  8,  8,
     9,  9,  9,  9,  9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 12,
},
};

/***************************************************************************************************
    Huffman Codewords for Scale Factor Data
***************************************************************************************************/
static const HC sa_hc_sf0_blen3_ldac[8] = {
    {  0, 2}, {  1, 2}, { 14, 4}, { 62, 6},
    { 63, 6}, { 30, 5}, {  6, 3}, {  2, 2},
};

static const HC sa_hc_sf0_blen4_ldac[16] = {
    {  1, 2}, {  2, 2}, {  0, 4}, {  6, 5},
    { 15, 6}, { 19, 7}, { 35, 8}, { 36, 8},
    { 37, 8}, { 34, 8}, { 33, 8}, { 32, 8},
    { 14, 6}, {  5, 5}, {  1, 4}, {  3, 2},
};

static const HC sa_hc_sf0_blen5_ldac[32] = {
    {  2, 2}, {  1, 3}, {  7, 3}, { 13, 4},
    { 12, 5}, { 24, 5}, { 27, 6}, { 33, 7},
    { 63, 7}, {106, 8}, {107, 8}, {104, 8},
    {115, 8}, {121, 8}, {124, 8}, {125, 8},
    {122, 8}, {123, 8}, {120, 8}, {114, 8},
    { 68, 8}, { 69, 8}, { 71, 8}, { 70, 8},
    {105, 8}, { 56, 7}, { 32, 7}, { 29, 6},
    { 25, 5}, {  9, 5}, {  5, 4}, {  0, 3},
};

static const HC sa_hc_sf0_blen6_ldac[64] = {
    {  0, 3}, {  1, 3}, {  4, 4}, {  5, 4},
    { 18, 5}, { 19, 5}, { 46, 6}, { 47, 6},
    { 48, 6}, {102, 7}, {103, 7}, {214, 8},
    {215, 8}, {216, 8}, {217, 8}, {218, 8},
    {219, 8}, {220, 8}, {221, 8}, {222, 8},
    {223, 8}, {224, 8}, {225, 8}, {226, 8},
    {227, 8}, {228, 8}, {229, 8}, {230, 8},
    {231, 8}, {232, 8}, {233, 8}, {234, 8},
    {235, 8}, {236, 8}, {237, 8}, {238, 8},
    {239, 8}, {240, 8}, {241, 8}, {242, 8},
    {243, 8}, {244, 8}, {245, 8}, {246, 8},
    {247, 8}, {248, 8}, {249, 8}, {250, 8},
    {251, 8}, {252, 8}, {253, 8}, {254, 8},
    {255, 8}, {104, 7}, {105, 7}, {106, 7},
    { 49, 6}, { 50, 6}, { 20, 5}, { 21, 5},
    { 22, 5}, {  6, 4}, {  7, 4}, {  8, 4},
};

static const HC sa_hc_sf1_blen2_ldac[4] = {
    {  0, 1}, {  3, 2}, {  0, 0}, { 2,  2},
};

static const HC sa_hc_sf1_blen3_ldac[8] = {
    {  1, 1}, {  0, 3}, {  4, 5}, { 11, 6},
    {  0, 0}, { 10, 6}, {  3, 4}, {  1, 2},
};

static const HC sa_hc_sf1_blen4_ldac[16] = {
    {  1, 1}, {  1, 3}, {  4, 4}, { 14, 5},
    { 15, 5}, { 44, 7}, { 90, 8}, { 93, 8},
    {  0, 0}, { 92, 8}, { 91, 8}, { 47, 7},
    { 21, 6}, { 20, 6}, {  6, 4}, {  0, 3},
};

static const HC sa_hc_sf1_blen5_ldac[32] = {
    {  0, 3}, {  5, 3}, {  7, 4}, { 12, 4},
    {  4, 4}, {  2, 4}, {  3, 4}, {  5, 4},
    {  9, 4}, { 16, 5}, { 35, 6}, { 51, 7},
    { 54, 7}, {110, 7}, { 96, 8}, {101, 8},
    { 98, 8}, { 97, 8}, { 99, 8}, {100, 8},
    {111, 7}, {109, 7}, {108, 7}, {107, 7},
    {106, 7}, {104, 7}, {105, 7}, { 69, 7},
    { 68, 7}, { 55, 7}, { 26, 6}, {  7, 3},
};


/***************************************************************************************************
    Huffman Encoding/Decoding Structures for Scale Factor Data
***************************************************************************************************/
DECLFUNC HCENC ga_hcenc_sf0_ldac[LDAC_MAXSFCBLEN_0-LDAC_MINSFCBLEN_0+1] = {
    {sa_hc_sf0_blen3_ldac,  8,  3,  7},
    {sa_hc_sf0_blen4_ldac, 16,  4, 15},
    {sa_hc_sf0_blen5_ldac, 32,  5, 31},
    {sa_hc_sf0_blen6_ldac, 64,  6, 63},
};

DECLFUNC HCENC ga_hcenc_sf1_ldac[LDAC_MAXSFCBLEN_2-LDAC_MINSFCBLEN_2+1] = {
    {sa_hc_sf1_blen2_ldac,  4,  2,  3},
    {sa_hc_sf1_blen3_ldac,  8,  3,  7},
    {sa_hc_sf1_blen4_ldac, 16,  4, 15},
    {sa_hc_sf1_blen5_ldac, 32,  5, 31},
};


