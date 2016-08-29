/** @file

Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __FSPMUPD_H__
#define __FSPMUPD_H__

#include "FspUpd.h"
#include <fsp/upd.h>

#define MAX_CHANNELS_NUM 4
#define MAX_DIMMS_NUM    1

struct DIMM_INFO {
  uint8_t         DimmId;
  uint32_t        SizeInMb;
  uint16_t        MfgId;
  /** Module part number for DRR3 is 18 bytes
  but DRR4 is 20 bytes as per JEDEC Spec, so
  reserving 20 bytes **/
  uint8_t         ModulePartNum[20];
} __attribute__((packed));

struct CHANNEL_INFO {
  uint8_t         ChannelId;
  uint8_t         DimmCount;
  struct DIMM_INFO     DimmInfo[MAX_DIMMS_NUM];
} __attribute__((packed));

struct FSP_SMBIOS_MEMORY_INFO {
  uint8_t         Revision;
  uint8_t         DataWidth;
  /** As defined in SMBIOS 3.0 spec
    Section 7.18.2 and Table 75
  **/
  uint16_t         MemoryType;
  uint16_t        MemoryFrequencyInMHz;
  /** As defined in SMBIOS 3.0 spec
    Section 7.17.3 and Table 72
  **/
  uint8_t         ErrorCorrectionType;
  uint8_t         ChannelCount;
  struct CHANNEL_INFO  ChannelInfo[MAX_CHANNELS_NUM];
} __attribute__((packed));


/** Fsp M Configuration
**/
struct FSP_M_CONFIG {

/** Offset 0x0040 - Debug Serial Port Base address
  Debug serial port base address. This option will be used only when the 'Serial Port
  Debug Device' option is set to 'External Device'. 0x00000000(Default).
**/
  uint32_t                      SerialDebugPortAddress;

/** Offset 0x0044 - Debug Serial Port Type
  16550 compatible debug serial port resource type. NONE means no serial port support.
  0x02:MMIO(Default).
  0:NONE, 1:I/O, 2:MMIO
**/
  uint8_t                       SerialDebugPortType;

/** Offset 0x0045 - Serial Port Debug Device
  Select active serial port device for debug. For SOC UART devices,'Debug Serial Port
  Base' options will be ignored. 0x02:SOC UART2(Default).
  0:SOC UART0, 1:SOC UART1, 2:SOC UART2, 3:External Device
**/
  uint8_t                       SerialDebugPortDevice;

/** Offset 0x0046 - Debug Serial Port Stride Size
  Debug serial port register map stride size in bytes. 0x00:1, 0x02:4(Default).
  0:1, 2:4
**/
  uint8_t                       SerialDebugPortStrideSize;

/** Offset 0x0047 - Memory Fast Boot
  Enable/Disable MRC fast boot support. 0x00:Disable, 0x01:Enable(Default).
  $EN_DIS
**/
  uint8_t                       MrcFastBoot;

/** Offset 0x0048 - Integrated Graphics Device
  Enable : Enable Integrated Graphics Device (IGD) when selected as the Primary Video
  Adaptor. Disable: Always disable IGD. 0x00:Disable, 0x01:Enable(Default).
  $EN_DIS
**/
  uint8_t                       Igd;

/** Offset 0x0049 - DVMT Pre-Allocated
  Select DVMT 5.0 Pre-Allocated (Fixed) Graphics Memory size used by the Internal
  Graphics Device. 0x02:64 MB(Default).
  0x02:64 MB, 0x03:96 MB, 0x04:128 MB, 0x05:160 MB, 0x06:192 MB, 0x07:224 MB, 0x08:256
  MB, 0x09:288 MB, 0x0A:320 MB, 0x0B:352 MB, 0x0C:384 MB, 0x0D:416 MB, 0x0E:448 MB,
  0x0F:480 MB, 0x10:512 MB
**/
  uint8_t                       IgdDvmt50PreAlloc;

/** Offset 0x004A - Aperture Size
  Select the Aperture Size used by the Internal Graphics Device. 0x1:128 MB(Default),
  0x2:256 MB, 0x3:512 MB.
  0x1:128 MB, 0x2:256 MB, 0x3:512 MB
**/
  uint8_t                       IgdApertureSize;

/** Offset 0x004B - GTT Size
  Select the GTT Size used by the Internal Graphics Device. 0x1:2 MB, 0x2:4 MB, 0x3:8
  MB(Default).
  0x1:2 MB, 0x2:4 MB, 0x3:8 MB
**/
  uint8_t                       GttSize;

/** Offset 0x004C - Primary Display
  Select which of IGD/PCI Graphics device should be Primary Display. 0x0:AUTO(Default),
  0x2:IGD, 0x3:PCI
  0x0:AUTO, 0x2:IGD, 0x3:PCI
**/
  uint8_t                       PrimaryVideoAdaptor;

/** Offset 0x004D - Package
  NOTE: First option is CoPOP if LPDDR3/LPDDR4 is being used. It is SODIMM if DDR3L
  is being used. 0x00(Default).
  0x0:CoPop, 0x1:BGA, 0x2:LP3 ACRD
**/
  uint8_t                       Package;

/** Offset 0x004E - Profile
  Profile list. 0x19(Default).
  0x1:WIO2_800_7_8_8, 0x2:WIO2_1066_9_10_10, 0x3:LPDDR3_1066_8_10_10, 0x4:LPDDR3_1333_10_12_12,
  0x5:LPDDR3_1600_12_15_15, 0x6:LPDDR3_1866_14_17_17, 0x7:LPDDR3_2133_16_20_20, 0x8:LPDDR4_1066_10_10_10,
  0x9:LPDDR4_1600_14_15_15, 0xA:LPDDR4_2133_20_20_20, 0xB:LPDDR4_2400_24_22_22, 0xC:LPDDR4_2666_24_24_24,
  0xD:LPDDR4_2933_28_27_27, 0xE:LPDDR4_3200_28_29_29, 0xF:DDR3_1066_6_6_6, 0x10:DDR3_1066_7_7_7,
  0x11:DDR3_1066_8_8_8, 0x12:DDR3_1333_7_7_7, 0x13:DDR3_1333_8_8_8, 0x14:DDR3_1333_9_9_9,
  0x15:DDR3_1333_10_10_10, 0x16:DDR3_1600_8_8_8, 0x17:DDR3_1600_9_9_9, 0x18:DDR3_1600_10_10_10,
  0x19:DDR3_1600_11_11_11, 0x1A:DDR3_1866_10_10_10, 0x1B:DDR3_1866_11_11_11, 0x1C:DDR3_1866_12_12_12,
  0x1D:DDR3_1866_13_13_13, 0x1E:DDR3_2133_11_11_11, 0x1F:DDR3_2133_12_12_12, 0x20:DDR3_2133_13_13_13,
  0x21:DDR3_2133_14_14_14, 0x22:DDR4_1333_10_10_10, 0x23:DDR4_1600_10_10_10, 0x24:DDR4_1600_11_11_11,
  0x25:DDR4_1600_12_12_12, 0x26:DDR4_1866_12_12_12, 0x27:DDR4_1866_13_13_13, 0x28:DDR4_1866_14_14_14,
  0x29:DDR4_2133_14_14_14, 0x2A:DDR4_2133_15_15_15, 0x2B:DDR4_2133_16_16_16, 0x2C:DDR4_2400_15_15_15,
  0x2D:DDR4_2400_16_16_16, 0x2E:DDR4_2400_17_17_17, 0x2F:DDR4_2400_18_18_18
**/
  uint8_t                       Profile;

/** Offset 0x004F - MemoryDown
  Memory Down. 0x0(Default).
  0x0:No, 0x1:Yes, 0x2:1MD+SODIMM (for DDR3L only) ACRD, 0x3:1x32 LPDDR4
**/
  uint8_t                       MemoryDown;

/** Offset 0x0050 - DDR3LPageSize
  NOTE: Only for memory down or downgrade DDR3L frequency. 0x01:1KB(Default), 0x02:2KB.
  0x1:1KB, 0x2:2KB
**/
  uint8_t                       DDR3LPageSize;

/** Offset 0x0051 - DDR3LASR
  NOTE: Only for memory down. 0x00:Not Supported(Default), 0x01:Supported.
  0x0:Not Supported, 0x1:Supported
**/
  uint8_t                       DDR3LASR;

/** Offset 0x0052 - ScramblerSupport
  Scrambler Support. 0x00:Not Supported, 0x01:Supported(Default).
  $EN_DIS
**/
  uint8_t                       ScramblerSupport;

/** Offset 0x0053 - ChannelHashMask
  Channel Hash Mask. 0x00(Default).
**/
  uint16_t                      ChannelHashMask;

/** Offset 0x0055 - SliceHashMask
  Slice Hash Mask. 0x00(Default).
**/
  uint16_t                      SliceHashMask;

/** Offset 0x0057 - InterleavedMode
  Interleaved Mode. 0x00:Disable(Default), 0x02:Enable.
  0x0:Disable, 0x2:Enable
**/
  uint8_t                       InterleavedMode;

/** Offset 0x0058 - ChannelsSlicesEnable
  Channels Slices Enable. 0x00:Disable(Default), 0x01:Enable.
  $EN_DIS
**/
  uint8_t                       ChannelsSlicesEnable;

/** Offset 0x0059 - MinRefRate2xEnable
  Provided as a means to defend against Row-Hammer attacks. 0x00:Disable(Default),
  0x01:Enable.
  $EN_DIS
**/
  uint8_t                       MinRefRate2xEnable;

/** Offset 0x005A - DualRankSupportEnable
  Dual Rank Support Enable. 0x00:Disable, 0x01:Enable(Default).
  $EN_DIS
**/
  uint8_t                       DualRankSupportEnable;

/** Offset 0x005B - RmtMode
  Rank Margin Tool Mode. 0x00(Default).
  $EN_DIS
**/
  uint8_t                       RmtMode;

/** Offset 0x005C - MemorySizeLimit
  Memory Size Limit: This value is used to restrict the total amount of memory and
  the calculations based on it. Value is in MB. Example encodings are: 0x400 = 1GB,
  0x800 = 2GB, 0x1000 = 4GB, 0x2000 8GB. 0x0000(Default)
**/
  uint16_t                      MemorySizeLimit;

/** Offset 0x005E - LowMemoryMaxValue
  Low Memory Max Value: This value is used to restrict the amount of memory below
  4GB and the calculations based on it. Value is in MB.Example encodings are: 0x400
  = 1GB, 0x800 = 2GB, 0x1000 = 4GB, 0x2000 8GB. 0x0000(Default).
**/
  uint16_t                      LowMemoryMaxValue;

/** Offset 0x0060 - DisableFastBoot
  00:Disabled Used saved training data (if valid)(Default), 01:Enabled; Full re-train
  of memory.
  $EN_DIS
**/
  uint8_t                       DisableFastBoot;

/** Offset 0x0061 - HighMemoryMaxValue
  High Memory Max Value: This value is used to restrict the amount of memory above
  4GB and the calculations based on it. Value is in MB. Example encodings are: 0x0400:1GB,
  0x0800:2GB, 0x1000:4GB, 0x2000:8GB. 0x00(Default).
**/
  uint16_t                      HighMemoryMaxValue;

/** Offset 0x0063 - DIMM0SPDAddress
  DIMM0 SPD Address (NOTE: Only for DDR3L only. Please put 0 for MemoryDown. 0xA0(Default).
**/
  uint8_t                       DIMM0SPDAddress;

/** Offset 0x0064 - DIMM1SPDAddress
  DIMM1 SPD Address (NOTE: Only for DDR3L only. Please put 0 for MemoryDown. 0xA4(Default).
**/
  uint8_t                       DIMM1SPDAddress;

/** Offset 0x0065 - Ch0_RankEnable
  NOTE: Only for memory down. Set to 1 to enable Ch0 rank. 0x00(Default).
**/
  uint8_t                       Ch0_RankEnable;

/** Offset 0x0066 - Ch0_DeviceWidth
  NOTE: Only for memory down. DRAM Device Data Width populated on Ranks 0 and 1. 0x00(Default).
  0b0000:x8, 0b0001:x16, 0b0010:x32, 0b0011:x64
**/
  uint8_t                       Ch0_DeviceWidth;

/** Offset 0x0067 - Ch0_DramDensity
  NOTE: Only for memory down. DRAM Device Density populated on Ranks 0 and 1. 0x00(Default).
  0b0000:4Gb, 0b0001:6Gb, 0b0010:8Gb, 0b0011:12Gb, 0b0100:16Gb
**/
  uint8_t                       Ch0_DramDensity;

/** Offset 0x0068 - Ch0_Option
  Rank Select Interleaving Enable.  See Address Mapping section for full description.
  0:Rank Select Interleaving disabled, 1:Rank Select Interleaving enabled. [1] Bank
  Address Hashing Enable.  See Address Mapping section for full description. 0:Bank
  Address Hashing disabled, 1:Bank Address Hashing enabled. [3:2] Reserved. [5:4]
  This register specifies the address mapping to be used: 00:1KB (A), 01:2KB (B).
  0x03(Default).
**/
  uint8_t                       Ch0_Option;

/** Offset 0x0069 - Ch0_OdtConfig
  ODT configuration control. 0:WEAK_ODT_CONFIG(Default), 1:STRONG_ODT_CONFIG.
**/
  uint8_t                       Ch0_OdtConfig;

/** Offset 0x006A - Ch0_TristateClk1
  Parameter used to determine whether to tristate CLK1. 0x00(Default).
**/
  uint8_t                       Ch0_TristateClk1;

/** Offset 0x006B - Ch0_Mode2N
  2N Mode. 0x00(Default).
**/
  uint8_t                       Ch0_Mode2N;

/** Offset 0x006C - Ch0_OdtLevels
  Rank Select Interleaving Enable.  See Address Mapping section for full description.
  0:Rank Select Interleaving disabled(Default), 1:Rank Select Interleaving enabled.
  [1] Bank Address Hashing Enable.  See Address Mapping section for full description.
  0:Bank Address Hashing disabled, 1:Bank Address Hashing enabled. [3:2] Reserved.
  [5:4] This register specifies the address mapping to be used:00:1KB (A), 01:2KB (B).
**/
  uint8_t                       Ch0_OdtLevels;

/** Offset 0x006D - Ch1_RankEnable
  NOTE: Only for memory down. Set to 1 to enable Ch1 rank.
**/
  uint8_t                       Ch1_RankEnable;

/** Offset 0x006E - Ch1_DeviceWidth
  NOTE: Only for memory down. DRAM Device Data Width populated on Ranks 0 and 1. 0x00(Default).
  0b0000:x8, 0b0001:x16, 0b0010:x32, 0b0011:x64
**/
  uint8_t                       Ch1_DeviceWidth;

/** Offset 0x006F - Ch1_DramDensity
  NOTE: Only for memory down. DRAM Device Density populated on Ranks 0 and 1. 0x00:4Gb(Default).
  0b0000:4Gb, 0b0001:6Gb, 0b0010:8Gb, 0b0011:12Gb, 0b0100:16Gb
**/
  uint8_t                       Ch1_DramDensity;

/** Offset 0x0070 - Ch1_Option
  Rank Select Interleaving Enable.  See Address Mapping section for full description.
  0 - Rank Select Interleaving disabled. 1 - Rank Select Interleaving enabled. [1]
  Bank Address Hashing Enable.  See Address Mapping section for full description.
  0 - Bank Address Hashing disabled. 1 - Bank Address Hashing enabled. [3:2] Reserved.
  [5:4] This register specifies the address mapping to be used: 00:1KB (A), 01:2KB
  (B), 0x03(Default).
**/
  uint8_t                       Ch1_Option;

/** Offset 0x0071 - Ch1_OdtConfig
  ODT configuration control. 0:WEAK_ODT_CONFIG(Default), 1:STRONG_ODT_CONFIG.
**/
  uint8_t                       Ch1_OdtConfig;

/** Offset 0x0072 - Ch1_TristateClk1
  Parameter used to determine whether to tristate CLK1. 0x00(Default).
**/
  uint8_t                       Ch1_TristateClk1;

/** Offset 0x0073 - Ch1_Mode2N
  2N Mode. 0x00(Default).
**/
  uint8_t                       Ch1_Mode2N;

/** Offset 0x0074 - Ch1_OdtLevels
  Parameter used to determine if ODT will be held high or low. 0:Use MRC default(Default),
  1:ODT_AB_HIGH_HIGH. 3:ODT_AB_HIGH_LOW.
**/
  uint8_t                       Ch1_OdtLevels;

/** Offset 0x0075 - Ch2_RankEnable
  NOTE: Only for memory down. Set to 1 to enable Ch2 rank.
**/
  uint8_t                       Ch2_RankEnable;

/** Offset 0x0076 - Ch2_DeviceWidth
  NOTE: Only for memory down. DRAM Device Data Width populated on Ranks 0 and 1.
  0b0000:x8, 0b0001:x16, 0b0010:x32, 0b0011:x64
**/
  uint8_t                       Ch2_DeviceWidth;

/** Offset 0x0077 - Ch2_DramDensity
  NOTE: Only for memory down. DRAM Device Density populated on Ranks 0 and 1. 0x00(Default).
  0b0000:4Gb, 0b0001:6Gb, 0b0010:8Gb, 0b0011:12Gb, 0b0100:16Gb
**/
  uint8_t                       Ch2_DramDensity;

/** Offset 0x0078 - Ch2_Option
  Rank Select Interleaving Enable.  See Address Mapping section for full description..
  0 - Rank Select Interleaving disabled. 1 - Rank Select Interleaving enabled. [1]
  Bank Address Hashing Enable.  See Address Mapping section for full description..
  0 - Bank Address Hashing disabled. 1 - Bank Address Hashing enabled. [3:2] Reserved.
  [5:4] This register specifies the address mapping to be used:. 00:1KB (A)(Default).
  01:2KB (B).
**/
  uint8_t                       Ch2_Option;

/** Offset 0x0079 - Ch2_OdtConfig
  ODT configuration control. 0:WEAK_ODT_CONFIG(Default), 1:STRONG_ODT_CONFIG.
**/
  uint8_t                       Ch2_OdtConfig;

/** Offset 0x007A - Ch2_TristateClk1
  Parameter used to determine whether to tristate CLK1. 0x00(Default).
**/
  uint8_t                       Ch2_TristateClk1;

/** Offset 0x007B - Ch2_Mode2N
  2N Mode. 0x00(Default).
**/
  uint8_t                       Ch2_Mode2N;

/** Offset 0x007C - Ch2_OdtLevels
  Parameter used to determine if ODT will be held high or low. 0:Use MRC default(Default),
  1:ODT_AB_HIGH_HIGH, 3:ODT_AB_HIGH_LOW.
**/
  uint8_t                       Ch2_OdtLevels;

/** Offset 0x007D - Ch3_RankEnable
  NOTE: Only for memory down. Set to 1 to enable Ch3 rank. 0x00(Default).
**/
  uint8_t                       Ch3_RankEnable;

/** Offset 0x007E - Ch3_DeviceWidth
  NOTE: Only for memory down. DRAM Device Data Width populated on Ranks 0 and 1. 0x00:x8(Default),
  0x01:x16, 0x02:x32, 0x03:x64.
  0b0000:x8, 0b0001:x16, 0b0010:x32, 0b0011:x64
**/
  uint8_t                       Ch3_DeviceWidth;

/** Offset 0x007F - Ch3_DramDensity
  NOTE: Only for memory down. DRAM Device Density populated on Ranks 0 and 1. 0x00:4Gb(Default),
  0x01:6Gb, 0x02:8Gb, 0x03:12Gb, 0x04:16Gb.
  0b0000:4Gb, 0b0001:6Gb, 0b0010:8Gb, 0b0011:12Gb, 0b0100:16Gb
**/
  uint8_t                       Ch3_DramDensity;

/** Offset 0x0080 - Ch3_Option
  Rank Select Interleaving Enable.  See Address Mapping section for full description..
  0 - Rank Select Interleaving disabled. 1 - Rank Select Interleaving enabled. [1]
  Bank Address Hashing Enable.  See Address Mapping section for full description..
  0 - Bank Address Hashing disabled. 1 - Bank Address Hashing enabled. [3:2] Reserved.
  [5:4] This register specifies the address mapping to be used:. 00 - 1KB (A). 01
  - 2KB (B).
**/
  uint8_t                       Ch3_Option;

/** Offset 0x0081 - Ch3_OdtConfig
  ODT configuration control.. 0:WEAK_ODT_CONFIG(Default). 1:STRONG_ODT_CONFIG.
**/
  uint8_t                       Ch3_OdtConfig;

/** Offset 0x0082 - Ch3_TristateClk1
  Parameter used to determine whether to tristate CLK1. 0x00(Default).
**/
  uint8_t                       Ch3_TristateClk1;

/** Offset 0x0083 - Ch3_Mode2N
  2N Mode. 0x00(Default).
**/
  uint8_t                       Ch3_Mode2N;

/** Offset 0x0084 - Ch3_OdtLevels
  Parameter used to determine if ODT will be held high or low. 0:Use MRC default(Default),
  1:ODT_AB_HIGH_HIGH, 3:ODT_AB_HIGH_LOW.
**/
  uint8_t                       Ch3_OdtLevels;

/** Offset 0x0085 - RmtCheckRun
  RmtCheckRun: 0x00(Default).
**/
  uint8_t                       RmtCheckRun;

/** Offset 0x0086 - Ch0_Bit_swizzling
  Channel 0 PHY to DUnit DQ mapping (only used if not 1-1 mapping)Range: 0-32.
**/
  uint8_t                       Ch0_Bit_swizzling[32];

/** Offset 0x00A6 - Ch1_Bit_swizzling
  Channel 1 PHY to DUnit DQ mapping (only used if not 1-1 mapping)Range: 0-32.
**/
  uint8_t                       Ch1_Bit_swizzling[32];

/** Offset 0x00C6 - Ch2_Bit_swizzling
  Channel 2 PHY to DUnit DQ mapping (only used if not 1-1 mapping)Range: 0-32.
**/
  uint8_t                       Ch2_Bit_swizzling[32];

/** Offset 0x00E6 - Ch3_Bit_swizzling
  Channel 3 PHY to DUnit DQ mapping (only used if not 1-1 mapping)Range: 0-32.
**/
  uint8_t                       Ch3_Bit_swizzling[32];

/** Offset 0x0106 - RmtMarginCheckScaleHighThreshold
  RmtMarginCheckScaleHighThreshold. 0x0000(Default).
**/
  uint16_t                      RmtMarginCheckScaleHighThreshold;

/** Offset 0x0108 - MsgLevelMask
  MsgLevelMask. 0x00000000(Default).
**/
  uint32_t                      MsgLevelMask;

/** Offset 0x010C
**/
  uint32_t                      UnusedUpdSpace0;

/** Offset 0x0110 - PreMem GPIO Table Entry Number. Currently maximum entry number is 4
  Number of Entries in PreMem GPIO Table. 0(Default).
**/
  uint8_t                       PreMemGpioTableEntryNum;

/** Offset 0x0111 - PreMem GPIO Pin Number for each table
  Number of Pins in each PreMem GPIO Table. 0(Default).
**/
  uint8_t                       PreMemGpioTablePinNum[4];

/** Offset 0x0115 - PreMem GPIO Table Pointer
  Pointer to Array of pointers to PreMem GPIO Table. 0x00000000(Default).
**/
  uint32_t                      PreMemGpioTablePtr;

/** Offset 0x0119 - Enhance the port 8xh decoding
  Enable/Disable Enhance the port 8xh decoding. 0:Disable, 1:Enable(Default).
  $EN_DIS
**/
  uint8_t                       EnhancePort8xhDecoding;

/** Offset 0x011A - OEM File Loading Address
  Determine the memory base address to load a specified file from CSE file system
  after memory is available.
**/
  uint32_t                      OemLoadingBase;

/** Offset 0x011E - OEM File Name to Load
  Specify a file name to load from CSE file system after memory is available. Empty
  indicates no file needs to be loaded.
**/
  uint8_t                       OemFileName[16];

/** Offset 0x012E - SPD Data Write
  Enable/Disable SPD data write on the SMBUS. 0x00:Disable(Default), 0x01:Enable.
  $EN_DIS
**/
  uint8_t                       SpdWriteEnable;

/** Offset 0x012F - MRC Training Data Saving
  Enable/Disable MRC training data saving in FSP. 0x00:Disable(Default), 0x01:Enable.
  $EN_DIS
**/
  uint8_t                       MrcDataSaving;

/** Offset 0x0130 - eMMC Trace Length
  Select eMMC trace length to load OEM file from when loading OEM file name is specified.
  0x0:Long(Default), 0x1:Short.
  0x0:Long, 0x1:Short
**/
  uint8_t                       eMMCTraceLen;

/** Offset 0x0131
**/
  void*                       MrcBootDataPtr;

/** Offset 0x0135 - Skip CSE RBP to support zero sized IBB
  Enable/Disable skip CSE RBP for bootloader which loads IBB without assistance of
  CSE. 0x00:Disable(Default), 0x01:Enable.
  $EN_DIS
**/
  uint8_t                       SkipCseRbp;

/** Offset 0x0136 - Npk Enable
  Enable/Disable Npk. 0:Disable, 1:Enable, 2:Debugger, 3:Auto(Default).
  0:Disable, 1:Enable, 2:Debugger, 3:Auto
**/
  uint8_t                       NpkEn;

/** Offset 0x0137 - FW Trace Enable
  Enable/Disable FW Trace. 0:Disable, 1:Enable(Default).
  $EN_DIS
**/
  uint8_t                       FwTraceEn;

/** Offset 0x0138 - FW Trace Destination
  FW Trace Destination. 1-NPK_TRACE_TO_MEMORY, 2-NPK_TRACE_TO_DCI, 3-NPK_TRACE_TO_BSSB,
  4-NPK_TRACE_TO_PTI(Default).
**/
  uint8_t                       FwTraceDestination;

/** Offset 0x0139 - NPK Recovery Dump
  Enable/Disable NPK Recovery Dump. 0:Disable(Default), 1:Enable.
  $EN_DIS
**/
  uint8_t                       RecoverDump;

/** Offset 0x013A - Memory Region 0 Buffer WrapAround
  Memory Region 0 Buffer WrapAround. 0-n0-wrap, 1-warp(Default).
**/
  uint8_t                       Msc0Wrap;

/** Offset 0x013B - Memory Region 1 Buffer WrapAround
  Memory Region 1 Buffer WrapAround. 0-n0-warp, 1-warp(Default).
**/
  uint8_t                       Msc1Wrap;

/** Offset 0x013C - Memory Region 0 Buffer Size
  Memory Region 0 Buffer Size. 0-0MB(Default), 1-1MB, 2-8MB, 3-64MB, 4-128MB, 5-256MB,
  6-512MB, 7-1GB.
**/
  uint32_t                      Msc0Size;

/** Offset 0x0140 - Memory Region 1 Buffer Size
  Memory Region 1 Buffer Size, 0-0MB(Default), 1-1MB, 2-8MB, 3-64MB, 4-128MB, 5-256MB,
  6-512MB, 7-1GB.
**/
  uint32_t                      Msc1Size;

/** Offset 0x0144 - PTI Mode
  PTI Mode. 0-0ff, 1-x4(Default), 2-x8, 3-x12, 4-x16.
**/
  uint8_t                       PtiMode;

/** Offset 0x0145 - PTI Training
  PTI Training. 0-off(Default), 1-6=1-6.
**/
  uint8_t                       PtiTraining;

/** Offset 0x0146 - PTI Speed
  PTI Speed. 0-full, 1-half, 2-quarter(Default).
**/
  uint8_t                       PtiSpeed;

/** Offset 0x0147 - Punit Message Level
  Punit Message Output Verbosity Level. 0, 1(Default), 2-4=2-4.
**/
  uint8_t                       PunitMlvl;

/** Offset 0x0148 - PMC Message Level
  PMC Message Output Verbosity Level. 0, 1(Default), 2-4=2-4.
**/
  uint8_t                       PmcMlvl;

/** Offset 0x0149 - SW Trace Enable
  Enable/Disable SW Trace. 0:Disable(Default), 1:Enable.
  $EN_DIS
**/
  uint8_t                       SwTraceEn;

/** Offset 0x014A - Periodic Retraining Disable
  Option to disable LPDDR4 Periodic Retraining. 0x00:Disable(Default), 0x01:Enable.
  $EN_DIS
**/
  uint8_t                       PeriodicRetrainingDisable;

/** Offset 0x014B
**/
  uint8_t                       ReservedFspmUpd[5];
} __attribute__((packed));

/** Fsp M Test Configuration
**/
struct FSP_M_TEST_CONFIG {

/** Offset 0x0150
**/
  uint32_t                      Signature;

/** Offset 0x0154
**/
  uint8_t                       ReservedFspmTestUpd[28];
} __attribute__((packed));

/** Fsp M Restricted Configuration
**/
struct FSP_M_RESTRICTED_CONFIG {

/** Offset 0x0170
**/
  uint32_t                      Signature;

/** Offset 0x0174
**/
  uint8_t                       ReservedFspmRestrictedUpd[138];
} __attribute__((packed));

/** Fsp M UPD Configuration
**/
struct FSPM_UPD {

/** Offset 0x0000
**/
  struct FSP_UPD_HEADER              FspUpdHeader;

/** Offset 0x0020
**/
  struct FSPM_ARCH_UPD               FspmArchUpd;

/** Offset 0x0040
**/
  struct FSP_M_CONFIG                FspmConfig;

/** Offset 0x0150
**/
  struct FSP_M_TEST_CONFIG           FspmTestConfig;

/** Offset 0x0170
**/
  struct FSP_M_RESTRICTED_CONFIG     FspmRestrictedConfig;

/** Offset 0x01FE
**/
  uint16_t                      UpdTerminator;
} __attribute__((packed));

#endif
