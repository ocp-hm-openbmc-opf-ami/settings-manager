/*
// Copyright (c) 2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once
#include "interface.hpp"

using Association = std::tuple<std::string, std::string, std::string>;

// this file is vendor specific, other vendors should replace this file using a
// bbappend

inline void loadSettings(sdbusplus::asio::object_server &objectServer,
                         std::vector<SettingsInterface> &settings)
{

    SettingsInterface *setting = nullptr;
    setting = &settings.emplace_back(
        objectServer,
        "/xyz/openbmc_project/control/minimum_ship_level_required",
        "xyz.openbmc_project.Control.MinimumShipLevel");

    setting->addProperty("MinimumShipLevelRequired", true);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/auto_reboot",
        "xyz.openbmc_project.Control.Boot.RebootPolicy");

    setting->addProperty("AutoReboot", false);

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/control/host0/boot",
                                     "xyz.openbmc_project.Control.Boot.Source");

    setting->addProperty(
        "BootSource",
        "xyz.openbmc_project.Control.Boot.Source.Sources.Default");

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/control/host0/boot",
                                     "xyz.openbmc_project.Control.Boot.Mode");

    setting->addProperty("BootMode",
                         "xyz.openbmc_project.Control.Boot.Mode.Modes.Regular");

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/control/host0/boot",
                                     "xyz.openbmc_project.Control.Boot.Type");

    setting->addProperty("BootType",
                         "xyz.openbmc_project.Control.Boot.Type.Types.EFI");

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/control/host0/boot",
                                     "xyz.openbmc_project.Object.Enable");

    setting->addProperty("Enabled", false);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/boot/one_time",
        "xyz.openbmc_project.Object.Enable");

    setting->addProperty("Enabled", false);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/power_cap",
        "xyz.openbmc_project.Control.Power.Cap");

    setting->addProperty("PowerCap", static_cast<uint32_t>(0));
    setting->addProperty("PowerCapEnable", false);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/power_restore_policy",
        "xyz.openbmc_project.Control.Power.RestorePolicy");

    setting->addProperty(
        "PowerRestorePolicy",
        "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.AlwaysOff");

    setting->addProperty("PowerRestoreDelay", static_cast<uint64_t>(0));

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/acpi_power_state",
        "xyz.openbmc_project.Control.Power.ACPIPowerState");

    setting->addProperty(
        "SysACPIStatus",
        "xyz.openbmc_project.Control.Power.ACPIPowerState.ACPI.Unknown");
    setting->addProperty(
        "DevACPIStatus",
        "xyz.openbmc_project.Control.Power.ACPIPowerState.ACPI.Unknown");

    setting =
        &settings.emplace_back(objectServer, "/xyz/openbmc_project/time/owner",
                               "xyz.openbmc_project.Time.Owner");

    setting->addProperty("TimeOwner",
                         "xyz.openbmc_project.Time.Owner.Owners.BMC");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/time/sync_method",
        "xyz.openbmc_project.Time.Synchronization");

    setting->addProperty("TimeSyncMethod",
                         "xyz.openbmc_project.Time.Synchronization.Method.NTP");

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/network/host0/intf",
                                     "xyz.openbmc_project.Network.MACAddress");

    setting->addProperty("MACAddress", "00:00:00:00:00:00");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/network/host0/intf/addr",
        "xyz.openbmc_project.Network.IP");

    setting->addProperty("Address", "0.0.0.0");
    setting->addProperty("PrefixLength", static_cast<uint8_t>(0));
    setting->addProperty("Origin",
                         "xyz.openbmc_project.Network.IP.AddressOrigin.Static");
    setting->addProperty("Gateway", "0.0.0.0");
    setting->addProperty("Type",
                         "xyz.openbmc_project.Network.IP.Protocol.IPv4");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/TPMEnable",
        "xyz.openbmc_project.Control.TPM.Policy");

    setting->addProperty("TPMEnable", false);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/power_supply_redundancy",
        "xyz.openbmc_project.Control.PowerSupplyRedundancy");

    setting->addProperty("PowerSupplyRedundancyEnabled", false);
    setting->addProperty(
        "ColdRedundancyStatus",
        "xyz.openbmc_project.Control.PowerSupplyRedundancy.Status.completed");
    setting->addProperty("RotationEnabled", true);
    setting->addProperty(
        "RotationAlgorithm",
        "xyz.openbmc_project.Control.PowerSupplyRedundancy.Algo.bmcSpecific");
    setting->addProperty("RotationRankOrder", std::vector<uint8_t>{1, 2, 3, 4});
    setting->addProperty("PeriodOfRotation", static_cast<uint32_t>(86400));

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/turbo_allowed",
        "xyz.openbmc_project.Control.Host.TurboAllowed");

    setting->addProperty("TurboAllowed", true);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/systemGUID",
        "xyz.openbmc_project.Common.UUID");

    setting->addProperty("UUID", "00000000-0000-0000-0000-000000000000");

    setting = &settings.emplace_back(
        objectServer, "/com/intel/cooling/mode",
        "com.intel.Cooling.Mode");

    setting->addProperty("Mode", "Air Cooling Mode");

    setting = &settings.emplace_back(
        objectServer, "/com/intel/control/vr_Access",
        "com.intel.Control.vrAccess");

    setting->addProperty("Mode", "Normal");
    setting->addProperty("IsolationInitialState", "Inactive");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/software/bios_active",
        "xyz.openbmc_project.Software.Version");
    setting->addProperty("Version", "NA");
    setting->addProperty(
        "Purpose", "xyz.openbmc_project.Software.Version.VersionPurpose.Host");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/software/bios_active",
        "xyz.openbmc_project.Software.Activation");
    setting->addProperty(
        "Activation",
        "xyz.openbmc_project.Software.Activation.Activations.Active");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/software/rot_fw_active",
        "xyz.openbmc_project.Software.Version");
    setting->addProperty("Version", "NA");
    setting->addProperty(
        "Purpose", "xyz.openbmc_project.Software.Version.VersionPurpose.Other");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/software/rot_fw_active",
        "xyz.openbmc_project.Software.Activation");
    setting->addProperty(
        "Activation",
        "xyz.openbmc_project.Software.Activation.Activations.Active");
    setting->addProperty(
        "RequestedActivation",
        "xyz.openbmc_project.Software.Activation.RequestedActivations.None");

    std::vector<Association> associations;
    associations.push_back(
        Association("functional", "software_version",
                    "/xyz/openbmc_project/software/bios_active"));
    associations.push_back(
        Association("functional", "software_version",
                    "/xyz/openbmc_project/software/rot_fw_active"));

    setting =
        &settings.emplace_back(objectServer, "/xyz/openbmc_project/software",
                               "xyz.openbmc_project.Association.Definitions");
    setting->interface->register_property("Associations", associations);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/processor_error_config",
        "xyz.openbmc_project.Control.Processor.ErrConfig");

    setting->addProperty("ResetOnIERR", false);
    setting->addProperty("AllowResetOnMCERR", true);
    setting->addProperty("ResetOnERR2", false);
    setting->addProperty("ErrorCountCPU1", static_cast<uint8_t>(0));
    setting->addProperty("ErrorCountCPU2", static_cast<uint8_t>(0));
    setting->addProperty("ErrorCountCPU3", static_cast<uint8_t>(0));
    setting->addProperty("ErrorCountCPU4", static_cast<uint8_t>(0));
    setting->addProperty("CrashdumpCount", static_cast<uint8_t>(0));

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/bmc_reset_disables",
        "xyz.openbmc_project.Control.ResetDisables");

    setting->addProperty("ResetOnSMI", false);

    setting = &settings.emplace_back(
        objectServer, "/com/intel/control/ocotshutdown_policy_config",
        "com.intel.Control.OCOTShutdownPolicy");

    setting->addProperty(
        "OCOTPolicy",
        "com.intel.Control.OCOTShutdownPolicy.Policy.NoShutdownOnOCOT");

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/Chassis/Control/NMISource",
        "xyz.openbmc_project.Chassis.Control.NMISource");

    setting->addProperty(
        "BMCSource",
        "xyz.openbmc_project.Chassis.Control.NMISource.BMCSourceSignal.None");

    setting->addProperty("Enabled", false);

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/state/chassis0",
                                     "xyz.openbmc_project.State.PowerOnHours");

    setting->addProperty("POHCounter", static_cast<uint32_t>(0));

    setting = &settings.emplace_back(
        objectServer,
        "/xyz/openbmc_project/control/chassis_capabilities_config",
        "xyz.openbmc_project.Control.ChassisCapabilities");

    setting->addProperty("CapabilitiesFlags", static_cast<uint8_t>(7));
    setting->addProperty("ChassisIntrusionEnabled", true);
    setting->addProperty("ChassisFrontPanelLockoutEnabled", true);
    setting->addProperty("ChassisNMIEnabled", true);
    setting->addProperty("ChassisPowerInterlockEnabled", false);
    setting->addProperty("FRUDeviceAddress", static_cast<uint8_t>(32));
    setting->addProperty("SDRDeviceAddress", static_cast<uint8_t>(32));
    setting->addProperty("SELDeviceAddress", static_cast<uint8_t>(32));
    setting->addProperty("SMDeviceAddress", static_cast<uint8_t>(32));
    setting->addProperty("BridgeDeviceAddress", static_cast<uint8_t>(32));

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/thermal_mode",
        "xyz.openbmc_project.Control.ThermalMode");

    setting->addProperty("Current", "Performance");
    setting->addProperty("Supported",
                         std::vector<std::string>{"Acoustic", "Performance"});

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/control/cfm_limit",
                                     "xyz.openbmc_project.Control.CFMLimit");

    setting->addProperty("Limit", static_cast<double>(0));

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/ipmi/sol/eth0",
                                     "xyz.openbmc_project.Ipmi.SOL");

    setting->addProperty("Progress", static_cast<uint8_t>(0), false);
    setting->addProperty("Enable", false);
    setting->addProperty("ForceEncryption", true);
    setting->addProperty("ForceAuthentication", true);
    setting->addProperty("Privilege", static_cast<uint8_t>(4));
    setting->addProperty("AccumulateIntervalMS", static_cast<uint8_t>(100));
    setting->addProperty("Threshold", static_cast<uint8_t>(96));
    setting->addProperty("RetryCount", static_cast<uint8_t>(6));
    setting->addProperty("RetryIntervalMS", static_cast<uint8_t>(20));

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/ipmi/sol/eth1",
                                     "xyz.openbmc_project.Ipmi.SOL");

    setting->addProperty("Progress", static_cast<uint8_t>(0), false);
    setting->addProperty("Enable", false);
    setting->addProperty("ForceEncryption", true);
    setting->addProperty("ForceAuthentication", true);
    setting->addProperty("Privilege", static_cast<uint8_t>(4));
    setting->addProperty("AccumulateIntervalMS", static_cast<uint8_t>(100));
    setting->addProperty("Threshold", static_cast<uint8_t>(96));
    setting->addProperty("RetryCount", static_cast<uint8_t>(6));
    setting->addProperty("RetryIntervalMS", static_cast<uint8_t>(20));

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/ipmi/sol/eth2",
                                     "xyz.openbmc_project.Ipmi.SOL");

    setting->addProperty("Progress", static_cast<uint8_t>(0), false);
    setting->addProperty("Enable", false);
    setting->addProperty("ForceEncryption", true);
    setting->addProperty("ForceAuthentication", true);
    setting->addProperty("Privilege", static_cast<uint8_t>(4));
    setting->addProperty("AccumulateIntervalMS", static_cast<uint8_t>(100));
    setting->addProperty("Threshold", static_cast<uint8_t>(96));
    setting->addProperty("RetryCount", static_cast<uint8_t>(6));
    setting->addProperty("RetryIntervalMS", static_cast<uint8_t>(20));

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/control/host0/ac_boot",
        "xyz.openbmc_project.Common.ACBoot");

    setting->addProperty("ACBoot", "Unknown", false);

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/Inventory/Item/Dimm",
        "xyz.openbmc_project.Inventory.Item.Dimm.Offset");

    setting->addProperty("DimmOffset", std::vector<uint8_t>{});

    setting = &settings.emplace_back(
        objectServer, "/xyz/openbmc_project/logging/rest_api_logs",
        "xyz.openbmc_project.Object.Enable");

    setting->addProperty("Enabled", true);

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/software/apply_time",
                                     "xyz.openbmc_project.Software.ApplyTime");

    setting->addProperty(
        "RequestedApplyTime",
        "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes.Immediate");

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/logging/settings",
                                     "xyz.openbmc_project.Logging.Settings");

    setting->addProperty("QuiesceOnHwError", false);

    setting = &settings.emplace_back(objectServer,
                                     "/xyz/openbmc_project/pfr/last_events",
                                     "xyz.openbmc_project.PFR.LastEvents");

    setting->addProperty("lastRecoveryCount", static_cast<uint8_t>(0));
    setting->addProperty("lastPanicCount", static_cast<uint8_t>(0));
    setting->addProperty("lastMajorErr", static_cast<uint8_t>(0));
    setting->addProperty("lastMinorErr", static_cast<uint8_t>(0));

    for (SettingsInterface &s : settings)
    {
        s.initialize();
    }
}
