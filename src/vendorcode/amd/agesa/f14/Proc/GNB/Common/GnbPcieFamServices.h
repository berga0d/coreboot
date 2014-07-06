/* $NoKeywords:$ */
/**
 * @file
 *
 * PCIe family specific services.
 *
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:     AGESA
 * @e sub-project: GNB
 * @e \$Revision: 34897 $   @e \$Date: 2010-07-13 19:07:10 -0700 (Tue, 13 Jul 2010) $
 *
 */
/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */
#ifndef _GNBPCIEFAMSERVICES_H_
#define _GNBPCIEFAMSERVICES_H_


AGESA_STATUS
PcieFmGetComplexDataLength (
  IN       UINT32                        SocketId,
  OUT      UINTN                         *Length
  );

AGESA_STATUS
PcieFmBuildComplexConfiguration (
  OUT      VOID                          *Buffer,
  IN       AMD_CONFIG_PARAMS             *StdHeader
  );

AGESA_STATUS
PcieFmConfigureEnginesLaneAllocation (
  IN       PCIe_WRAPPER_CONFIG           *Wrapper,
  IN       PCIE_ENGINE_TYPE              EngineType,
  IN       UINT8                         ConfigurationId
  );

AGESA_STATUS
PcieFmGetCoreConfigurationValue (
  IN       PCIe_WRAPPER_CONFIG          *Wrapper,
  IN       UINT8                        CoreId,
  IN       UINT64                       ConfigurationSignature,
  IN       UINT8                        *ConfigurationValue
  );

BOOLEAN
PcieFmCheckPortPciDeviceMapping (
  IN      PCIe_PORT_DESCRIPTOR          *PortDescriptor,
  IN      PCIe_ENGINE_CONFIG            *Engine
  );

AGESA_STATUS
PcieFmMapPortPciAddress (
  IN      PCIe_ENGINE_CONFIG            *Engine,
  IN      PCIe_PLATFORM_CONFIG          *Pcie
  );

BOOLEAN
PcieFmCheckPortPcieLaneCanBeMuxed (
  IN      PCIe_PORT_DESCRIPTOR          *PortDescriptor,
  IN      PCIe_ENGINE_CONFIG            *Engine
  );

CONST CHAR8*
PcieFmDebugGetCoreConfigurationString (
  IN       PCIe_WRAPPER_CONFIG          *Wrapper,
  IN       UINT8                        ConfigurationValue
 );

CONST CHAR8*
PcieFmDebugGetWrapperNameString (
  IN       PCIe_WRAPPER_CONFIG          *Wrapper
 );

CONST CHAR8*
PcieFmDebugGetHostRegAddressSpaceString (
  IN      UINT16                        AddressFrame
  );

PCIE_LINK_SPEED_CAP
PcieFmGetLinkSpeedCap (
  IN       UINT32                       Flags,
  IN       PCIe_ENGINE_CONFIG           *Engine,
  IN       PCIe_PLATFORM_CONFIG          *Pcie
  );
#endif
